//
//  H2HPhoneSwitchChatCell.h
//  H2H
//
//  Created by Madhura Sudhir Marathe on 24/08/16.
//  Copyright © 2016 Tutor Group. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface H2HPhoneSwitchChatCell : UITableViewCell
@property (weak, nonatomic) IBOutlet UILabel *chatNameLabel;
@property (weak, nonatomic) IBOutlet UIButton *editChatListButton;
@property (weak, nonatomic) IBOutlet UILabel *participantsCountLabel;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *constraintEditButtonTrailing;
@end
