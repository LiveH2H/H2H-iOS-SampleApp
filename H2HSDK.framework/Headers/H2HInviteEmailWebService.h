//
//  H2HInviteEmailWebService.h
//  H2H
//
//  Created by Kalyani.Chinchane on 28/09/16.
//  Copyright © 2016 Tutor Group. All rights reserved.
//

#import "H2HWebService.h"

@interface H2HInviteEmailWebService : H2HWebService

- (instancetype)initWithMeetingOrigin:(NSString *)meetingOrigin
                         andMeetingID:(NSString *)meetingID
                          forInvitees:(NSArray *)inviteeList;
@end
