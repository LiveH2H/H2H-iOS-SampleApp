//
//  H2HDiagnosticManager.h
//  H2H
//
//  Created by Anton Ostrovskii on 6/25/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface H2HDiagnosticManager : NSObject

+ (H2HDiagnosticManager *)sharedInstance;

- (void)logSystemMessage:(NSString *)message;
- (void)logVideoMessage:(NSString *)message;
- (void)logChatMessage:(NSString *)message;
- (void)logWhiteboardMessage:(NSString *)message;

@end