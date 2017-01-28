//
//  H2HNewDeviceSettingViewController.h
//  H2H
//
//  Created by pratima ghadage on 17/08/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface H2HNewDeviceSettingViewController : UIViewController
typedef enum : NSInteger
{
    DEVICE_SETTING_MICROPHONE=0,//Detail Cell
    DEVICE_SETTING_CAMERA
}DeviceSettingCellIndex;
@end
