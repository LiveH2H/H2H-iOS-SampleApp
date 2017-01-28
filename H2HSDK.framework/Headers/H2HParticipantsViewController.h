//
//  H2HParticipantsViewController.h
//  H2H
//
//  Created by pratima ghadage on 25/01/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface H2HParticipantsViewController : UIViewController
typedef enum
{
   MANAGE_PARTICIPANT,
   CHANGE_PRESENTER
}VIEW_TYPE;

@property VIEW_TYPE viewType;

@end
