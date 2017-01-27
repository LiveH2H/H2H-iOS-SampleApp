//
//  RTCSessionManagerConstants.h
//  TutorWebRTC
//
//  Created by Piyush Banerjee on 12/23/15.
//  Copyright © 2015 Spring Computing Technologies Pvt. Ltd. All rights reserved.
//

/** @file RTCSessionManagerConstants.h */


#ifndef RTCSessionManagerConstants_h
#define RTCSessionManagerConstants_h


#pragma mark - Generic constants

/**
 *  The error domain of the errors raised by the RTCSessionManager and its subclasses.
 */
#define RTCErrorDomain  (@"RTCSessionManagerErrorDomain")

/**
 *  The media audio.
 */
#define MEDIA_AUDIO         (@"audio")

/**
 *  The media video.
 */
#define MEDIA_VIDEO         (@"video")
/**
 *  The audio sticky bit.
 */
#define IS_AUDIO_STICKY     (@"isAudioSticky")
/**
 *  The video sticky bit.
 */
#define IS_VIDEO_STICKY     (@"isVideoSticky")

/**
 *  The network Statistics Fetch Interval in seconds
 */
#define networkStatsFetchInterval 60.0

#pragma mark - Notification names

/**
 *  This notification is posted to indicate that the signaling connection state has changed.
 *  @note If any error occurs, the userInfo dictionary will contain an NSError object accessible by the NSUnderlyingErrorKey.
 */
#define RTCNotificationConnectionStateChanged       (@"connectionState")


/**
 *  This notification is posted to indicate that the registration state has changed.
 *  @note If any error occurs, the userInfo dictionary will contain an NSError object accessible by the NSUnderlyingErrorKey.
 */
#define RTCNotificationRegistrationStateChanged     (@"registrationState")

/**
 *  This notification is posted to indicate that the unicast session state has changed.
 *  @note If any error occurs, the userInfo dictionary will contain an NSError object accessible by the NSUnderlyingErrorKey.
 */
#define RTCNotificationUnicastStateChanged          (@"unicastState")


/**
 *  This notification is posted to indicate that the broadcast session state has changed.
 *  @note If any error occurs, the userInfo dictionary will contain an NSError object accessible by the NSUnderlyingErrorKey.
 */
#define RTCNotificationBroadcastStateChanged        (@"broadcastState")


/**
 *  This notification is posted to indicate that the multicast room joining state has changed.
 *  @note If any error occurs, the userInfo dictionary will contain an NSError object accessible by the NSUnderlyingErrorKey.
 */
#define RTCNotificationMulticastRoomStateChanged    (@"multicastRoomState")

/**
 *  This notification is posted to indicate that the multicast session state has changed.
 *  @note If any error occurs, the userInfo dictionary will contain an NSError object accessible by the NSUnderlyingErrorKey.
 */
#define RTCNotificationMulticastStateChanged        (@"multicastState")


/**
 *  This notification is posted to indicate that an incoming call request has been received.
 */
#define RTCNotificationIncomingCall     (@"incomingCall")


/**
 *  This notification is posted to indicate that the stream for a particular user has changed.
 *  The notification's object is the user (RTCUser) whose stream has changed.
 */
#define RTCNotificationUserStreamChanged        (@"userStream")

/**
 *  This notification is posted to indicate that the broadcast stream has changed.
 */
#define RTCNotificationBroadcastStreamChanged   (@"broadcastStream")

/**
 *  This notification is posted to indicate that the multicast room has changed.
 */
#define RTCNotificationMulticastRoomChanged     (@"mutlicastRoom")

/**
 *  This notification is posted to indicate that the users in the multicast room have changed.
 */
#define RTCNotificationRoomUsersChanged         (@"roomUsers")

/**
 *  This subprotocol is used by web socket to establish signalling connection.
 */
#define RTCConnectionProtocol                   (@"sig-webrtc")

/**
 *  This notification is posted to indicate that the media stream has been toggled.
 */
#define RTCNotificationMediaStreamToggledForLocalUser       (@"mediaStreamToggledForLocalUser")

/**
 *  This notification is posted to indicate that the media stream has been toggled.
 */
#define RTCNotificationMediaStreamToggledForParticipant       (@"mediaStreamToggledForParticipant")


