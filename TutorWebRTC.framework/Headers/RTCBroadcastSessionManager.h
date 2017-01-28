//
//  RTCBroadcastSessionManager.h
//  TutorWebRTC
//
//  Created by Piyush Banerjee on 1/14/16.
//  Copyright © 2016 Spring Computing Technologies Pvt. Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "RTCSessionManager.h"


/**
 *  Responsible for managing the entire life-cycle of a one-to-many WebRTC call.
 */
@interface RTCBroadcastSessionManager : RTCSessionManager

/**
 *  The state of the broadcast WebRTC session.
 */
@property (readonly, nonatomic) RTCBroadcastState broadcastState;

/**
 *  The channel containing audio/video tracks of the broadcasting user.
 */
@property (readonly, strong) RTCStream *broadcastStream;


/**
 *  Starts the process of presenting a broadcast session.
 */
- (void)startBroadcastPresentation;

/**
 *  Starts the process of viewing a remote broadcast session.
 */
- (void)startBroadcastViewing;

/**
 *  Stops an active broadcast session.
 */
- (void)stopBroadcast;

@end
