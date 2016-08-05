//
//  RTCUser.h
//  TutorWebRTC
//
//  Created by Piyush Banerjee on 12/23/15.
//  Copyright © 2015 Spring Computing Technologies Pvt. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 *  An RTCUser represents a real world user involved in a call.
 */
@interface RTCUser : NSObject

/**
 *  The name of the user.
 */
@property (readonly, strong) NSString *name;

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



@end
