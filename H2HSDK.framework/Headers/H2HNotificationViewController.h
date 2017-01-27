//
//  H2HNotificationViewController.h
//  H2H
//
//  Created by Anton Ostrovskii on 7/29/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface H2HNotificationViewController : UIViewController

- (void)showNotification:(NSString *)message inView:(UIView *)parentView animated:(BOOL)animated;
- (void)hideNotificationAnimated:(BOOL)animated;

+ (void)showNotification:(NSString *)message inView:(UIView *)parentView animated:(BOOL)animated;

@end