//
//  H2HVideoParticipantsStackViewController.h
//  DevMeetingView
//
//  Created by Anton Ostrovskii on 3/18/16.
//  Copyright © 2016 TutorGroup. All rights reserved.
//

#import "H2HVideoParticipantsBaseViewController.h"

@class H2HVideoParticipantsStackViewController;

@protocol H2HVideoParticipantsStackViewDelegate <NSObject>
@required
- (void)didTapParticipant:(H2HVideoParticipantViewController *)participant inStackView:(H2HVideoParticipantsStackViewController *)sender;
@end

@interface H2HVideoParticipantsStackViewController : H2HVideoParticipantsBaseViewController

@property (weak, nonatomic) id<H2HVideoParticipantsStackViewDelegate> delegate;

@end