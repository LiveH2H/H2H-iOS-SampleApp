//
//  H2HSwitchViewController.h
//  H2H
//
//  Created by Anton Ostrovskii on 7/25/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface H2HSwitchViewController : UIViewController

@property (nonatomic, setter=setText:, getter=getText) NSString *text;
@property (nonatomic, setter=setOn:, getter=getOn) BOOL isOn;
@property (nonatomic, strong) NSString *metaData;

@end