//
//  H2HNewInviteeTableViewCell.h
//  H2H
//
//  Created by Riddhi Joshi on 30/09/16.
//  Copyright © 2016 Tutor Group. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "H2HInviteeModel.h"

@interface H2HNewInviteeTableViewCell : UITableViewCell

//Method to set Invitee Details
-(void)setInviteeDataFor:(H2HInviteeModel *)invitee;

@end
