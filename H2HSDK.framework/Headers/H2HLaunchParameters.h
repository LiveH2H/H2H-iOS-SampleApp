//
//  H2HLaunchParameters.h
//  H2H
//
//  Created by Sagar Kasture on 14/04/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "H2HLaunchParamsUser.h"
#import "H2HLaunchParamsMeeeting.h"
#import "H2HLaunchParamsMeetingParticipant.h"

@interface H2HLaunchParameters : NSObject

@property (nonatomic, copy) NSString*                           apiVersion;
@property (nonatomic)       H2HLaunchParamsUser*                user;
@property (nonatomic)       H2HLaunchParamsMeeeting*            meeting;
@property (nonatomic)       H2HLaunchParamsMeetingParticipant*  participant;

@property (nonatomic, copy) NSString* meetingID;
@property (nonatomic, copy) NSString* meetingIDWithoutOrigin;
@property (nonatomic, readonly, getter=getMeetingIdUserFriendly) NSString *meetingIdUserFriendly;
@property (nonatomic, copy) NSArray* whiteboards;

@end