//
//  H2HNewRecordMeetingTableViewCell.h
//  H2H
//
//  Created by Kalyani.Chinchane on 30/08/16.
//  Copyright © 2016 Tutor Group. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol  H2HNewMeetIDRecordDelegate <NSObject>

- (void)didClickOnRecordButton;

@end

@interface H2HNewRecordMeetingTableViewCell : UITableViewCell
@property (weak, nonatomic) IBOutlet UILabel *labelTitle;
@property (weak, nonatomic) IBOutlet UILabel *labelSubTitle;
@property (weak, nonatomic) IBOutlet UIButton *buttonRecord;
@property id delegate;
@end
