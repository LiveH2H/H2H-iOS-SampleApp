//
//  H2HParticipantModel.h
//  H2H
//
//  Created by pratima ghadage on 25/01/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, PARTICIPANT_BUTTON_STATE)
{
    PARTICIPANT_BUTTON_STATE_ENABLED,
    PARTICIPANT_BUTTON_STATE_DISABLED,
    PARTICIPANT_BUTTON_STATE_NOT_ALLOWED_ENABLED,
    PARTICIPANT_BUTTON_STATE_NOT_ALLOWED_DISABLED,
};

@interface H2HParticipantModel : NSObject

@property NSString* participantName;
@property PARTICIPANT_BUTTON_STATE audioState;
@property PARTICIPANT_BUTTON_STATE videoState;
@property PARTICIPANT_BUTTON_STATE whiteboardState;
@property (copy) NSString* role;
@property BOOL isParticipantSelected;

@end
