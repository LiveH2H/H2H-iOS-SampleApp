//
//  H2HNewMeetingIDDropDownViewController.h
//  H2H
//
//  Created by Kalyani.Chinchane on 30/08/16.
//  Copyright © 2016 Tutor Group. All rights reserved.
//

#import <UIKit/UIKit.h>
@protocol H2HNewMeetingIDDropDownViewDelegate <NSObject>

- (void)handleInviteByEmailActionForMeetingIDDropDownView;
- (void)showActivityController:(UIActivityViewController *)activity;
@end

@interface H2HNewMeetingIDDropDownViewController : UIViewController
@property (nonatomic, weak) id <H2HNewMeetingIDDropDownViewDelegate> delegate;

@end
