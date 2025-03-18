//
//  BizConfVideoSDKSettings.h
//  BVProNext-SDK-iOS
//
//  Created by bizconf on 2024/11/2.
//

#import <Foundation/Foundation.h>

@interface BizConfVideoSDKSettings : NSObject

/// Show/Hide meeting expansion in the meeting view
@property (assign, nonatomic) BOOL meetingExpansionShow;

/// Show/Hide meeting title in the meeting bar
@property (assign, nonatomic) BOOL meetingTitleHidden;

/// Show/Hide Invite button in the meeting bar
@property (assign, nonatomic) BOOL meetingInviteHidden;

/// Set to auto-connect the audio when user joins meeting
/// - Parameter connected YES means the audio device is automatically connected, otherwise not
- (void)setAutoConnectInternetAudio:(BOOL)connected;

/// Query if the user joins meeting with audio device
/// YES means the audio device is automatically connected, otherwise not
- (BOOL)autoConnectInternetAudio;

/// Set to mute user's audio when he joins the meeting
/// - Parameter muted: YES means to mute the audio, otherwise not
- (void)setMuteAudioWhenJoinMeeting:(BOOL)muted;

/// Query if user's audio is muted when he joins the meeting
/// YES means muted, otherwise not
- (BOOL)muteAudioWhenJoinMeeting;

/// Set to mute user's video when he joins the meeting
/// - Parameter muted YES means to mute the video, otherwise not
- (void)setMuteVideoWhenJoinMeeting:(BOOL)muted;

/// Query if user's video is muted when he joins the meeting
/// YES means muted, otherwise not
- (BOOL)muteVideoWhenJoinMeeting;

#pragma mark - Singleton
+ (instancetype)sharedInstance;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end
