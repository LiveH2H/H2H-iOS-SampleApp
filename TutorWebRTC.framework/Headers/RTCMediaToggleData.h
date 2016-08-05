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
 *  The user represents the one of the user who has joined the room.
 */
@property (readonly, strong) RTCUser *user;

/**
 *  The isEnabled represents the action required to taken on the media.
 *  Mute or unmute the media stream.
 */
@property (readonly) BOOL isEnabled;

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
                       andUser: (RTCUser *)user;

@end
