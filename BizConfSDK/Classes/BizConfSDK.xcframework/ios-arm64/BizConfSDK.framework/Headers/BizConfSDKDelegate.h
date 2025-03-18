//
//  BizConfSDKDelegate.h
//  BVProNext-SDK-iOS
//
//  Created by bizconf on 2024/10/28.
//

#import <Foundation/Foundation.h>
#import <BizConfSDK/BizConfSDKConstants.h>

#pragma mark - BizConfSDKDelegate

@protocol BizConfSDKDelegate <NSObject>

@optional

/// Notify the meeting is launch success
- (void)onBizLaunchSuccess;

/// Notify the meeting is launch failure
- (void)onBizLaunchFailure:(NSError *)error;

/// Notify the meeting is cancel during launch
- (void)onBizLaunchCancel;

/// Notify the user that the meeting is end
- (void)onExitedWithReason:(BizSDKExitReason)reason;

/// Notify the user that the meeting status changes. 
/// - Parameter state: The meeting status changes.
- (void)onBizMeetingStateChange:(BizMeetingState)state;

@end
