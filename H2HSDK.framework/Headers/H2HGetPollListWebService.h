//
//  H2HGetPollListWebService.h
//  H2H
//
//  Created by charuta.rajopadhye on 12/10/16.
//  Copyright © 2016 Tutor Group. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "H2HWebService.h"

@interface H2HGetPollListWebService : H2HWebService

- (instancetype)initWithMeetingID: (NSString *) meetingID;

@end
