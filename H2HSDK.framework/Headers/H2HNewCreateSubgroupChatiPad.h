//
//  H2HNewCreateSubgroupChatiPad.h
//  H2H
//
//  Created by pratima ghadage on 16/09/16.
//  Copyright © 2016 Tutor Group. All rights reserved.
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
@end


@interface H2HNewCreateSubgroupChatiPad : UIViewController

@property (strong, atomic) NSArray * arrayAvailableUsers;
@property (weak, nonatomic) id<H2HNewChatViewControllerDelegate> delegate;

@end
