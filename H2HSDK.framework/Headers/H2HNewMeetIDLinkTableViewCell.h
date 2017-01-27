//
//  H2HNewMeetIDLinkTableViewCell.h
//  H2H
//
//  Created by Kalyani.Chinchane on 30/08/16.
//  Copyright © 2016 Tutor Group. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol  H2HNewMeetIDLinkDelegate <NSObject>

- (void)didClickOnCopyLinkButton;
- (void)didClickOnInviteButton;

@end



@interface H2HNewMeetIDLinkTableViewCell : UITableViewCell

@property (weak, nonatomic) IBOutlet UILabel *labelTitle;
@property (weak, nonatomic) IBOutlet UILabel *labelSubTitle;
@property (weak, nonatomic) IBOutlet UIButton *buttonCopyLink;
@property (weak, nonatomic) IBOutlet UIButton *buttonInvite;
@property id delegate;

@end
