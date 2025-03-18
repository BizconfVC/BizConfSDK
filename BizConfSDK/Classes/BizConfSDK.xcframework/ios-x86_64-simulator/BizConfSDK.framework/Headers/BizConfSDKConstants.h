//
//  BizConfSDKConstants.h
//  BVProNext
//
//  Created by bizconf on 2024/10/11.
//  Copyright © 2024 Bizconf Telecom Co., Ltd. All rights reserved.
//

#ifndef BizConfSDKConstants_h
#define BizConfSDKConstants_h

typedef NS_ENUM(NSInteger, BizSDKAuthError) {
    /// Authentication is successful
    BizSDKAuthError_Success = 0,
    /// SDK not initialized
    BizSDKAuthError_SDKNotInitialized = 1,
    /// Domain format error
    BizSDKAuthError_DomainError = 2,
    /// Server internal error
    BizSDKAuthError_ServerInternalError = 3,
    /// Invalid channelID
    BizSDKAuthError_InvalidChannelID = 101,
    /// Key or Secret is empty
    BizSDKAuthError_KeyOrChannelIDEmpty = 109,
    /// Unknown error or Network issue, please check the network connection
    BizSDKAuthError_Unknown = 1001,
};

typedef NS_ENUM(NSInteger, BizSDKMeetError) {
    /// Start/Join meeting successfully
    BizSDKMeetError_Success = 0,
    /// SDK not initialized
    BizSDKMeetError_SDKNotInitialized = 1,
    /// MeetingNumber is null when start meeting
    BizSDKMeetError_MeetingNumberNull = 2,
    /// UserName is null when start meeting
    BizSDKMeetError_UserNameNull = 3,
    /// The meeting request was cancelled by the user themselves
    BizSDKMeetError_RequestCancleByUser = 4,
    /// The meeting is locked by the host
    BizSDKMeetError_MeetingLocked = 12,
    /// The authentication fails
    BizSDKMeetError_SDKAuthError = 102,
    /// Server internal error
    BizSDKMeetError_ServerInternalError = 103,
    /// The request parameters is incorrect
    BizSDKMeetError_ParameterIsIncorrect = 109,
    /// Please join the meeting after register
    BizSDKMeetError_JoinMeetingAfterRegister = 208,
    /// There is another meeting runnning on the meeting room, please try later
    BizSDKMeetError_HasAnotherRunnningMeeting = 661,
    /// There is anothre meeting running on the meeting room. Do you terminate it and start the new meeting.
    /// When you see this status code, you should call the startMeeting again and pass the forceJoin parameter as YES
    BizSDKMeetError_PromptToEndAnotherMeeting = 662,
    /// The total concurrent call license not enough
    BizSDKMeetError_RemainCapacityNotEnough  = 663,
    /// Time out to join in meeting
    BizSDKMeetError_JoinMeetingTimeout  = 664,
    /// Please input the meeting password
    /// When you see this status code, you should call the startMeeting again
    BizSDKMeetError_MissingPassword  = 665,
    /// The meeting passsword is invalid
    /// When you see this status code, you should call the startMeeting again
    BizSDKMeetError_InvalidPassword  = 666,
    /// Please login then join in meeting
    BizSDKMeetError_LoginBeforeJoinMeeting  = 667,
    /// Failure to start meeting, please try later
    BizSDKMeetError_FailureStartMeeting = 668,
    /// Then meeting is already end
    BizSDKMeetError_MeetingAlreadyEnded = 707,
    /// Unknown error or Network issue, please check the network connection
    BizSDKMeetError_Unknown = 1001,
};

typedef NS_ENUM(NSInteger, BizSDKExitReason) {
    /// Unknown error
    BizSDKExitReason_Unknown = 0,
    /// Exit with user leave room
    BizSDKExitReason_LeaveRoom = 1,
    /// Exit with user close room
    BizSDKExitReason_CloseRoom = 2,
    /// Exit with user is kicked out
    BizSDKExitReason_KickedOut = 3,
    /// Exit with user is aborted
    BizSDKExitReason_Aborted = 4,
};

typedef NS_ENUM(NSInteger, BizMeetingState) {
    /// No meeting is running
    BizMeetingState_Idle = 0,
    /// Connect to the meeting server status
    BizMeetingState_Connecting,
    /// Waiting for the host to start the meeting
    BizMeetingState_WaitingForHost,
    /// Meeting is ready, in meeting status
    BizMeetingState_InMeeting,
    /// Disconnect the meeting server, leave meeting status
    BizMeetingState_Disconnecting,
    /// Reconnecting meeting server status
    BizMeetingState_Reconnecting,
    /// Failed to connect the meeting server
    BizMeetingState_Failed,
    /// Meeting ends
    BizMeetingState_Ended,
    /// Unknown status
    BizMeetingState_Unknow,
    /// Meeting is locked to prevent the further participants to join the meeting
    BizMeetingState_Locked,
    /// Meeting is open and participants can join the meeting
    BizMeetingState_Unlocked,
    /// Participants who join the meeting before the start are in the waiting room
    BizMeetingState_InWaitingRoom,
    /// Upgrade the attendees to panelist in webinar
    BizMeetingState_WebinarPromote,
    /// Downgrade the attendees from the panelist
    BizMeetingState_WebinarDePromote,
    /// Waiting for the additional secret key
    BizMeetingState_WaitingExternalSessionKey,
};

#endif /* BizConfSDKConstants_h */
