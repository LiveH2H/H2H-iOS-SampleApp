//
//  H2HNewContactManager.h
//  H2H
//
//  Created by Kalyani.Chinchane on 19/08/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol H2HNewContactManagerDelegate <NSObject>

- (void)showRequiredContactViewController:(UIViewController *)viewController;
- (void)dismissPresentedView:(UIViewController *)viewController;
- (void)showAlertController:(UIAlertController *)alertController;

@end

@interface H2HNewContactManager : NSObject

@property (nonatomic, weak) id <H2HNewContactManagerDelegate> delegate;

- (void) contactScan;
- (NSString *)getMeetingIDLink;

@end
