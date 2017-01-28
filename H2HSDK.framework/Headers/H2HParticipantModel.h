//
//  H2HParticipantModel.h
//  H2H
//
//  Created by pratima ghadage on 25/01/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TutorWebRTC/RTCSessionManagerConstants.h>

@interface H2HParticipantModel : NSObject

@property NSString* participantName;
@property MediaToggleState audioState;
@property MediaToggleState videoState;
@property MediaToggleState whiteboardState;
@property (copy) NSString* role;
@property BOOL isParticipantSelected;
@property BOOL ishandRaised;

@end
