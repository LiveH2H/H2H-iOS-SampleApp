//
//  H2HLaunchParamsMeetingParticipant.h
//  H2H
//
//  Created by Sagar Kasture on 04/05/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "H2HLaunchParamsAttendeeRole.h"
#import "H2HLaunchParamsServerConfig.h"
#import "H2HLaunchParamsJoinDetails.h"

@interface H2HLaunchParamsMeetingParticipantTranslator : NSObject
@property (nonatomic, copy)     NSString*   languageCode;
@property (nonatomic, copy)     NSString*   language;
@end

@interface H2HLaunchParamsMeetingParticipant : NSObject

@property (nonatomic, assign)   NSInteger   ID;
@property (nonatomic, assign)   NSInteger   participationMinutes;

@property (nonatomic, copy)     NSString*   displayName;
@property (nonatomic, copy)     NSString*   joinTime;
@property (nonatomic, copy)     NSString*   leaveReason;
@property (nonatomic, copy)     NSString*   leaveTime;
@property (nonatomic, copy)     NSString*   role;
@property (nonatomic, copy)     NSString*   status;
@property (nonatomic, copy)     NSString*   token;
@property (nonatomic, copy)     NSArray*    roles;

@property (nonatomic)           H2HLaunchParamsServerConfig *serverConfig;
@property (nonatomic)           H2HLaunchParamsMeetingParticipantTranslator*   translator;
@property (nonatomic)           H2HLaunchParamsJoinDetails *joinDetails;

@end