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
#import "RTCTestConnectionData.h"



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
 *  The attendee user in the current broadcast or webinar session whose audio/video is active.If no attendeeUser arrived it will be @p nil.
 */
@property (readwrite, strong) RTCUser *attendeeUser;
/**
 *  The mediaDataForBroadcast is RTCMediaToggleData that is received from server for attendee for broadcast meeting type.
 */
@property (readwrite, strong) RTCMediaToggleData *mediaDataForBroadcast;

/**
 *  The mediaDataForWebinar is RTCMediaToggleData that is received from server for attendee for webinar meeting type.
 */
@property (readwrite, strong) RTCMediaToggleData *mediaDataForWebinar;

@property (nonatomic, copy) NSString* connectionCheckStr;

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

-(void) checkWithRoom:(NSString*)roomName
          andUserName:(NSString*)userName;

/**
 *  Starts the process of joining a room with the specified room-name
 *  and register with the specified user-name.
 *
 *  @param roomName The name of the room to join.
 *  @param userName The user-name to use for registration.
 *  @param role The Role of the user whether he is host or participant.
 *  @param languageCode LanguageCode of the transcript
 */
- (void)joinRoom: (NSString *)roomName
    withUserName: (NSString *)userName
         andRole: (NSString *)role
withTranscriptLanguage:(NSString *)languageCode;


/**
 *  Starts the process of leaving the room and discards the multicast session.
 *
 *  @param room The room to leave.
 */
- (void)leaveRoom:(RTCRoom *)room
  withLeaveReason:(NSString*)leaveReason;

/**
 *  Enables or disables the media for participant when host
 *
 *  @param isEnabled   The action to be taken YES/NO.
 *  @param userName    The user for whom media is to enabled/disabled.
 *  @param mediaType   The media to enable/disable.
 */
- (void)setEnabled: (BOOL)isEnabled
    forParticipant: (NSString *)userName
      forMediaType: (MediaType)mediaType
     andMediaState: (ToggleState) state;


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

/**
 *  Sets property in room that video is toggle by host
 *
 */
-(void)setVideoToggledByHost;

/**
 *  Sets property in room that audio is toggle by host
 *
 */
-(void)setAudioToggledByHost;

/**
 *  notifies server to update raise hand permissions
 *
 *  @param permission is BOOL 
 *  @param type is TogglePermissionType that is chat or hand raise
 *
 */
- (void)notifyBroadcastTogglePermission:(BOOL) permission forType:(TogglePermissionType) type;

/**
 *  Notifies server to start/stop recording the meeting
 *
 *  @param action is BOOL
 */
- (void)notifyActionForRecording:(BOOL) action;
/**
 *  Notifies server toggle media is denied
 *
 *  @param mediaData is RTCMediaToggleData
 */
- (void)sendToggleMediaDenied:(RTCMediaToggleData *)mediaData;
/**
 *  Enables or disables the video without sending the toggleMediaSuccessful json
 *
 *  @param toggleData   The toggle data.
 *  @param isChangesForLocalUser to identify if the change is for local user
 */
- (BOOL)toggleVideoWithMediaData:(RTCMediaToggleData *)toggleData andIsChangesForLocalUser: (BOOL)isChangesForLocalUser
;
/**
 *  Enables or disables the audio without sending the toggleMediaSuccessful json
 *
 *  @param toggleData   The toggle data.
 *  @param isChangesForLocalUser to identify if the change is for local user
 */
- (BOOL)toggleAudioWithMediaData:(RTCMediaToggleData *)toggleData andIsChangesForLocalUser: (BOOL)isChangesForLocalUser
;
/**
 *  Notifies server media popup action accepted
 *
 *  @param mediaData is RTCMediaToggleData
 */
- (void)initiateMediaPopupActionForBroadcastWith:(RTCMediaToggleData *)mediaData;
/**
 *  Notifies server Attendee rejected serve hand
 *
 */
- (void) notifyAttendeeRejectedServeHand;
/**
 *  Updates permission dictionary and notifies UI 
 *
 *  @param toggleData   The toggle data.
 *  @param isChangesForLocalUser to identify if the change is for local user
 */

- (void) updatePermissionsforMediaData:(RTCMediaToggleData *)toggleData andIsChangesForLocalUser: (BOOL)isChangesForLocalUser;

@end