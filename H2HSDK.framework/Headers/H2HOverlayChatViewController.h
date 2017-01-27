//
//  H2HOverlayChatViewController.h
//  H2H
//
//  Created by Madhura Sudhir Marathe on 30/08/16.
//  Copyright © 2016 Tutor Group. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "H2HChatViewController.h"

@interface H2HOverlayChatViewController : UIViewController
@property (weak, nonatomic) IBOutlet UIView *overlayContainerView;
@property (weak, nonatomic) IBOutlet UIButton *doneButton;
@property (nonatomic,strong) H2HChatViewController *vcChat;
@property(nonatomic,strong) UINavigationController *overlayNavigationController;

- (IBAction)doneButtonAction:(id)sender;
@end
