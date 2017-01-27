//
//  H2HSupportRequestViewController.h
//  H2H
//
//  Created by Anton Ostrovskii on 7/22/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <UIKit/UIKit.h>

@class H2HSupportRequestViewController;

@protocol H2HSupportRequestViewControllerDelegate <NSObject>
@required
- (void)closedSupportRequestSupport:(H2HSupportRequestViewController *)sender;
@end

@interface H2HSupportRequestViewController : UIViewController <UITextViewDelegate>

@property (weak, nonatomic) id<H2HSupportRequestViewControllerDelegate> delegate;

@end