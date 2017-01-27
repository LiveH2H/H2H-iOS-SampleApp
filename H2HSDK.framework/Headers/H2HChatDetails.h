//
//  H2HChatDetails.h
//  H2H
//
//  Created by Madhura Sudhir Marathe on 26/08/16.
//  Copyright © 2016 Tutor Group. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <H2HChatClient/H2HChatUser.h>
#import "H2HBasicUtility.h"

@interface H2HChatDetails : NSObject

@property (strong,nonatomic) NSString* message;
@property (nonatomic) H2H_MESSAGE_TYPE messageType;
@property (nonatomic) H2HChatUser* user;
@property (nonatomic) ChatMode chatMode;
@property (nonatomic,strong) NSMutableArray *chatMessages;

@end
