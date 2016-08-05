//
//  RTCUnicastSessionManager.h
//  TutorWebRTC
//
//  Created by Piyush Banerjee on 1/14/16.
//  Copyright © 2016 Spring Computing Technologies Pvt. Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "RTCSessionManager.h"

/**
 *  Responsible for managing the entire life-cycle of a one-to-one WebRTC call.
 */
@interface RTCUnicastSessionManager : RTCSessionManager

/**
 *  The state of the user's registration on the server.
 */
@property (readonly, nonatomic) RTCRegistrationState registrationState;

/**
 *  The state of the unicast WebRTC session.
 */
@property (readonly, nonatomic) RTCUnicastState callState;

/**
 *  The remote user involved in the unicast session.
 */
@property (readonly, strong) RTCUser *remoteUser;

/**
 *  The remote user whose incoming call request has an action pending (accept/reject).
 */
@property (readonly, strong) RTCUser *pendingCallingUser;


/**
 *  Starts the process of registering the current user with the server, with the name specified.
 *
 *  @param name The name of the current user.
 */
- (void)registerUserWithName:(NSString *)name;

/**
 *  Provides a login mechanism for a pre-existing user.
 *
 *  @param name The name of the pre-existing user.
 *
 *  @note Currently this is not supported by the server. Its been added for future enhancement.
 */
- (void)loginWithUserName:(NSString *)name;


/**
 *  Starts the process of calling a remote user with the specified name.
 *
 *  @param remoteUserName The name of the remote user to be called.
 */
- (void)callUserWithName:(NSString *)remoteUserName;

/**
 *  Starts the process of accepting a pending incoming call from the specified remote user.
 *
 *  @param callingUser The remote user who had issued the call request.
 */
- (void)acceptIncomingCallFromUser:(RTCUser *)callingUser;

/**
 *  Rejects the pending incoming call from the specified remote user.
 *
 *  @param callingUser The remote user who had issued the call request.
 */
- (void)rejectIncomingCallFromUser:(RTCUser *)callingUser;

/**
 *  Disconnects an active call (if any) from the specified remote user.
 *
 *  @param remoteUser The remote user involved in the unicast session.
 */
- (void)disconnectCallToUser:(RTCUser *)remoteUser;

@end
