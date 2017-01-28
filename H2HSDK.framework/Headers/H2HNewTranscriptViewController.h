//
//  H2HNewTranscriptViewController.h
//  H2H
//
//  Created by Anton Ostrovskii on 8/26/16.
//  Copyright © 2016 Tutor Group. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface H2HNewTranscriptViewController : UIViewController

- (void)showText:(NSString *)text;
- (void)showText:(NSString *)text duration:(NSTimeInterval)duration;
- (void)hideViewAnimated:(BOOL)animated;

@end