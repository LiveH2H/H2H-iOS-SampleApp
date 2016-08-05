//
//  RTCMulticastSessionManager.h
//  TutorWebRTC
//
//  Created by Piyush Banerjee on 1/14/16.
//  Copyright © 2016 Spring Computing Technologies Pvt. Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "RTCSessionManager.h"
#import "RTCRoom.h"


/**
 *  Responsible for managing the entire life-cycle of a group WebRTC call.
 */
@interface RTCMulticastSessionManager : RTCSessionManager

/**
 *  The state of joining the multicast room.
 */
@property (readonly, nonatomic) RTCMulticastRoomState multicastRoomState;

/**
 *  State of the multicast WebRTC session.
 */
@property (readonly, nonatomic) RTCMulticastState multicastState;

/**
 *  The room which is currently joined by the localUser. If no room is joined this will be @p nil.
 */
@property (readonly, strong) RTCRoom *room;


/**
 *  Starts the process of joining a room with the specified room-name
 *  and register with the specified user-name.
 *
 *  @param roomName The name of the room to join.
 *  @param userName The user-name to use for registration.
 */
- (void)joinRoom: (NSString *)roomName
    withUserName: (NSString *)userName;


/**
 *  Starts the process of joining a room with the specified room-name
 *  and register with the specified user-name.
 *
 *  @param roomName The name of the room to join.
 *  @param userName The user-name to use for registration.
 *  @param role The Role of the user whether he is host or participant.
 */

- (void)joinRoom: (NSString *)roomName
    withUserName: (NSString *)userName
         andRole: (NSString *)role;


/**
 *  Starts the process of leaving the room and discards the multicast session.
 *
 *  @param room The room to leave.
 */
- (void)leaveRoom:(RTCRoom *)room;

/**
 *  Enables or disables the media for participant when host
 *
 *  @param isEnabled   The action to be taken YES/NO.
 *  @param userName    The user for whom media is to enabled/disabled.
 *  @param mediaType   The media to enable/disable.
 */
- (void)setEnabled: (BOOL)isEnabled
    forParticipant: (NSString *)userName
      forMediaType: (MediaType)mediaType;


- (void)setEnabledWhiteboard:(BOOL)isEnabled
              forParticipant: (NSString *)userName
                forMeetingID: (NSString *)meetingID;


/**
 *  Adds required translator to the room.
 *
 *  @param translatorUser The translator user selected by local user.It is an instance of RTCTranslatorUser.
 */
- (void)addTranslator:(RTCTranslatorUser *)translatorUser;

/**
 *  Removes required translator from the room.
 *
 */
- (void)removeTranslator;

- (void)raiseHand;


/**
 *  Sends request to kick user from the meeting (only host can perform this request)
 *  
 *  @param user    User who should be kicked out
 */
- (void)removeUser:(NSString *)user;

@end