//
//  H2HPhoneToolbarManager.h
//  H2H
//
//  Created by Riddhi Joshi on 29/08/16.
//  Copyright © 2016 Tutor Group. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "H2HPhoneToolbarViewController.h"

@interface H2HPhoneToolbarManager : NSObject

+(H2HPhoneToolbarManager *)sharedToolbarManager;

-(H2HPhoneToolbarViewController *)getToolBar;

-(void)destroyToolbar;

@end