/**
 *  This notification is posted to indicate that the Translator has joined metting.
 */
#define RTCNotificationTranslatorJoinedMeeting       (@"translatorJoinedMeeting")

/**
 *  This notification is posted to indicate that the Translator has joined metting.
 */
#define RTCNotificationUsersListChanged     (@"UsersListChanged")

/**
 *  This notification is posted to indicate that the new user has arrived the meeting.
 */
#define RTCNotificationNewUserHasArrived     (@"NewUserHasArrived")

/**
 *  This notification is posted to indicate that the existing user has left the meeting.
 */
#define RTCNotificationExistingUserHasLeft    (@"ExistingUserHasLeft")


/**
 *  This notification is posted to indicate that the Whiteboard state has changed.
 */
#define RTCNotificationWhiteboardStateChanged       (@"whiteboardStateChanged")

/**
 *  This notification is posted to indicate that the Whiteboard status is changed for Remote user.
 */
#define RTCNotificationWhiteboardStateChangedForRemoteUser       (@"whiteboardStateChangedForRemoteUser")

/**
 *  This notification is posted to indicate that server error is received.
 */

#define RTCNotificationServerErrorRecieved  (@"serverErrorReceived")

/**
 *  This notification is posted to indicate that user should grant access for microphone and camera.
 */

#define RTCNotificationGrantMediaAccess (@"NotifyUserToGrantMediaAccess")

/**
 *  This notification is posted to that we received raise hand event.
 */

#define RTCNotificationRaiseHandReceived (@"NotifyRaiseHandReceived")

/**
 *  This notification is posted to that we received video status changed event.
 */
#define RTCNotificationVideoStatusChanged (@"NotifyVideoStatusChanged")

/**
 * This notification is posted when host forces user to quit the meeting
 */
#define RTCNotificationLeftRoomReceived  (@"NotifyLeftRoomReceived")

/**
 * This notification is posted when host wanted to remove user from the meeting
 */
#define RTCNotificationStickyRemoveMeetReceived  (@"NotifyStickyRemoveMeetReceived")

/**
 * This notification is posted when network status is changed
 */
#define RTCNotificationNetworkStatusChanged  (@"NotifyNetworkStatusChanged")

/**
 * This notification is posted when network status is changed for local users local network
 */
#define RTCNotificationLocalNetworkStatusChanged  (@"NotifyLocalStatusChanged")

/**
 * This notification is posted when network status is changed for local users local network
 */
#define RTCNotificationLocalNetworkStatusChangedUI  (@"NotifyLocalStatusChangedUI")

/**
 * This notification is posted when Admin support user has joined room
 */
#define RTCNotificationAdminJoined  (@"NotifyAdminJoined")

/**
 * This notification is posted when host needs to toggle media of local user
 */
#define RTCNotificationHostNeedToToggleMedia  (@"HostNeedToToggleMedia")

/**
 * This notification is posted when participant button has to be deselected
 */
#define RTCNotificationDeselectParticipantButton  (@"DeselectParticipantButton")

/**
 * This notification is posted when camera is switched for local user from front to back or vice versa
 */
#define RTCNotificationCameraSwitched   (@"CameraSwitched")

/**
 * This notification is posted when share screen started
 */
#define RTCNotificationShareScreenStarted   (@"ShareScreenStarted")

/**
 * This notification is posted when share screen stopped
 */
#define RTCNotificationShareScreenStopped   (@"ShareScreenStopped")

/**
 * This notification is posted when raise hand permission is received
 */
#define RTCNotificationUpdateRaiseHandPermission   (@"UpdateRaiseHandPermission")

/**
 * This notification is posted when chat permission is received
 */
#define RTCNotificationUpdateChatPermission   (@"UpdateChatPermission")

/**
 *  This notification is posted to that we recived transcript.
 */

#define RTCNotificationRaiseTranscriptReceived (@"NotifyRaiseTranscriptReceived")

/**
 *  This notification is posted to recording is started at server.
 */

#define RTCNotificationRecordingStartedReceived (@"NotifyrecordingStartedReceived")

/**
 *  This notification is posted to that recording is stopped at server.
 */
