//
//  H2HVideoConferenceViewController.h
//  DevMeetingView
//
//  Created by Anton Ostrovskii on 3/10/16.
//  Copyright © 2016 TutorGroup. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "H2HVideoParticipantsBaseViewController.h"

typedef NS_OPTIONS(NSUInteger, VideoConferenceViewMode) {
    VideoConferenceViewModeStandard = 0,
    VideoConferenceViewModeExpanded = 1 << 0,
    VideoConferenceViewModePhone = 1 << 1,
    //BEGIN - Changes for adding content view in base view
    VideoConferenceViewModeiPadFullScreeen

    //END - Changes for adding content view in base view

};

@interface H2HVideoConferenceViewController : UIViewController

@property (nonatomic, getter=getViewMode, setter=setViewMode:) VideoConferenceViewMode viewMode;

- (id)initWithViewMode:(VideoConferenceViewMode)viewMode;

@end