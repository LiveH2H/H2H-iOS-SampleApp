//
//  H2HSupportManager.h
//  H2H
//
//  Created by Anton Ostrovskii on 7/28/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <Foundation/Foundation.h>

@class H2HSupportManager;

@interface H2HSupportManager : NSObject

+ (H2HSupportManager *)sharedInstance;

- (void)connect;
- (void)disconnect;
- (void)sendLiveChatSupportMessage:(NSString *)message;
- (void)sendLiveChatSupportOfflineMessage:(NSString *)message;
- (void)sendToggleMediaInMeeting :(RTCMediaToggleData*)mediaData
                     withApproval:(NSString*) approval;
- (void)requestLiveChatSupport;
- (void)clientDisconnect;

@property (strong, nonatomic) NSMutableArray *liveChatSupportOfflineMessages;
@property (strong, nonatomic) NSMutableArray *liveChatSupportMessages;
@property (nonatomic, readonly, getter=getLiveChatSupportAvailable) BOOL isLiveChatSupportAvailable;
@property (nonatomic, readonly, getter=getIsLiveChatSupportStartedByAdmin) BOOL isLiveChatSupportStartedByAdmin;

// Sagar :
// We need to change this based on event from admin console server.
@property (nonatomic) BOOL isLiveSupportAdminOnline;

@end