#define RTCNotificationRecordingStoppedReceived (@"NotifyRecordingStoppedReceived")

/**
 *  This notification is posted to that we recived attendee serve hand success [request participant to enable audio].
 */

#define RTCNotificationAttendeeServeHandSuccessForBroadcast (@"NotifyAttendeeServeHandSuccessForBroadcast")
/**
 *  This notification is posted when error join room retry limit received
 */
#define RTCNotificationErrorJoinRoomRetryLimit  (@"NotifyErrorJoinRoomRetryLimit")

/**
 *  This notification is posted to indicate that the stream for a particular user for screen sharing has changed.
 *  The notification's object is the user (RTCUser) whose stream has changed.
 */
#define RTCNotificationUserScreenShareStreamChanged        (@"userScreenShareStream")

/**
 *  This notification is posted when host wants to unmute the media but we need confimation from user
 */
#define RTCNotificationMediaToggleConfirmation (@"MediaToggleConfirmation")

/**
 *  This notification is posted when BROADCAST host entered or left the meeting
 */
#define RTCNotificationReloadHLSVideo (@"ReloadHLSVideo")

/**
 * This notification is posted when media for attendee is toggled.
 */
#define RTCNotificationMediaToggleAttendee  (@"NotifyMediaToggleAttendee")

/**
 * This notification is posted when we receive test connection result.
 */
#define RTCNotificationTestConnectionResultReceived  (@"NotifyTestConnectionResultReceived")

/**
 * This notification is posted when we receive test connection result.
 */
#define RTCNotificationTCPMediaICECompleted          (@"NotifyTCPMediaICECompleted")

/**
 * This notification is posted when we receive join room fail.
 */
#define RTCNotificationJoinRoomFail          (@"NotifyJoinRoomFail")

#pragma mark - Role constants
/**
 *  This constant is used to identify if local user is host
 */
#define value_h2h_host                                      @"H2H_HOST"
/**
 *  This constant is used to identify if local user is host
 */
#define value_h                                             @"H"

/**
 *  This constant is used to identify if local user is Participant
 */
#define value_P                                             @"P"

/**
 *  This constant is used to identify if local user is Admin support
 */
#define value_S                                             @"S"

/**
 *  This constant is used to identify if local user is Admin support
 */
#define value_Attendee_webinar                              @"Attendee_Webinar"

/**
 *  This constant is used to identify key for meeting type
 */
#define key_meetingType                                    @"meetingType"

/**
 *  This constant is used to identify room type
 */
#define value_meeting_group                                 @"group"

/**
 *  This constant is used to identify room type
 */
#define value_meeting_webinar                               @"webinar"
/**
 *  This constant is used to identify room type
 */
#define value_meeting_broadcast                               @"broadcast"


#pragma mark - State constants

/**
 *  Definite states of the signaling connection.
 */
typedef NS_ENUM(NSInteger, RTCConnectionState) {
    /**
     *  The connection has been closed.
     */
    RTCConnectionStateDisconnected,
    /**
     *  The connection is being established.
     */
    RTCConnectionStateConnecting,
    /**
     *  The connection has been established.
     */
    RTCConnectionStateConnected,
};

/**
 *  Definite states of registration with the server.
 *  @note Currently only the Unicast server supports explicit registration.
 */
typedef NS_ENUM(NSInteger, RTCRegistrationState) {
    /**
     *  The user is currently not registered with the server.
     */
    RTCRegistrationStateUnregistered,
    /**
     *  The user's registration is ongoing.
     */
    RTCRegistrationStateRegistering,
    /**
     *  The user is currently registered with the server.
     */
    RTCRegistrationStateRegistered
};

/**
 *  Definite states of a unicast RTC session.
 */
typedef NS_ENUM(NSInteger, RTCUnicastState) {
    /**
     *  There is no active unicast session.
     */
    RTCUnicastStateStopped,
    /**
     *  A unicast session is being started.
     */
    RTCUnicastStateStarting,
    /**
     *  A unicast session has started.
     */
    RTCUnicastStateStarted,
};

/**
 *  Definite states of a broadcast RTC session.
 */
