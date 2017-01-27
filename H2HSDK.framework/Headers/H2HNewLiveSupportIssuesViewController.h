//
//  H2HNewLiveSupportIssuesViewController.h
//  H2H
//
//  Created by Kalyani.Chinchane on 17/08/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "H2HLiveSupportIssue.h"

@interface H2HNewLiveSupportIssuesViewController : UIViewController

//set the enum for selected issue,used to populate the issue list
@property (readwrite,nonatomic) H2HLiveSupportIssue *selectedIssue;

@end
