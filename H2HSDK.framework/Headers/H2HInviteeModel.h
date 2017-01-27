//
//  H2HInviteeModel.h
//  H2H
//
//  Created by Riddhi Joshi on 19/09/16.
//  Copyright © 2016 Tutor Group. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "H2HParticipantModel.h"
#import "AppConstants.h"

@interface H2HInviteeModel : H2HParticipantModel

@property NSString *emailId;
@property InviteeState state;
@property NSDate *timeInviteeLeft;

@end
