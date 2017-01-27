//
//  BaseViewControllerPhone.h
//  H2H
//
//  Created by Anton Ostrovskii on 8/3/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface BaseViewControllerPhone : UITabBarController

/*!
 * @discussion Method to display enabled/disabled Audio.
 * @param enable is a boolean if YES, set the audio control in enabled state.
 */
-(void)enableAudio:(BOOL) enable;

/*!
 * @discussion Method to display enabled/disabled Video
 * @param enable is a boolean if YES, set the video control in enabled state.
 */
-(void)enableVideo:(BOOL) enable;

/*!
 * @discussion Method to signify whether all users have joined in the room.
 * @param connected is a boolean if YES, all users have joined in.
 */
-(void)connectedToRoom:(BOOL)connected;

/*!
 * @discussion Method to display chat badge icon
 * @param shouldShow is a boolean if YES, set the chat badge icon.
 */
-(void) setChatBadgeIconVisibility:(BOOL)shouldShow;

/*!
 * @discussion Method to display RaiseHand icon depending on persmission from host.
 * @param isAllowed is a boolean if YES, set the raiseHandIcon accordingly.
 */
-(void) setHandRaiseIconForPermission:(BOOL)isAllowed;

- (UINavigationController *) getNavigationController;

@end