typedef NS_ENUM(NSInteger, RTCBroadcastState) {
    /**
     *  There is no active broadcast session.
     */
    RTCBroadcastStateStopped,
    /**
     *  A request to start a audio/video broadcast has been sent to the server.
     */
    RTCBroadcastStateProcessingPresentation,
    /**
     *  A broadcast of local media stream is active.
     */
    RTCBroadcastStatePresenting,
    /**
     *  A request to view a remote broadcast session has been sent to the server.
     */
    RTCBroadcastStateProcessingViewership,
    /**
     *  A remote broadcast session is being viewed.
     */
    RTCBroadcastStateViewing
};

/**
 *  Definite states of joining a multicast room.
 */
typedef NS_ENUM(NSInteger, RTCMulticastRoomState) {
    /**
     *  Currently no room is joined.
     */
    RTCMulticastRoomStateUnjoined,
    /**
     *  A room is being joined.
     */
    RTCMulticastRoomStateJoining,
    /**
     *  A room has been joined.
     */
    RTCMulticastRoomStateJoined
};

/**
 *  Definite states of a multicast RTC session.
 */
typedef NS_ENUM(NSInteger, RTCMulticastState) {
    /**
     *  There is no active multicast session.
     */
    RTCMulticastStateStopped,
    /**
     *  A mutlicast session is being started.
     */
    RTCMulticastStateStarting,
    /**
     *  A multicast session is active.
     */
    RTCMulticastStateStarted
};

/**
 *  The types of the camera supported.
 */
typedef NS_ENUM(NSInteger, RTCCamera) {
    /**
     *  Denotes the front camera.
     */
    RTCCameraFront,
    /**
     *  Denotes the rear camera.
     */
    RTCCameraBack
};

/**
 *  The error codes used by the RTCSessionManager and its subclasses.
 */
typedef NS_ENUM(NSInteger, RTCError) {
    /**
     *  Indicates that the signaling connection was terminated abnormally and hence the re-connection process has been started.
     */
    RTCErrorSignalingLost,
    /**
     *  Indicates that the maximum number of re-connection attempts was reached, hence the re-connection process was stopped.
     */
    RTCErrorSignalingReconnectionFailed,
    /**
     *  Indicates that the server URL could not be updated as a signaling connection is currently open
     *  using the existing server URL OR that a re-connection may be in progress.
     */
    RTCErrorSignalingServerURLCurrentlyInUse
};

/**
 * The types of media.
 */
typedef NS_ENUM (NSInteger, MediaType) {
    /**
     *  Denotes the media type audio.
     */
    MediaTypeAudio = 1,
    /**
     *  Denotes the media type video.
     */
    MediaTypeVideo = 2
};


/**
 * The camera positions.
 */
typedef NS_ENUM (NSInteger, DeviceCameraPosition) {
    /**
     *  Denotes the position of Front camera.
     */
    DeviceCameraPositionFront = 1,
    /**
     *  Denotes the position of Back Camera.
     */
    DeviceCameraPositionBack = 2
};

/**
 * Media toggle states.
 */
typedef NS_ENUM (NSInteger, MediaToggleState) {
    /**
     *  Denotes media is ON.
     */
    MediaStateON = 1,
    /**
     *  Denotes media is OFF.
     */
    MediaStateOFF = 2,
    /**
     *  Denotes media is disabled, but ON .
     */
    MediaStateDisabledON = 3,
    /**
     *  Denotes media is disabled, and OFF .
     */
    MediaStateDisabledOFF = 4,
    /**
     *  Denotes media hidden .
     */
    MediaStateHidden = 5
};

/**
 * Toggle states.
 */
typedef NS_ENUM (NSInteger, ToggleState) {
    /**
     *  Denotes media is ON/OFF.
     */
    ToggleStateOnOFF = 1,
    /**
     *  Denotes media is Disabled/Enabled.
     */
    ToggleStateEnabledDisabled = 2,
};

/**
 * Toggle Permission Type.
 */
typedef NS_ENUM (NSInteger, TogglePermissionType) {
    /**
     *  Denotes media is ON/OFF.
     */
    TogglePermissionTypeHandRaise = 1,
    /**
     *  Denotes media is Disabled/Enabled.
     */
    TogglePermissionTypeChat = 2,
};

#endif /* RTCSessionManagerConstants_h */