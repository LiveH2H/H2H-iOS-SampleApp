//
//  H2HPhoneSwitchChatViewController.h
//  H2H
//
//  Created by Madhura Sudhir Marathe on 20/08/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <H2HChatClient/H2HError.h>
#import <H2HChatClient/H2HChatClient.h>
#import <H2HChatClient/H2HChatMessageModel.h>

/**
 *  @brief To handle cell selection.
 */
@protocol H2HSwictChatTableViewDelegate <NSObject>

@required
/**
 *  @brief Call back when user select chat from list.
 *
 *  @param selectedChat H2HChatMessageModel Selected chat object.
 */
- (void)switchChatWithSelectedChat:(H2HChatMessageModel *)selectedChat;

@end

@interface H2HPhoneSwitchChatViewController : UIViewController
/**
 *  @brief delegate object will receive chat selection call back.
 */
@property (weak, nonatomic) id<H2HSwictChatTableViewDelegate> delegate;
@property (assign, atomic)NSInteger selectedIndex;

@property (nonatomic,strong) NSMutableArray *ongoingChatList;

@end
