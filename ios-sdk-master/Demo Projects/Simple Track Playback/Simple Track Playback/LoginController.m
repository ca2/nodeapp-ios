/*
 Copyright 2015 Spotify AB

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#import "LoginController.h"
#import <SpotifyAuthentication/SpotifyAuthentication.h>
#import <SpotifyMetadata/SpotifyMetadata.h>
#import <SpotifyAudioPlayback/SpotifyAudioPlayback.h>
#import "Config.h"

#import <SafariServices/SafariServices.h>
#import <WebKit/WebKit.h>
#import "WebViewController.h"

@interface LoginController () <SFSafariViewControllerDelegate, WebViewControllerDelegate, SPTStoreControllerDelegate>

@property (atomic, readwrite) UIViewController *authViewController;
@property (atomic, readwrite) BOOL firstLoad;

@end

@implementation LoginController


#pragma mark - View Lifecycle

- (void)viewDidLoad
{
    [super viewDidLoad];

    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(sessionUpdatedNotification:) name:@"sessionUpdated" object:nil];
    self.statusLabel.text = @"";
    self.firstLoad = YES;
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];

    SPTAuth *auth = [SPTAuth defaultInstance];
    // Uncomment to turn off native/SSO/flip-flop login flow
    //auth.allowNativeLogin = NO;

    // Check if we have a token at all
    if (auth.session == nil) {
        self.statusLabel.text = @"";
        return;
    }

    // Check if it's still valid
    if ([auth.session isValid] && self.firstLoad) {
        // It's still valid, show the player.
        [self showPlayer];
        return;
    }

    // Oh noes, the token has expired, if we have a token refresh service set up, we'll call tat one.
    self.statusLabel.text = @"Token expired.";
    if (auth.hasTokenRefreshService) {
        [self renewTokenAndShowPlayer];
        return;
    }

    // Else, just show login dialog
}

- (BOOL)prefersStatusBarHidden
{
    return YES;
}

- (UIViewController *)authViewControllerWithURL:(NSURL *)url
{
    UIViewController *viewController;
    if ([SFSafariViewController class]) {
        SFSafariViewController *safari = [[SFSafariViewController alloc] initWithURL:url];
        safari.delegate = self;
        viewController = safari;
    } else {
        WebViewController *webView = [[WebViewController alloc] initWithURL:url];
        webView.delegate = self;
        viewController = [[UINavigationController alloc] initWithRootViewController:webView];
    }
    viewController.modalPresentationStyle = UIModalPresentationPageSheet;
    return viewController;
}

- (void)sessionUpdatedNotification:(NSNotification *)notification
{
    self.statusLabel.text = @"";

    SPTAuth *auth = [SPTAuth defaultInstance];
    [self.presentedViewController dismissViewControllerAnimated:YES completion:nil];
    
    
    if (auth.session && [auth.session isValid]) {
        self.statusLabel.text = @"";
        [self showPlayer];
    } else {
        self.statusLabel.text = @"Login failed.";
        NSLog(@"*** Failed to log in");
    }
}

- (void)showPlayer
{
    self.firstLoad = NO;
    self.statusLabel.text = @"Logged in.";
    [self performSegueWithIdentifier:@"ShowPlayer" sender:nil];
}

#pragma mark - SPTStoreControllerDelegate

- (void)productViewControllerDidFinish:(SPTStoreViewController *)viewController
{
    self.statusLabel.text = @"App Store Dismissed.";
    [viewController dismissViewControllerAnimated:YES completion:nil];
}

- (void)openLoginPage
{
    self.statusLabel.text = @"Logging in...";
    SPTAuth *auth = [SPTAuth defaultInstance];
    
    if ([SPTAuth supportsApplicationAuthentication]) {
        [[UIApplication sharedApplication] openURL:[auth spotifyAppAuthenticationURL]];
    } else {
        self.authViewController = [self authViewControllerWithURL:[[SPTAuth defaultInstance] spotifyWebAuthenticationURL]];
        self.definesPresentationContext = YES;
        [self presentViewController:self.authViewController animated:YES completion:nil];
    }
}

- (void)renewTokenAndShowPlayer
{
    self.statusLabel.text = @"Refreshing token...";
    SPTAuth *auth = [SPTAuth defaultInstance];

    [auth renewSession:auth.session callback:^(NSError *error, SPTSession *session) {
        auth.session = session;

        if (error) {
            self.statusLabel.text = @"Refreshing token failed.";
            NSLog(@"*** Error renewing session: %@", error);
            return;
        }

        [self showPlayer];
    }];
}

#pragma mark WebViewControllerDelegate

- (void)webViewControllerDidFinish:(WebViewController *)controller
{
    // User tapped the close button. Treat as auth error
}

#pragma mark SFSafariViewControllerDelegate

- (void)safariViewControllerDidFinish:(SFSafariViewController *)controller
{
    // User tapped the close button. Treat as auth error
}

#pragma mark - IBActions

- (IBAction)loginClicked:(id)sender
{
    [self openLoginPage];
}

- (IBAction)showSpotifyAppStoreClicked:(id)sender
{
    self.statusLabel.text = @"Presenting App Store...";
    SPTStoreViewController *storeVC = [[SPTStoreViewController alloc] initWithCampaignToken:@"your_campaign_token"
                                                                              storeDelegate:self];
    [self presentViewController:storeVC animated:YES completion:nil];
}

- (IBAction)clearCookiesClicked:(id)sender
{
    NSHTTPCookieStorage *storage = [NSHTTPCookieStorage sharedHTTPCookieStorage];
    for (NSHTTPCookie *cookie in [storage cookies]) {
        if ([cookie.domain rangeOfString:@"spotify."].length > 0 ||
            [cookie.domain rangeOfString:@"facebook."].length > 0) {
            [storage deleteCookie:cookie];
        }
    }
    [[NSUserDefaults standardUserDefaults] synchronize];
    self.statusLabel.text = @"Cookies cleared.";
}

@end
