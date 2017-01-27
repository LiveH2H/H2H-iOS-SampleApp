//
//  RTCSessionManager.h
//  TutorWebRTC
//
//  Created by Piyush Banerjee on 12/22/15.
//  Copyright © 2015 Spring Computing Technologies Pvt. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

#import "RTCSessionManagerConstants.h"
#import "RTCStream.h"
#import "RTCUser.h"

#import "RTCTurnServer.h"
#import "RTCStunServer.h"

#import "RTCMediaToggleData.h"
#import "RTCMediaConstraint.h"

typedef enum : NSUInteger {
    RTCSessionManagerCameraOrientationPortrait = 1,
    RTCSessionManagerCameraOrientationPortraitUpsideDown = 2,
    RTCSessionManagerCameraOrientationLandscapeRight = 3,
    RTCSessionManagerCameraOrientationLandscapeLeft = 4,
    RTCSessionManagerCameraOrientationPotraitOnly = 5,
    RTCSessionManagerCameraOrientationLandscapeOnly = 6,
    RTCSessionManagerCameraOrientationBoth = 7
} RTCSessionManagerCameraOrientation;

typedef NS_ENUM(NSUInteger, MEETING_TYPE) {
    MEETING_TYPE_GROUP_CALL,
    MEETING_TYPE_WEBINAR,
    MEETING_TYPE_BROADCAST,
    MEETING_TYPE_NONE
};

/**
 *  Responsibilities include:
 *
 *  1. Connecting, maintaining and disconnecting a signaling connection to the signaling server.
 *
 *  2. Creating, maintaining and discarding a basic WebRTC session.
 *
 *  @note Call requests/responses, sdp offer/answer requests etc. are communicated over the signaling connection.
 *  The signaling connection (channel) is @a NOT responsible for WebRTC related communications.
 */
@interface RTCSessionManager : NSObject

/**
 *  The URL of the signaling server.
 */
@property (readonly, strong) NSURL *_Nonnull serverURL;

/**
 *  The list of servers required for bypassing NATs for successful RTC even on restricted networks.These should be instances of RTCStunServer or RTCTurnServer.
 */
@property (readonly, strong) NSArray<RTCServer *> *_Nonnull arrayOfServers;

/**
 *  The dictionary of parameters for joining the room
 */
@property (readwrite, strong) NSDictionary *_Nonnull joinRoomParameters;

@property (readonly, getter=getMeetingType) MEETING_TYPE meetingType;

/**
 *  The amount of time in seconds to wait before trying to connect again.
 *  Default value is 1 second.
 */
@property (readonly, nonatomic) NSUInteger retryDelay;

/**
 *  The maximum number of retry attempts before stopping the re-connection process.
 *  Default value is 1000000 (1 million OR 10^6).
 */
@property (readonly, nonatomic) NSUInteger maximumRetryAttempts;

/**
 *  The current count of the retry attempt.
 *  Default value is 0. It is incremented every time a re-connection is attempted.
 *  When this value crosses the value of 'maximumRetryAttempts', the re-connection process is stopped.
 */
@property (readonly, nonatomic) NSUInteger currentRetryCount;

/**
 *  The state of the signaling connection.
 */
@property (readonly, nonatomic) RTCConnectionState connectionState;

/**
 *  The camera to be used for capturing video.
 *  Default is RTCCameraFront.
 */
@property (readwrite, nonatomic) RTCCamera camera;

/**
 *  The current user of the device logged into a WebRTC session.
 */
@property (readonly, strong) RTCUser *_Nonnull localUser;

/**
 *  The orientation that is to be set for the camera that is used for capturing video.
 *   Needs to be set before join.
 */
@property(readwrite, nonatomic) RTCSessionManagerCameraOrientation cameraOrientation;

/**
 *  The camera position that is to be used for capturing video.
 *  Default value suggests use front camera
 */
@property(readwrite,nonatomic) DeviceCameraPosition cameraPosition;

/**
 *  Flag which controlls RTCIceTransportsType
 */
@property (readwrite, nonatomic) BOOL relayOnly;

@property (readonly, nonatomic) NSInteger maxVideoCount;

/**
 *  Initializes an instance of RTCSessionManager with the signaling server URL.
 *
 *  @param serverURL The URL of the signaling server.
 *
 *  @return An instance of RTCSessionManager or @p nil.
 */
- (instancetype _Nonnull)initWithServerURL:(NSURL *_Nonnull)serverURL;

/**
 *  Initializes an instance of RTCSessionManager with the specified parameters.
 *
 *  @param serverURL            The URL of the signaling server.
 *  @param retryDelay           The amount of time in seconds to wait before trying to connect again; in case of failure.
 *  @param maximumRetryAttempts The maximum number of retry attempts before stopping the re-connection process.
 *
 *  @return An instance of RTCSessionManager or @p nil.
 */
