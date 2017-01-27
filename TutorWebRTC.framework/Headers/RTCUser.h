//
//  RTCUser.h
//  TutorWebRTC
//
//  Created by Piyush Banerjee on 12/23/15.
//  Copyright © 2015 Spring Computing Technologies Pvt. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RTCUserNetworkStatus.h"

#define SCREEN_SHARE_SUFFIX @"_screenShare"

/**
 *  An RTCUser represents a real world user involved in a call.
 */
@interface RTCUser : NSObject

/**
 *  The name of the user.
 */
@property (readonly, strong) NSString *name;

/**
 *  The email of the user.
 */
@property (readonly, strong) NSString *email;

/**
 *  The stream containing audio/video tracks corresponding to the user.
 */
@property (readonly, strong) RTCStream *stream;

/**
 *  Role of this user.
 */
@property (readonly, strong) NSString *role;

/**
 *  Permissions for user.
 */
@property (readonly, copy) NSDictionary *permissions;

/**
 *  Whiteboard state of this user.
 */
@property (readwrite ) BOOL isWhiteboardEnabled;

/**
 *  Video state of this user.
 */
@property (readwrite ) BOOL isVideoEnabled;

/**
 *  Audio state of this user.
 */
@property (readwrite ) BOOL isAudioEnabled;

@property (readwrite) RTCUserNetworkStatus *localNetworkStatus;

//Dictionary with user name as key and value as object of type RTCUserNetworkStatus
@property (readwrite) NSMutableDictionary *remoteNetworkStatus;

@property ToggleState toggleState;

@property (readwrite) BOOL isAttendee;

/**
 *  The flag is used to identify if peerconnection created is of send recv kind. Since when participant joins webinar meeting, that time peer creatd will be only recv kind for the particiapnt but when particiapnt becomes an attendee then the peer needs to be replaced with sendrecv peer now.
 */
@property (readwrite) BOOL isReceivePeerCreatedForAttendee;

@end