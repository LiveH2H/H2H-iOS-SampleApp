//
//  H2HChatTableViewCell.h
//  H2H
//
//  Created by Sagar Kasture on 10/03/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <H2HChatClient/H2HChatUser.h>


@interface H2HChatTableViewCell : UITableViewCell

@property (assign) CGFloat backgroundViewMargin;

- (void) updateCellContentWithMessage: (NSString*) message
                      withMessageType: (H2H_MESSAGE_TYPE) messageType
                              forUser: (H2HChatUser*) user;

@end