- (instancetype _Nonnull)initWithServerURL: (NSURL *_Nonnull)serverURL
                                retryDelay: (NSUInteger)retryDelay
                   andMaximumRetryAttempts: (NSUInteger)maximumRetryAttempts;


/**
 *  Initializes an instance of RTCSessionManager with the specified parameters.
 *
 *  @param serverURL            The URL of the signaling server.
 *  @param arrayOfServers       The list of servers required for bypassing NATs for successful RTC even on restricted networks.
 *  @return An instance of RTCSessionManager or @p nil.
 */
- (instancetype _Nonnull)initWithServerURL: (NSURL *_Nonnull)serverURL
                         andArrayOfServers: (NSArray<RTCServer *> *_Nonnull)arrayOfServers;

/**
 *  Initializes an instance of RTCSessionManager with the specified parameters.
 *
 *  @param serverURL            The URL of the signaling server.
 *  @param retryDelay           The amount of time in seconds to wait before trying to connect again; in case of failure.
 *  @param maximumRetryAttempts The maximum number of retry attempts before stopping the re-connection process.
 *  @param arrayOfServers       The list of servers required for bypassing NATs for successful RTC even on restricted networks.
 *  @return An instance of RTCSessionManager or @p nil.
 */
- (instancetype _Nonnull)initWithServerURL: (NSURL *_Nonnull)serverURL
                                retryDelay: (NSUInteger)retryDelay
                   andMaximumRetryAttempts: (NSUInteger)maximumRetryAttempts
                         andArrayOfServers: (NSArray<RTCServer *> *_Nonnull)arrayOfServers;

/**
 *  Initializes an instance of RTCSessionManager with the specified parameters.
 *
 *  @param serverURL            The URL of the signaling server.
 *  @param retryDelay           The amount of time in seconds to wait before trying to connect again; in case of failure.
 *  @param maximumRetryAttempts The maximum number of retry attempts before stopping the re-connection process.
 *  @param arrayOfServers       The list of servers required for bypassing NATs for successful RTC even on restricted networks.
 *  @param joinRoomParameters   The dictionary of parameters for joining the room
 *  @param minMediaConstraint   Minimum media constraint depending on meeting type
 *  @param maxMediaConstraint   Maximum media constraint depending on meeting type
 *  @return An instance of RTCSessionManager or @p nil.
 */
- (instancetype _Nonnull)initWithServerURL: (NSURL *_Nonnull)serverURL
                                retryDelay: (NSUInteger)retryDelay
                   andMaximumRetryAttempts: (NSUInteger)maximumRetryAttempts
                         andArrayOfServers: (NSArray<RTCServer *> *_Nonnull)arrayOfServers
                     andJoinRoomParameters: (NSDictionary *_Nonnull)joinRoomParameters
                     andMinMediaConstraint: (RTCMediaConstraint *_Nonnull) minMediaConstraint
                     andMaxMediaConstraint: (RTCMediaConstraint *_Nonnull) maxMediaConstraint
                               isRelayOnly: (BOOL)relayOnly
                             maxVideoCount: (NSUInteger)maxVideoCount;

/**
 *  Updates the URL of the signaling server.
 *  In case of failure the 'error' parameter will point to an error object.
 *
 *  @param serverURL The URL of the new server to use for signaling.
 *  @param error     @p Nil if no error has occurred, else points to an error object.
 *
 *  @return Returns @p true if the URL was successfully updated. Else returns @p false.
 */
-(BOOL)updateServerURL: (NSURL *_Nonnull)serverURL
             withError: (NSError *_Nonnull *_Nonnull)error;

/**
 *  Starts connecting to the signaling server.
 *
 *  @note A retry mechanism is currently inplace, which tries to re-connect (in case of failure) after every 'retryDelay' number of seconds, till a connection is successfully established OR till the 'maximumRetryAttempts' is reached.
 */
- (void)connect;

/**
 *  Discards the signaling connection.
 */
- (void)disconnect;

/**
 *  Enables or disables the media and notifies signaling server.
 *
 *  @param mediaToggleData The instance of RTCToggleMediaData used for toggling the required media.
 *  @param isChangesForLocalUser The user for whom media is to enabled/disabled is local or participant.
 *  @param error     @p Nil if no error has occurred, else points to an error object.
 *  @return Returns  @p true if the URL was successfully updated. Else returns @p false.
 */
- (BOOL) setEnabledFor: (RTCMediaToggleData *_Nonnull)mediaToggleData
andIsChangesForLocalUser: (BOOL) isChangesForLocalUser
             andError : (NSError *_Nonnull __autoreleasing *_Nonnull)error;

/**
 *  Switch camera position from front to back or vice versa
 */
- (void) switchCamera;

/**
 *  Check if user has camera permissions.
 */
-(BOOL) isVideoPermissionGranted;

/**
 *  Check if user has microphone permissions.
 */
-(BOOL) isAudioPermissionGranted;

/**
 *  Request for test connection.
 */
-(void)testConnection;
@end
