//
//  H2HVideoParticipantsViewController.h
//  H2H
//
//  Created by Anton Ostrovskii on 6/20/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "H2HVideoParticipantsBaseViewController.h"

@interface H2HVideoParticipantsViewController : H2HVideoParticipantsBaseViewController

@property (strong, nonatomic) UIView *videoSceneHostView;
@property (strong, nonatomic) NSMutableArray *videoContainerViewControllers;

- (void)moveActiveVideoSceneToLeftAnimated:(BOOL)animated;
- (void)moveActiveVideoSceneToRightAnimated:(BOOL)animated;
- (void)moveNewActiveVideoSceneFromLeft:(H2HVideoParticipantsBaseViewController *)videoContainerViewController animated:(BOOL)animated;
- (void)moveNewActiveVideoSceneFromRight:(H2HVideoParticipantsBaseViewController *)videoContainerViewController animated:(BOOL)animated;
- (void)shakeActiveVideoSceneToLeftAnimated:(BOOL)animated;
- (void)shakeActiveVideoSceneToRightAnimated:(BOOL)animated;

@end