//
//  H2HChatViewController.h
//  H2H
//
//  Created by Sagar Kasture on 08/03/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface H2HChatViewController : UIViewController
-(void) replayToMessage;
- (void)replyToMessageWithText:(NSString *)text;
- (void) markReadForCurrentChat;
@end
