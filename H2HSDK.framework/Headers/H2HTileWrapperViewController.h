//
//  H2HTileWrapperViewController.h
//  H2H
//
//  Created by Anton Ostrovskii on 9/5/16.
//  Copyright © 2016 Tutor Group. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum {
    H2HTileWrapperTileTypeUnknown,
    H2HTileWrapperTileTypeVideo,
    H2HTileWrapperTileTypeChat,
    H2HTileWrapperTileTypeWhiteboard
} H2HTileWrapperTileType;

typedef enum {
    H2HTileWrapperTileStateUnknown,
    H2HTileWrapperTileStateLeftTop,
    H2HTileWrapperTileStateLeftBottom,
    H2HTileWrapperTileStateRight,
    H2HTileWrapperTileStateFullScreen
} H2HTileWrapperTileState;

@class H2HTileWrapperViewController;

@protocol H2HTileWrapperViewControllerDelegate <NSObject>
@required
- (void)setRightStateForTile:(H2HTileWrapperViewController *)sender;
- (void)setFullScreenStateForTile:(H2HTileWrapperViewController *)sender;
@end

@interface H2HTileWrapperViewController : UIViewController

@property (weak, nonatomic, getter=getViewController, setter=setViewController:) UIViewController *viewController;
@property (nonatomic, getter=getTileType, setter=setTileType:) H2HTileWrapperTileType tileType;
@property (nonatomic, getter=getTileState, setter=setTileState:) H2HTileWrapperTileState tileState;
@property (nonatomic, assign) BOOL disableFeature;

@property (weak, nonatomic) id<H2HTileWrapperViewControllerDelegate> delegate;

- (id)initWithViewController:(UIViewController *)viewController tileType:(H2HTileWrapperTileType)tileType tileState:(H2HTileWrapperTileState)tileState delegate:(id<H2HTileWrapperViewControllerDelegate>)delegate;

@end
