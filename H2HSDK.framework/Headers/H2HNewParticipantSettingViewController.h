//
//  H2HNewParticipantSettingViewController.h
//  H2H
//
//  Created by pratima ghadage on 12/08/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface H2HNewParticipantSettingViewController : UIViewController
typedef enum : NSInteger
{
    PARTICIPANT_SETTING_MICROPHONE,
    PARTICIPANT_SETTING_CAMERA_DISPLAY,
    PARTICIPANT_SETTING_PARTICIPANT_NAME
}ParticipantSettingCellIndex;
@end
