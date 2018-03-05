Spotify iOS SDK Beta 25
=======================

**Authentication changes**

We have simplified the authentication flow a bit. 

`-[SPTAuth loginURL]` returned URLs with different schemas depending on a number of parameters. This method has been replaced by two methods

- `-[SPTAuth spotifyWebAuthenticationURL]` returns a https://accounts.spotify.com URL that you should open in a Safari View Controller (or UIWebView if supporting iOS versions prior to 9)
- `-[SPTAuth spotifyAppAuthenticationURL]` will always return a spotify-action:// URI that you should open with `-[UIApplication openURL:]` if `+[SPTAuth supportsApplicationAuthentication]` returns YES, in order to perform SSO authentication against the Spotify application.

**API Changes**

* Auth: Removed BOOL SPTAuthViewController.hideSignup. It was not actually used.
* Auth: Deprecated `SPTAuthViewController`. Please use SFSafariViewController

**Bugs fixed**

* [`SPTSearch performSearchWithQuery:` offset is broken](https://github.com/spotify/ios-sdk/issues/478)
* [`SPTSearch performSearchWithQuery:` crash](https://github.com/spotify/ios-sdk/issues/766)
* [Beta 24 emits a lot of warnings](https://github.com/spotify/ios-sdk/issues/782)
* [b24 frameworks do not support bitcode while b23 did](https://github.com/spotify/ios-sdk/issues/786)

Spotify iOS SDK Beta 24
=======================

SDK is now split into Authentication, Metadata and AudioPlayback frameworks independent from each other.

**API Changes**

All classes and methods have been moved into appropriate frameworks.

**Bugs fixed**

* Fixed library hanging on 32 bit systems. (#772, #777)
* `SPTPartialPlaylist` now correctly parses name and uri as nil when the object is `NSNull`
* [SPTPlaylistTrack decodedJSONObject is nil](https://github.com/spotify/ios-sdk/issues/396)
* [requestNewReleasesForCountry returns nil items](https://github.com/spotify/ios-sdk/issues/387])

**Improvements**

* Added the scopes SPTAuthPlaylistReadCollaborativeScope (user-top-read) and SPTAuthUserReadTopScope (playlist-read-collaborative).
* Added new `SPTStoreViewController` - Display an App Store page to promote the Spotify app. If you use it, link with the StoreKit framework.

Spotify iOS SDK Beta 23
=======================

**Bugs fixed**

* [Beta 22: `SPTPlaylistSnapshot +playlistsWithURIs...` is gone.](https://github.com/spotify/ios-sdk/issues/761)


Spotify iOS SDK Beta 22
=======================

In preparation for splitting our SDK into distinct components the focus of this release is to decouple future components.
SDK is now grouped into Authentication, Metadata and AudioPlayback functionality modules independent from each other. This functionality grouping is reflected in the "Spotify.h" header. SDK will be split into three libraries representing these functionality modules in an upcoming release.
Decoupling manifested in that all methods concerning Metadata that previously took a SPTSession object now instead take an `NSString *accessToken` argument which is a property of the `SPTSession` object.
E.g. `SPTArtist` method `requestTopTracksForTerritory:withSession:callback:` becomes `requestTopTracksForTerritory:withAccessToken:callback:`. If such a method was already present then the method referencing session was simply removed.

**Notes**

* SDK version added into SDK "Spotify.h" header.   

**Bugs fixed**

* [Beta 21 works perfect!](https://github.com/spotify/ios-sdk/issues/740) (but hopefully this version also works perfect...)
* [Beta 20: allowCaching and diskCache - may cause issue with subsequent track plays] (https://github.com/spotify/ios-sdk/issues/722)
* [Beta 21: Symbols 'symbolise' and 'symboliseError' are un-prefixed] (https://github.com/spotify/ios-sdk/issues/741)
* [SPTAudioStreamingController loginWithAccessToken results to "audioStreaming:didReceiveError:withName: unrecognized selector sent to instance"] (https://github.com/spotify/ios-sdk/issues/747)
* [Unable to set repeat status but SPTPlaybackState has an isRepeating property] (https://github.com/spotify/ios-sdk/issues/749)
* Improved performance mentioned in [Massive skipNext performance degradation in Beta 21] (https://github.com/spotify/ios-sdk/issues/746)
* Improved performance mentioned in [Seek 20-25x slower in Beta 21] (https://github.com/spotify/ios-sdk/issues/750)

**Additional APIs**

* `SPTAudioStreamingController` has exposed the following functionality:
  * exposed `-(void)setShuffle:(BOOL)enable callback:(SPTErrorableOperationCallback)block` to allow setting shuffle option.
  * exposed `-(void)setRepeat:(SPTRepeatMode)mode callback:(SPTErrorableOperationCallback)block` to allow setting repeat mode.

**API Changes**

* Removed all methods marked as deprecated in `SPTArtist` and `SPTRequest`. These methods have been previously moved to other interfaces, but not deleted at their original location.
* `SPTAudioStreamingController` has now the following functionality changes:
  * changed `-(void)audioStreaming:(SPTAudioStreamingController *)audioStreaming didReceiveError:(SpErrorCode)errorCode withName:(NSString*)name` to `- (void)audioStreaming:(SPTAudioStreamingController *)audioStreaming didReceiveError:(NSError *)error`. Latter method has one argument `NSError *error` instead of two arguments: `errorCode` and `errorName`.
  * Removed argument `name` from the method `- (void)audioStreaming:(SPTAudioStreamingController *)audioStreaming didReceivePlaybackEvent:(SpPlaybackEvent)event withName:(NSString *)name`. 
* `SPTDiskCaching` protocol has been updated and extended.
* Basic implementation of `SPTDiskCaching` protocol, interface `SPTDiskCache` has been refactored as well and works properly.

Spotify iOS SDK Beta 21
======================

**Notes**

Please check the demo app, there were a lot of changes.

**Bugs fixed**

* [seekToOffset 0 breaks music playback in beta20](https://github.com/spotify/ios-sdk/issues/725)
* [Track URIs being remapped in Beta20](https://github.com/spotify/ios-sdk/issues/724)
* [audioStreaming:didStartPlayingTrack: & didStopPlayingTrack: missing from beta 20](https://github.com/spotify/ios-sdk/issues/723)
* [Beta 20 and iOS 7 - login web view fails](https://github.com/spotify/ios-sdk/issues/721)
* [How to tell if a SPTrack has finished playing in beta 20](https://github.com/spotify/ios-sdk/issues/718)

**Additional APIs**

* SPTAudioStreamingPlaybackDelegate
  * `-(void)audioStreaming:(SPTAudioStreamingController *) didReceivePlaybackEvent:(SpPlaybackEvent) withName:(NSString*);` exposes 
  low-level events. See `SPTPlaybackEvent` for reference.
  * `-(void)audioStreaming:(SPTAudioStreamingController *) didReceiveError:(SpErrorCode) withName:(NSString*);` 
  exposes low-level errors. 
  * `-(void)audioStreaming:(SPTAudioStreamingController *) didChangePosition:(NSTimeInterval);` report current track position.
  * Property `SPTAudioStreamingController.metadata` provides the data on current/previous/next tracks
  * Property `SPTAudioStreamingController.playbackState` provides data on plaback state, playback mode, current position.
* `SPTMetadata` contains two new properties `playbackSourceUri` and `playbackSourceName`. 
If current context is a playlist, than `playbackSourceUri` is the playlist's uri and `playbackSourceName` is its name.

**API Changes**

* `playURI` is `playSpotifyURI` now and it takes `NSString*` instead of `NSURL*`. 
 Additional parameter `startingWithPosition:(NSTimeInterval)` was added to be able to start playback from a specific position.
* `queueURI` is `queueSpotifyURI` and also takes `NSString*`
* `SPTPlaybackState` has only playback related datat now: isPlaying, isRepeating, isShuffling, position, isActiveDevice. 
Properties `currentPlaybackPosition, currentTrackUri, currentTrackDuration, repeat, shuffle, isPlaying` were removed from `SPTAudioStreamingController`.
* The data that used to be in `SPTPlaybackState` is now in `SPTMetadata`.
* `didStartPlayingTrack` and `didStopPlayingTrack` are expecting `NSString*` as an argument! Be careful, it NOT `NSURL*` anymore.



Spotify iOS SDK Beta 20
======================

**Important Notes**

* set `allowNativeLogin` to `NO` if you want to disable native/SSO login through Spotify App
* use `-(BOOL)startWithClientId:clientId audioController: allowCaching: error:` with `allowCaching` set to `NO` to run it on tvOS
* to recieve update on current playback state and metadata use `-(void)audioStreaming: didChangePlaybackState:` callback of `SPTAudioStreamingPlaybackDelegate`. Check the demo app for more info.

**Bugs fixed**

* [IPV6 Support is Required for App Store Submission](https://github.com/spotify/ios-sdk/issues/676)

**API Changes** 
Updated functions:

* -(void)playURI:(NSURL *)uri callback:(SPTErrorableOperationCallback)block;
* -(void)queueURI:(NSURL *)uri callback:(SPTErrorableOperationCallback)block;

Functions not deprecated that has been removed

* -(void)playURIs:(NSArray *)uris fromIndex:(int)index callback:(SPTErrorableOperationCallback)block;
* -(void)playURIs:(NSArray *)uris withOptions:(SPTPlayOptions *)options callback:(SPTErrorableOperationCallback)block;
* -(void)replaceURIs:(NSArray *)uris withCurrentTrack:(int)index callback:(SPTErrorableOperationCallback)block;
* -(void)queueURIs:(NSArray *)uris clearQueue:(BOOL)clear callback:(SPTErrorableOperationCallback)block;
* @property (nonatomic, readonly, assign) BOOL initialized;
* @property (nonatomic, readonly) int trackListSize;
* -(void)stop:(SPTErrorableOperationCallback)block;

Deprecated functions that has been removed

* -(void)playURI:(NSURL *)uri fromIndex:(int)index callback:(SPTErrorableOperationCallback)block DEPRECATED_ATTRIBUTE;
* -(void)setURIs:(NSArray *)uris callback:(SPTErrorableOperationCallback)block DEPRECATED_ATTRIBUTE;
* -(void)playURIsFromIndex:(int)index callback:(SPTErrorableOperationCallback)block DEPRECATED_ATTRIBUTE;
* -(void)playTrackProvider:(id<SPTTrackProvider>)provider callback:(SPTErrorableOperationCallback)block DEPRECATED_ATTRIBUTE;
* -(void)playTrackProvider:(id<SPTTrackProvider>)provider fromIndex:(int)index callback:(SPTErrorableOperationCallback)block DEPRECATED_ATTRIBUTE;
* -(void)queueURI:(NSURL *)uri clearQueue:(BOOL)clear callback:(SPTErrorableOperationCallback)block DEPRECATED_ATTRIBUTE;
* -(void)queueTrackProvider:(id<SPTTrackProvider>)provider clearQueue:(BOOL)clear callback:(SPTErrorableOperationCallback)block DEPRECATED_ATTRIBUTE;
* -(void)queuePlay:(SPTErrorableOperationCallback)block DEPRECATED_ATTRIBUTE;
* -(void)queueClear:(SPTErrorableOperationCallback)block DEPRECATED_ATTRIBUTE;
* -(void)getRelativeTrackMetadata:(int)index callback:(void (^)(NSDictionary *))block DEPRECATED_ATTRIBUTE;
* -(void)getAbsoluteTrackMetadata:(int)index callback:(void (^)(NSDictionary *))block DEPRECATED_ATTRIBUTE;
* @property (nonatomic, readwrite) int trackListPosition DEPRECATED_ATTRIBUTE;
* @property (nonatomic, readonly) int queueSize DEPRECATED_ATTRIBUTE;

Spotify iOS SDK Beta 12
======================

**Bugs fixed**

* This release fixes the following issues.

([Issue #472](https://github.com/spotify/ios-sdk/issues/472))
([Issue #409](https://github.com/spotify/ios-sdk/issues/409))

Spotify iOS SDK Beta 11
======================

**Bugs fixed**

* This release fixes the problem where Apple would reject your App in App Store due the app showing pages where you can purchase Spotify outside of App Store.

([Issue #463](https://github.com/spotify/ios-sdk/issues/463))

Spotify iOS SDK Beta 10
======================

**Bugs fixed**

* This release fixes SDK crash/instability due to poor/no network. Method [NSJSONSerialization JSONObjectWithData:options:error:] can not take nil data and will crash the app when fetching playlist.

([Issue #380](https://github.com/spotify/ios-sdk/issues/380))
([Issue #374](https://github.com/spotify/ios-sdk/issues/374))
([Issue #331](https://github.com/spotify/ios-sdk/issues/331))


Spotify iOS SDK Beta 9
======================

**Bugs fixed**

* This release fixes one breaking authentication issue that was introduced when
  the latest Spotify Application was rolled out.
  ([Issue #357](https://github.com/spotify/ios-sdk/issues/357))


Spotify iOS SDK Beta 8
======================

**What's New**

* Most metadata methods inside `SPTRequest` have been moved into
  their respective container classes, like `SPTTrack`, `SPTFollow`,
  `SPTYourMusic` etc.

* Most metadata objects like `SPTTrack`, `SPTAlbum` and `SPTPlaylistSnapshot`
  now provide separate request creation and response parsing functions. This
  will allow you to use custom libraries like `AFNetworking` to manage your
  HTTP requests, also allowing for better caching and throttling of the
  requests. These methods also take an access token string instead of a
  `SPTSession` object.
  ([Issue #92](https://github.com/spotify/ios-sdk/issues/92))

* More following api's implemented in `SPTFollow` and `SPTPlaylistSnapshot`
  which allows for subscription to someone else's playlists.
  ([Issue #278](https://github.com/spotify/ios-sdk/issues/278))
  ([Issue #22](https://github.com/spotify/ios-sdk/issues/22))

* Lots of null pointer exceptions, unrecognised selectors and similar bugs
  should now be fixed.
  ([Issue #296](https://github.com/spotify/ios-sdk/issues/296))
  ([Issue #280](https://github.com/spotify/ios-sdk/issues/280))
  ([Issue #257](https://github.com/spotify/ios-sdk/issues/257))
  ([Issue #219](https://github.com/spotify/ios-sdk/issues/219))

* Many methods now supports a market parameter providing backend filtering
  of available tracks.
  ([Issue #295](https://github.com/spotify/ios-sdk/issues/295))

* Appledoc comments improved, you might even find some examples in there.

**Bugs fixed**

* Playback related issues.
  ([Issue #317](https://github.com/spotify/ios-sdk/issues/317))
  ([Issue #297](https://github.com/spotify/ios-sdk/issues/297))
  ([Issue #214](https://github.com/spotify/ios-sdk/issues/214))
  ([Issue #194](https://github.com/spotify/ios-sdk/issues/194))
    
* URL encoding issues.
  ([Issue #292](https://github.com/spotify/ios-sdk/issues/292))
  ([Issue #284](https://github.com/spotify/ios-sdk/issues/284))

* "Appears on" album type properly supported by `SPTAlbum`.
  ([Issue #277](https://github.com/spotify/ios-sdk/issues/277))

* SPTAuthViewController bugs.
  ([Issue #302](https://github.com/spotify/ios-sdk/issues/302))
  ([Issue #271](https://github.com/spotify/ios-sdk/issues/271))
  ([Issue #267](https://github.com/spotify/ios-sdk/issues/267))

* Misc XCode warning.
  ([Issue #276](https://github.com/spotify/ios-sdk/issues/276))
  ([Issue #264](https://github.com/spotify/ios-sdk/issues/264))

* Misc old bugs that seems to be mitigated recently.
  ([Issue #143](https://github.com/spotify/ios-sdk/issues/143))



Spotify iOS SDK Beta 7
======================

**What's New**

* A wrapper that allows for having the login flow inside your app without
  bouncing out through Safari and back has been added - it's called
  `SPTAuthViewController` and the sample application has been updated to
  make use of this.
  ([Issue #198](https://github.com/spotify/ios-sdk/issues/198))

* The web page which does the actual authentication does not contain any
  links to signup which blocked a few from releasing with the previous
  version on the AppStore.
  ([Issue #242](https://github.com/spotify/ios-sdk/issues/242))

* You can now request items that are available in a specific market, or
  the market of the current user. This should get rid of all unplayable
  tracks [if there's an alternative available](https://developer.spotify.com/web-api/track-relinking-guide/).

* Some methods in `SPTAudioStreamingController` has been marked as
  deprecated in favor of a future simpler API.

* Authentication information can now be persisted by `SPTAuth`, it also
  provides a singleton to make it even more easy.

**Bugs fixed**

* You can search for playlists.
  ([Issue #227](https://github.com/spotify/ios-sdk/issues/227))

* You can now get playlists for other users.
  ([Issue #241](https://github.com/spotify/ios-sdk/issues/241))

* Crashes due to null/unavailable values should be solved.
  ([Issue #172](https://github.com/spotify/ios-sdk/issues/172))
  ([Issue #251](https://github.com/spotify/ios-sdk/issues/251))
  ([Issue #218](https://github.com/spotify/ios-sdk/issues/218))
  ([Issue #210](https://github.com/spotify/ios-sdk/issues/210))

* You can now seek immediately when starting playback.
  ([Issue #190](https://github.com/spotify/ios-sdk/issues/190))

* KVO observing works on more properties.
  ([Issue #157](https://github.com/spotify/ios-sdk/issues/157))


Spotify iOS SDK Beta 6
======================

**What's New**

* You are now allowed to release apps based on this version in the App Store.

* Removed the Release Candidate flag - please be aware that some API calls may
  change before final release.

* Improved playback stability, better error handling for lossy network
  connections and when switching between Wi-Fi and cellular networks.

* Added events to notify the app about connectivity changes.

* Added methods for New releases / Featured playlists.
  ([Issue #165](https://github.com/spotify/ios-sdk/issues/165))

* Example token swap service is now stateless and stores an encrypted refresh
  token in your app instead of on the server, no more SQLite.
  ([Issue #159](https://github.com/spotify/ios-sdk/issues/159))
  ([Issue #155](https://github.com/spotify/ios-sdk/issues/155))

* All models are updated to include the fields returned by the
  current Web API.

* More control over track queueing and the currently queued tracks.

* New events for which tracks starts and stops playing, not only when track
  changes.

* `SPTAudioStreamingController` constructor has changed to require a Client ID
  instead of optional company/appname.

**Bugs fixed**

* `SPTSession` now contains an encrypted refresh token.
  ([Issue #155](https://github.com/spotify/ios-sdk/issues/155))

* Simple Track Playback example updated.
  ([Issue #154](https://github.com/spotify/ios-sdk/issues/154))

* `skipNext` doesn't jump over tracks anymore.
  ([Issue #152](https://github.com/spotify/ios-sdk/issues/152))

* Renamed 'public' in selector for Swift users.
  ([Issue #141](https://github.com/spotify/ios-sdk/issues/141))

* seekToOffset now works in play callbacks.
  ([Issue #135](https://github.com/spotify/ios-sdk/issues/135))

* Playlists with local tracks crashes.
  ([Issue #132](https://github.com/spotify/ios-sdk/issues/132))

* Scope constants lacking Scope suffix.
  ([Issue #129](https://github.com/spotify/ios-sdk/issues/129))

* `queueURI:clearQueue` not clearing queue.
  ([Issue #126](https://github.com/spotify/ios-sdk/issues/126))

* `playTrackProvider:fromIndex` not skipping to correct track.
  ([Issue #124](https://github.com/spotify/ios-sdk/issues/124))

* Create playlist returned bad request.
  ([Issue #123](https://github.com/spotify/ios-sdk/issues/123))
  ([Issue #137](https://github.com/spotify/ios-sdk/issues/137))

* Exception thrown parsing playlist response.
  ([Issue #121](https://github.com/spotify/ios-sdk/issues/121))

* Lots of stability and playback issues fixed to the playback code.

* You can now start playing a playlist from other than the first track.


** Known issues **

* Reading `shuffle`/`repeat` properties within the `didChangeShuffleStatus`/
  `didChangeRepeatStatus` callbacks might return the wrong value, but the
  values passed to the callbacks are correct.


Spotify iOS SDK Beta 5 (Release Candidate)
==========================================

**What's New**

* We merged the functionality of the `SPTTrackPlayer` into
  `SPTAudioStreamingController`, giving you proper support for gapless
  playback, shuffle, etc.

* You can now remove tracks from playlists.
  ([Issue #2](https://github.com/spotify/ios-sdk/issues/2))

* Shuffle is properly supported.
  ([Issue #25](https://github.com/spotify/ios-sdk/issues/25))

* The examples are background-audio enabled.
  ([Issue #35](https://github.com/spotify/ios-sdk/issues/35))

* You can now call a Logout function explicitly.
  ([Issue #42](https://github.com/spotify/ios-sdk/issues/42))

* Multi-get functionality for Tracks, Albums, Artists and Playlists.
  ([Issue #66](https://github.com/spotify/ios-sdk/issues/66))

* You can add multiple tracks to playlists at once.
  ([Issue #118](https://github.com/spotify/ios-sdk/issues/118))

* A couple of easter eggs.


**Bugs Fixed**

* Follower count is returned for playlists.
  ([Issue #57](https://github.com/spotify/ios-sdk/issues/57))

* Images, external urls and description is returned for playlists.

* You get a notification when a track was skipped because it's unavailable.
  ([Issue #102](https://github.com/spotify/ios-sdk/issues/102))

* `currentPlaybackPosition` is properly reset on track change.
  ([Issue #112](https://github.com/spotify/ios-sdk/issues/112))

* `SPTAuthUserReadPrivateScope` is defined.
  ([Issue #116](https://github.com/spotify/ios-sdk/issues/116))

* `SPTAudioStreamingController` completion block is called correctly.
  ([Issue #117](https://github.com/spotify/ios-sdk/issues/117))

* Partial track, album and artist return properties that were missing. (e.g.
  available territories and external urls.)


Spotify iOS SDK Beta 4
======================

**What's New**

* Added support for the "Implicit Grant" authentication flow. This flow doesn't
  require a Token Swap Service, but sessions only last an hour and you'll have
  to re-authenticate the user via Safari.

* Audio is now cached to storage during playback, improving the playback
  experience significantly. See the new `SPTAudioStreamingController` APIs
  for controlling the cache
  ([Issue #68](https://github.com/spotify/ios-sdk/issues/68)).

* Added support for the "Your Music" feature with the following APIs on
  `SPTRequest`:
  * `+savedTracksForUserInSession:callback:` to get a user's saved tracks.
  * `+saveTracks:forUserInSession:callback:` to save new tracks.
  * `+removeTracksFromSaved:forUserInSession:callback` to un-save tracks.
  * `+savedTracksContains:forUserInSession:callback` to check if track(s) are
    saved without downloading the whole list.

  ([Issue #5](https://github.com/spotify/ios-sdk/issues/5)).

* Added `[SPTArtist -requestRelatedArtists:callback:]` to request an artist's
  related artists.

* Added `[SPTPlaylistSnapshot -setTracksInPlaylist:withSession:callback:]`

* Added `[SPTPlaylistSnapshot -changePlaylistDetails:withSession:callback:]`
  ([Issue #67](https://github.com/spotify/ios-sdk/issues/67)).


**Bugs Fixed**

* Bitrate constants are documented correctly
  ([Issue #86](https://github.com/spotify/ios-sdk/issues/86)).

* Playback error codes are documented correctly
  ([Issue #91](https://github.com/spotify/ios-sdk/issues/91)).

* Creating playlists now works correctly
  ([Issue #90](https://github.com/spotify/ios-sdk/issues/90)).

* `SPTListPage` objects returned from search requests now return correct results
  when calling `-requestNextPageWithSession:callback:`
  ([Issue #87](https://github.com/spotify/ios-sdk/issues/87)).

* `[SPTAudioStreamingController -seekToOffset:callback:]` now works correctly when
  called within the `-playURI:` callback block
  ([Issue #70](https://github.com/spotify/ios-sdk/issues/70)).

* The library now works in the 64-bit iOS Simulator
  ([Issue #11](https://github.com/spotify/ios-sdk/issues/11)).

* The `[SPTAudioStreamingController -currentTrackMetadata]` property now
  correctly returns metadata
  ([Issue #101](https://github.com/spotify/ios-sdk/issues/101)).

* Scopes are now working properly
  ([Issue #99](https://github.com/spotify/ios-sdk/issues/99)).

Spotify iOS SDK Beta 3
======================

**What's New**

* `SPTAuth` and `SPTSession` has been completely rewritten to use the new Spotify
  authentication stack. This means that you need to re-do your auth code.
  Additionally, the Client ID and Client Secret provided with earlier betas will
  no longer work. See the main readme for more information
  ([Issue #3](https://github.com/spotify/ios-sdk/issues/3)).

  * The Basic Auth demo project has been rewritten to be much more friendly for
  new users to understand what's going on.

  * You'll need to update your Token Swap Service for the new auth flow. A new
  example is provided with the SDK.

* Added `SPTArtist` convenience getters for albums and top lists:
  `-requestAlbumsOfType:withSession:availableInTerritory:callback:` and
  `-requestTopTracksForTerritory:withSession:callback:`
  ([Issue #44](https://github.com/spotify/ios-sdk/issues/44),
  [Issue #34](https://github.com/spotify/ios-sdk/issues/34)).

* Added ability to get the user's "Starred" playlist using `SPTRequest`'s
  `+starredListForUserInSession:callback:` method
  ([Issue #15](https://github.com/spotify/ios-sdk/issues/15)).

* Various API changes and additions to metadata objects. In particular, users may
  be interested in the availability of album art on `SPTPartialAlbum` and track
  count and owner properties on `SPTPartialPlaylist`
  ([Issue #23](https://github.com/spotify/ios-sdk/issues/23)).

* `SPTAudioStreamingController` now has a customisable streaming bitrate.

* Added ability to get detailed information about the logged-in user using
  `SPTRequest`'s `+userInformationForUserInSession:callback:` method
  ([Issue #40](https://github.com/spotify/ios-sdk/issues/40)).

* Added `SPTListPage` class to deal with potentially large lists in a sensible
  manner. Objects with potentially long lists (playlist and album tracks lists,
  search results, etc) now return an `SPTListPage` to allow you to paginate
  through the list.


**Bugs Fixed**

* Core metadata classes now work properly
  ([Issue #52](https://github.com/spotify/ios-sdk/issues/52) and a bunch of others).

* Delegate methods are now marked `@optional`
  ([Issue #41](https://github.com/spotify/ios-sdk/issues/41)).

* Playlists not owned by the current user can be requested as long as your
  application has permission to do so
  ([Issue #10](https://github.com/spotify/ios-sdk/issues/10)).

* `SPTAudioStreamingController` now calls the `audioStreaming:didChangeToTrack:`
  delegate method with a `nil` track when track playback ends
  ([Issue #21](https://github.com/spotify/ios-sdk/issues/21)).

* `SPTAudioStreamingController` is more aggressive at clearing internal audio
  buffers ([Issue #46](https://github.com/spotify/ios-sdk/issues/46)).

* `SPTAudioStreamingController` no longer crashes on 64-bit devices when calling
  certain delegate methods ([Issue #45](https://github.com/spotify/ios-sdk/issues/45)).

* `SPTAuth` no longer crashes when handling an auth callback URL triggered by the
  user pushing "Cancel" when being asked to log in
  ([Issue #38](https://github.com/spotify/ios-sdk/issues/38)).

* Included .docset now correctly works with Xcode and Dash
  ([Issue #12](https://github.com/spotify/ios-sdk/issues/12)).


Spotify iOS SDK Beta 2
======================

**What's New**

* Special release for Music Hackday Paris. Hi, hackers!

* `SPTAudioStreamingController` now allows initialization with a custom audio output controller ([Issue #19](https://github.com/spotify/ios-sdk/issues/19)).

* `SPTTrackPlayer` now has an observable `currentPlaybackPosition` property ([Issue #28](https://github.com/spotify/ios-sdk/issues/28)).

* Various API changes and additions to metadata objects. In particular, users may be interested in the availability of album art on `SPTAlbum`, artist images on `SPTArtist` and 30 second audio previews on `SPTTrack` ([Issue #1](https://github.com/spotify/ios-sdk/issues/1)).

* The Simple Track Player example project now shows cover art in accordance with the above.


**Bugs Fixed**

* `SPTAudioStreamingController` now more reliably updates its playback position when seeking ([Issue #33](https://github.com/spotify/ios-sdk/issues/33)).

* `SPTTrackPlayer` now respects the index passed into `-playTrackProvider:fromIndex:` ([Issue #14](https://github.com/spotify/ios-sdk/issues/14)).

* `NSError` objects caused by audio playback errors are now more descriptive ([Issue #8](https://github.com/spotify/ios-sdk/issues/8)).


**Known Issues**

* Building for the 64-bit iOS Simulator doesn't work.

* For other open issues, see the project's [Issue Tracker](https://github.com/spotify/ios-sdk/issues).


Spotify iOS SDK Beta 1
=============

**What's New**

* Initial release.

**Known Issues**

* No cover art APIs. ([#1](https://github.com/spotify/ios-sdk/issues/1))

* Cannot remove items from playlists. ([#2](https://github.com/spotify/ios-sdk/issues/2))

* Sessions will expire after one day, even if persisted to disk. At this point,
you'll need to re-authenticate the user using `SPAuth`. ([#3](https://github.com/spotify/ios-sdk/issues/3))
