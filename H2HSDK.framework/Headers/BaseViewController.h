//
//  BaseViewController.h
//  H2H
//
//  Created by Sagar Kasture on 14/01/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface BaseViewController : UIViewController
/*!
 * @discussion Method to reload the collection.
 */
-(void) reloadCollection;

/*!
 * @discussion Method to scroll to last tile of collection.
 */
-(void)scrollCollectionViewToLastTile;

/*!
 * @discussion Method to display enabled/disabled Video
 * @param enable is a boolean if YES, set the video control in enabled state.
 */
-(void) enableVideo:(BOOL)enable;

/*!
 * @discussion Method to display enabled/disabled Audio.
 * @param enable is a boolean if YES, set the audio control in enabled state.
 */
-(void) enableAudio:(BOOL)enable;

/*!
 * @discussion Method to change Visibility state of chat Badge Icon
 * @param Vissible is a boolean if YES.
 */
-(void) setChatBadgeIconVisibility:(BOOL)shouldShow;

-(void) connectedToRoom:(BOOL)connected;
@end
