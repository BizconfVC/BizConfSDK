//
//  BizConfVideoSDK.h
//  BVProNext
//
//  Created by bizconf on 2024/10/11.
//  Copyright © 2024 Bizconf Telecom Co., Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <BizConfSDK/BizConfSDKConstants.h>
#import <BizConfSDK/BizConfSDKDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@class BVSDKInitContext;
@class BVSDKDomaminContext;
@class BVConfStartJoinModel;

@interface BizConfVideoSDK : NSObject

#pragma mark - initialize、auth
/// [Required] Call the function to initialize BizConfVideoSDK
/// - Parameter context: Initialize the parameter configuration of the SDK, please See [BVSDKInitContext]
- (void)initSDK:(BVSDKInitContext *_Nullable)context;

/// [Optional] Call the function to initialize Logger
/// - Note: You should call it once in the didFinishLaunchingWithOptions
- (void)initLogger;

/// [Optional] Call the function to switch BizConfVideoSDK domain
/// - Note After switch domain, need to auth again
/// - Parameter context: Initialize the parameter configuration of the SDK, please See [BVSDKDomaminContext]
- (void)setCustomDomain:(BVSDKDomaminContext *_Nullable)context;

/// [Required] Authenticate SDK.
/// - Parameters:
///   - channelId: sdk channelId
///   - key: sdk key
///   - completion: auth result call back
- (void)authSdk:(NSString *_Nonnull)channelId 
        withKey:(NSString *_Nonnull)key
     completion:(void (^_Nullable)(BizSDKAuthError status))completion;

/// Authorization
/// - Returns: YES auth successfully. Otherwise not
- (BOOL)isAuthorized;

#pragma mark - Meeting
/// Start or Join Meeting
/// - Parameter model: Create an instance with right information via
- (void)joinMeeting:(BVConfStartJoinModel *_Nonnull)model completion:(void (^_Nullable)(BizSDKMeetError error))completion;

/// Start Meeting
/// - Note: Not recommended, adapted for old SDK users
- (void)startMeeting:(NSString *_Nonnull)meetingNo
            userName:(NSString *_Nonnull)userName
                cuid:(NSString *_Nullable)cuid
                 zak:(NSString *_Nullable)zak
          completion:(void (^_Nullable)(BizSDKMeetError error))completion __attribute__((deprecated("Use new joinMeeting instead")));

/// Join Meeting
/// - Note: Not recommended, adapted for old SDK users
- (void)joinMeeting:(NSString *_Nonnull)meetingNo
           userName:(NSString *_Nonnull)userName
           password:(NSString *_Nullable)password
               cuid:(NSString *_Nullable)cuid
                zak:(NSString *_Nullable)zak
         completion:(void (^_Nullable)(BizSDKMeetError error))completion __attribute__((deprecated("Use new joinMeeting instead")));

/// Is it in the meeting
/// - Returns: YES is in meeting. Otherwise not
- (BOOL)isInMeeting;

#pragma mark - SDK Info
/// SDK Version
/// - Returns: Version like "1.0.0"
- (NSString *)getSDKVersion;

#pragma mark - Delegate
/// Callback of receiving meeting events
@property (nullable, assign, nonatomic) id <BizConfSDKDelegate> delegate;

#pragma mark - Singleton
/// Call the function to get the BizConfVideoSDK client
+ (BizConfVideoSDK *)sharedSDK;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

@interface BVSDKInitContext : NSObject

/// [Optional] enableLog Set  log enable or not
@property (nonatomic, assign) BOOL enableLog;
/// [Optional] productName
@property (nonatomic, copy) NSString *productName;
/// [Optional] appVersion
@property (nonatomic, copy) NSString *appVersion;
/// [Optional] parameters
@property (nonatomic, strong) NSDictionary *parameters;

@end

@interface BVSDKDomaminContext : NSObject

/// [Optional] The apiUrl is used to start/join a  meeting
@property (nonatomic, copy) NSString *apiUrl;
/// [Optional]  The mediaUrl is used to start/join a  meeting
@property (nonatomic, copy) NSString *mediaUrl;

@end

@interface BVConfStartJoinModel : NSObject

/// [Required] meetingNo
@property (nonatomic, copy) NSString *meetingNo;
/// [Required] name displayed for the meeting
@property (nonatomic, copy) NSString *userName;
/// [Optional] access token, used to determine identity during the meeting
/// when you start meeting, you should pass zak，otherwise you can not be the host
@property (nonatomic, copy) NSString *zak;
/// [Optional] Third party user IDs may only be passed in during link membership
@property (nonatomic, copy) NSString *cuid;
/// [Optional] password
@property (nonatomic, copy) NSString *password;
/// [Optional] mandatory join meeting, Otherwise not
/// when BizSDKMeetError is BizSDKMeetError_PromptToEndAnotherLiveConf
/// you should pass YES, otherwise NO
@property (nonatomic, assign) BOOL forceJoin;
/// [Optional] current VC
@property (nonatomic, strong) UIViewController *currentVC;

@end

NS_ASSUME_NONNULL_END
