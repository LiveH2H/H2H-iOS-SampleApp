//
//  H2HNewBaseViewController.h
//  H2H
//
//  Created by Anton Ostrovskii on 8/24/16.
//  Copyright © 2016 Tutor Group. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface H2HNewBaseViewControllerPad : UIViewController

-(void)setChatBadgeIconVisibility:(BOOL)shouldShow;

-(void) setHandRaiseIconForPermission:(BOOL)isAllowed;
-(void) setChatIconForPermission:(BOOL)isAllowed;
/*!
 * @discussion Method to signify whether all users have joined in the room.
 * @param connected is a boolean if YES, all users have joined in.
 */
-(void) connectedToRoom:(BOOL)connected;

@end