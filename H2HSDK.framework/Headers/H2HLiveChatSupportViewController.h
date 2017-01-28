//
//  H2HLiveChatSupportViewController.h
//  H2H
//
//  Created by Anton Ostrovskii on 7/27/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <UIKit/UIKit.h>

@class H2HLiveChatSupportViewController;

@protocol H2HLiveChatSupportViewControllerDelegate <NSObject>
@required
- (void)closeLiveChatSupport:(H2HLiveChatSupportViewController *)sender;
@end

@interface H2HLiveChatSupportViewController : UIViewController <UITableViewDelegate, UITableViewDataSource, UITextFieldDelegate>

@property (nonatomic, setter=setPresenting:, getter=getPresenting) BOOL isPresenting;
@property (weak, nonatomic) id<H2HLiveChatSupportViewControllerDelegate> delegate;

@end