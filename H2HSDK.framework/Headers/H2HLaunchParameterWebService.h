//
//  H2HLaunchParameterWebService.h
//  H2H
//
//  Created by Sagar Kasture on 14/04/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import "H2HWebService.h"

@interface H2HLaunchParameterWebService : H2HWebService

- (instancetype)initWithDisplayName:(NSString*)displayName
                       andMeetingID:(NSString*)meetingID;
- (instancetype)initWithToken:(NSString*)token;

@end