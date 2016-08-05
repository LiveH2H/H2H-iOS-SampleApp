//
//  H2HVideoParticipantsBaseViewController.h
//  DevMeetingView
//
//  Created by Anton Ostrovskii on 3/17/16.
//  Copyright © 2016 TutorGroup. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "H2HVideoParticipantViewController.h"

@interface H2HVideoParticipantsBaseViewController : UIViewController

@property (strong, nonatomic) NSLayoutConstraint *leftConstraint;
@property (strong, nonatomic) NSLayoutConstraint *topConstraint;
@property (strong, nonatomic) NSLayoutConstraint *rightConstraint;
@property (strong, nonatomic) NSLayoutConstraint *bottomConstraint;
@property (strong, nonatomic) NSLayoutConstraint *widthConstraint;

@property (strong, nonatomic) NSMutableArray *participants;

- (void)setParticipants:(NSMutableArray *)participants animated:(BOOL)animated;
- (void)addParticipant:(H2HVideoParticipantViewController *)participant animated:(BOOL)animated;
- (void)removeParticipant:(H2HVideoParticipantViewController *)participant animated:(BOOL)animated;
- (void)layoutParticipantsAnimated:(BOOL)animated;
- (void)layoutParticipants;
- (void)sortParticipants;

@end