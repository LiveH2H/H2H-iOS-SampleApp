//
//  RTCRoom.h
//  TutorWebRTC
//
//  Created by Piyush Banerjee on 1/15/16.
//  Copyright © 2016 Spring Computing Technologies Pvt. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "RTCUser.h"
#import "RTCTranslatorUser.h"

/**
 *  An RTCRoom represents the virtual conference room where multiple users
 *  can have a conference call with each other. Such a conference call
 *  may include optional audio/video sharing by its registered users; i.e the users
 *  present in the room.
 */
@interface RTCRoom : NSObject

/**
 *  The name of the conference room.
 */
@property (readonly, strong) NSString *name;

/**
 *  Number of participants currently have video enabled for.
 */
@property (readwrite, assign) NSInteger enabledCount;

/**
 *  The local user represents the current user of the device,
 *  who has joined the room.
 */
@property (readonly, strong) RTCUser *localUser;

/**
 *  The local user represents the current user of the device,
 *  who has joined the room.
 */
@property (readwrite, strong) RTCUser *screenShareUser;

/**
 *  The list of the remote users present in the room.
 */
@property (readonly, strong) NSArray<RTCUser *> *users;

/**
 *  The list of the translator users present in the room.
 */
@property (readonly, strong) NSArray<RTCTranslatorUser *> *translatorUsers;

/**
 *  Boolean value whether Audio is toggled by Host for local user
 */
@property (readonly) BOOL isAudioToggledByHost;

/**
 *  Boolean value whether Video is toggled by Host for local user
 */
@property (readonly) BOOL isVideoToggledByHost;

/**
 *  Gets the user with the specified username.
 *
 *  @param userName The name of the required user.
 *
 *  @return The required user if found. Else returns @p nil.
 */
- (RTCUser *)userWithName:(NSString *)userName;

/**
 *  Gets the translator user with the specified username.
 *
 *  @param userName The name of the required user.
 *
 *  @return The required translator user if found. Else returns @p nil.
 */
- (RTCTranslatorUser *)translatorUserWithName:(NSString *)userName;
/**
 *  Gets the user who is host.
 *  @return The required host user if found. Else returns @p nil.
 */
- (RTCUser *)getHostUser;
@end
