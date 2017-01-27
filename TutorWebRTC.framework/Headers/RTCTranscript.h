//
//  RTCTranscript.h
//  TutorWebRTC
//
//  Created by atul.ghorpade on 24/08/16.
//  Copyright © 2016 Spring Computing Technologies Pvt. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RTCTranscript : NSObject

@property (nonatomic, readonly) NSString *message;
@property (nonatomic, readonly) NSString *userName;
@property (nonatomic, readonly) NSError *error;

-(id)initWithUserName:(NSString *)userName andMessage:(NSString *)message andError:(NSError *)error;

@end
