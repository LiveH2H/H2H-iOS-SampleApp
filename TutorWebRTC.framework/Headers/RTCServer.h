//
//  RTCServer.h
//  TutorWebRTC
//
//  Created by Kalyani.Chinchane on 28/04/16.
//  Copyright © 2016 Spring Computing Technologies Pvt. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RTCServer : NSObject

/**
 *  The URL of the server.
 */
@property (readonly, strong) NSURL *url;

/**
 *  The username for authentication.
 */
@property (readonly, strong) NSString *username;

/**
 *  The password for authentication.
 */
@property (readonly, strong) NSString *password;


/**
 *  Initializes an instance of RTCServer with the server URL.
 *
 *  @param serverURL The URL of the signaling server.
 *
 *  @return An instance of RTCServer or @p nil.
 */
- (instancetype)initWithURL:(NSURL *)serverURL
                andUserName:(NSString *)username
                andPassword:(NSString*)password;


@end
