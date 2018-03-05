//
//  AuthViewController.m
//  Simple Track Playback
//
//  Created by Patrik Sjöberg on 2016-10-13.
//  Copyright © 2016 Your Company. All rights reserved.
//

#import "WebViewController.h"
#import <WebKit/WebKit.h>

@interface WebViewController () <UIWebViewDelegate>
@property (nonatomic, strong) UIWebView *webView;

@property (nonatomic, copy) NSURL *initialURL;

@property (nonatomic, assign) BOOL loadComplete;
@end

@implementation WebViewController

- (instancetype)initWithURL:(NSURL *)URL
{
    self = [super init];
    if (self) {
        _initialURL = [URL copy];
    }
    return self;

}

- (void)viewDidLoad
{
    [super viewDidLoad];

    NSURLRequest *initialRequest = [NSURLRequest requestWithURL:self.initialURL];
    self.webView = [[UIWebView alloc] initWithFrame:self.view.bounds];
    self.webView.delegate = self;
    self.webView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    [self.view addSubview:self.webView];
    
    self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemDone
                                                                                          target:self
                                                                                          action:@selector(done)];
    
    [self.webView loadRequest:initialRequest];
}

- (void)done
{
    if ([self.delegate respondsToSelector:@selector(webViewControllerDidFinish:)]) {
        [self.delegate webViewControllerDidFinish:self];
    }
    [self.presentingViewController dismissViewControllerAnimated:YES completion:nil];
}

#pragma mark UIWebViewDelegate

- (void)webViewDidFinishLoad:(UIWebView *)webView
{
    if (!self.loadComplete) {
        if ([self.delegate respondsToSelector:@selector(webViewController:didCompleteInitialLoad:)]) {
            [self.delegate webViewController:self didCompleteInitialLoad:YES];
        }
        self.loadComplete = YES;
    }
}

- (void)webView:(UIWebView *)webView didFailLoadWithError:(NSError *)error
{
    if (!self.loadComplete) {
        if ([self.delegate respondsToSelector:@selector(webViewController:didCompleteInitialLoad:)]) {
            [self.delegate webViewController:self didCompleteInitialLoad:NO];
        }
        self.loadComplete = YES;
    }
}

@end
