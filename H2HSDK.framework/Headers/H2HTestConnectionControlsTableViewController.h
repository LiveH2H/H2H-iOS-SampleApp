//
//  H2HTestConnectionControlsTableViewController.h
//  H2H
//
//  Created by Riddhi Joshi on 17/01/17.
//  Copyright © 2017 Tutor Group. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol H2HTestConnectionCompletionDelegate <NSObject>

-(void)testConnectionCompleted;
-(void)testConnectionFailed;

@end

@interface H2HTestConnectionControlsTableViewController : UITableViewController

@property (nonatomic, weak) id <H2HTestConnectionCompletionDelegate> delegate;

@end
