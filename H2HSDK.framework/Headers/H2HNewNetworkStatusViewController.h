//
//  H2HNetworkStatusViewController.h
//  H2H
//
//  Created by charuta.rajopadhye on 25/08/16.
//  Copyright © 2016 Tutor Group. All rights reserved.
//

#import <UIKit/UIKit.h>

#define NETWORK_STATUS_POPUP_WIDTH 270.0f

// the pop up/view controller will display either
// 1. Waiting for Statistics message or
// 2. Network Statistics
// whatever is available
// check in the dictionary which of the following key is available
// and display data in the table view accordingly
typedef enum : NSUInteger
{
    INFO_NETWORK_STATISTICS,
    INFO_WAITING_MESSAGE
    
} InfoMessage;


@interface H2HNewNetworkStatusViewController : UIViewController

@property NSDictionary* dictionaryNetworkStatusInfo;

-(NSDictionary*) createDataForLocalNetworkStatusDisplay: (RTCUser*) rtcLocalUser;

@end
