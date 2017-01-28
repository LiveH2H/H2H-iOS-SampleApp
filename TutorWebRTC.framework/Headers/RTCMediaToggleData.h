//
//  RTCMediaToggleData.h
//  TutorWebRTC
//
//  Created by Kalyani.Chinchane on 12/05/16.
//  Copyright © 2016 Spring Computing Technologies Pvt. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RTCSessionManagerConstants.h"

/**
 *  An RTCMediaToggleData maintains the data when media is to be enabled/disabled.
 *  The data maintained consist of user, media type and action to be taken.
 */

@interface RTCMediaToggleData : NSObject

/**
 *  The media type.
 */
@property (readonly) MediaType rtcMediaType;

/**
 *  The user represents the username for whom media is to be toggled.
 */
@property (readonly, strong) NSString *user;

/**
 *  The isEnabled represents the action required to taken on the media.
 *  Mute or unmute the media stream.
 */
@property (readonly) BOOL isEnabled;
/**
 *  The toggleState represents isSticky.
 *  ToggleStateEnabledDisabled represents isSticky = True
 *  ToggleStateOnOFF represents isSticky = False
 */
@property ToggleState toggleState;

/**
 *  Role represents the role of user who has toggled the media. Host/admin.
 */
@property NSString *role;

/**
 *  The isAttendee represents if attendee is true for broadcast.
 */
@property (readwrite) BOOL  isAttendee;

/**
 *  The initiator represents user that has toggled a/v for broadcast.
 */
@property (readonly) NSString *initiator;

/**
 *  Gets the RTCMediaToggleData with the specified media type, action and user.
 *
 *  @param mediaType The media type MediaTypeAudio/MediaTypeVideo.
 *
 *  @param isEnabled The action to set enabled the MediaType TRUE/FALSE.
 *
 *  @param user The user for whom the media is to toggled.
 *
 *  @return The instance of RTCMediaToggleData. Else returns @p nil.
 */
- (instancetype) initWithMedia: (MediaType)mediaType
                     andAction: (BOOL) isEnabled
                       andUser: (NSString *)user
                andToggleState: (ToggleState) toggleState;
/**
 *  Gets the RTCMediaToggleData with the specified media type, action and user.
 *
 *  @param mediaType The media type MediaTypeAudio/MediaTypeVideo.
 *
 *  @param isEnabled The action to set enabled the MediaType TRUE/FALSE.
 *
 *  @param user The user for whom the media is to toggled.
 *
 *  @param role The role of user for who has toggled the media.
 *
 *  @return The instance of RTCMediaToggleData. Else returns @p nil.
 */
- (instancetype) initWithMedia: (MediaType)mediaType
                     andAction: (BOOL) isEnabled
                       andUser: (NSString *)user
                andToggleState: (ToggleState) toggleState
                       andRole:(NSString *)role;

/**
 *  Gets the RTCMediaToggleData with the specified media type, action and user.
 *
 *  @param mediaType The media type MediaTypeAudio/MediaTypeVideo.
 *
 *  @param isEnabled The action to set enabled the MediaType TRUE/FALSE.
 *
 *  @param user The user for whom the media is to toggled.
 *
 *  @param role The role of user for who has toggled the media.
 *
 *  @param isAttendee if attendee in boradcast.
 *
 *  @return The instance of RTCMediaToggleData. Else returns @p nil.
 */
- (instancetype) initWithMedia: (MediaType)mediaType
                     andAction: (BOOL) isEnabled
                       andUser: (NSString *)user
                andToggleState: (ToggleState) toggleState
                       andRole:(NSString *)role
                 andIsAttendee:(BOOL) isAttendee
                  andInitiator:(NSString *)initiator;
@end
