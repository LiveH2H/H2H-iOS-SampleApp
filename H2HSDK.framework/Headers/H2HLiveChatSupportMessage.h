//
//  H2HLiveChatSupportMessage.h
//  H2H
//
//  Created by Anton Ostrovskii on 8/1/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_OPTIONS(NSUInteger, LiveChatSupportMessageType) {
    LiveChatSupportMessageUser = 0,
    LiveChatSupportMessageAdmin = 1 << 0,
    LiveChatSupportMessagePresence = 2 <<0
};

@interface H2HLiveChatSupportMessage : NSObject

@property (nonatomic) LiveChatSupportMessageType messageType;
@property (strong, nonatomic) NSString *messageText;
@property (strong,nonatomic) NSString *userName;

- (id)initWithText:(NSString *)text andType:(LiveChatSupportMessageType)type;

- (id)initWithText:(NSString *)text andType:(LiveChatSupportMessageType)type andUserName:(NSString *)userName;

@end