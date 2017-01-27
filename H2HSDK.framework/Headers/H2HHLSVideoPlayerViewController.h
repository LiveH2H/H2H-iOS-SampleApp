//
//  H2HHLSVideoPlayerViewController.h
//  H2H
//
//  Created by Anton Ostrovskii on 10/3/16.
//  Copyright © 2016 Tutor Group. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "H2HNewVideoConferenceBaseViewController.h"

@interface H2HHLSVideoPlayerViewController : H2HNewVideoConferenceBaseViewController
-(void)addDummyTileForUser:(NSString*)user;
-(void)removeDummyTile;
@end