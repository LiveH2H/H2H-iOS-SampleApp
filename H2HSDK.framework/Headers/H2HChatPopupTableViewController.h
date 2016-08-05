//
//  H2HChatPopupTableViewController.h
//  H2H
//
//  Created by FauadAnwar on 22/03/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <H2HChatClient/H2HChatMessageModel.h>
/**
 *  @brief To handle cell selection.
 */
@protocol H2HChatPopupTableViewControllerDelegate <NSObject>

@required
/**
 *  @brief Call back when user select chat from list.
 *
 *  @param selectedChat H2HChatMessageModel Selected chat object.
 */
- (void)switchChatWithSelectedChat:(H2HChatMessageModel *)selectedChat;

@end

@interface H2HChatPopupTableViewController : UIViewController
/**
 *  @brief delegate object will receive chat selection call back.
 */
@property (weak, nonatomic) id<H2HChatPopupTableViewControllerDelegate> delegate;
@property (strong, atomic) NSArray * arrayChatList;
@property (assign, atomic)NSInteger selectedIndex;
-(void)reloadTableView;
@end
