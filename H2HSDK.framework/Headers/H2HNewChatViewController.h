//
//  H2HNewChatViewController.h
//  H2H
//
//  Created by FauadAnwar on 16/03/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 *  @brief To handle cell selection.
 */
@protocol H2HNewChatViewControllerDelegate <NSObject>

@required
/**
 *  @brief Call back when user select create chat button.
 *
 *  @param usersArray NSMutableArray array of selected users.
 */
- (void)createNewChatWithUsers:(NSMutableArray *)usersArray andMessage:(NSString*) messageSent;

/**
 *  @brief Call back when user select textview.
 *
 */
- (BOOL)textViewSelected;
@end

@interface H2HNewChatViewController : UIViewController

/**
 *  @brief delegate object will receive create chat button click call back.
 */
@property (weak, nonatomic) id<H2HNewChatViewControllerDelegate> delegate;
@property (strong, atomic) NSArray * arrayAvailableUsers;

@property (weak, nonatomic) NSLayoutConstraint *constraintBottomMargin;

@end
