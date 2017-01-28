//
//  H2HNewNotificationViewController.h
//  H2H
//
//  Created by Anton Ostrovskii on 8/31/16.
//  Copyright © 2016 Tutor Group. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface H2HNewNotificationViewController : UIViewController

- (void)showNotification:(NSString *)notification
                  inView:(UIView *)view
                animated:(BOOL)animated
            dismissAfter:(NSTimeInterval)delay
         showCloseButton:(BOOL)hasCloseButton
               leftImage:(UIImage *)image
        animateLeftImage:(BOOL)leftImageAnimated
         backgroundColor:(UIColor *)background
               textColor:(UIColor *)textColor;

- (void)hideNotificationAnimated:(BOOL)animated;

+ (void)showNotification:(NSString *)notification
                  inView:(UIView *)view
                animated:(BOOL)animated
            dismissAfter:(NSTimeInterval)delay
         showCloseButton:(BOOL)hasCloseButton
               leftImage:(UIImage *)image
        animateLeftImage:(BOOL)leftImageAnimated
         backgroundColor:(UIColor *)background
               textColor:(UIColor *)textColor;

@end