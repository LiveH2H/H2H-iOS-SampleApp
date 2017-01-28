//
//  H2HParticipantsViewController.h
//  H2H
//
//  Created by pratima ghadage on 25/01/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol H2HNewParticipantsViewDelegate <NSObject>

- (void)handleInviteByEmailAction;
- (void)showAlert:(UIAlertController*)alertController;

@end

@interface H2HNewParticipantsViewController : UIViewController

@property (nonatomic, weak) id <H2HNewParticipantsViewDelegate> delegate;

@end
