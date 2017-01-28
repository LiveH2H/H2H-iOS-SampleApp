//
//  RTCCommunicationChannel.h
//  TutorWebRTC
//
//  Created by Piyush Banerjee on 12/21/15.
//  Copyright © 2015 Spring Computing Technologies Pvt. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Utilities/JSONSerializableObject.h>

typedef NS_ENUM(NSInteger, RTCSignalingChannelState) {
    
    RTCSignalingChannelStateDisconnected,
    RTCSignalingChannelStateConnecting,
    RTCSignalingChannelStateConnected
};


@class RTCSignalingChannel;

@protocol RTCSignalingChannelDelegate <NSObject>

- (void)channel: (RTCSignalingChannel *)channel
 didChangeState: (RTCSignalingChannelState)state
      withError: (NSError *)error
    andUserInfo: (NSDictionary *)userInfo;

-   (void)channel: (RTCSignalingChannel *)channel
didReceiveMessage: (id)message
        withError: (NSError *)error
      andUserInfo: (NSDictionary *)userInfo;

@end


@interface RTCSignalingChannel : NSObject

@property (assign) BOOL shouldUseHTTP;

@property (readonly, nonatomic) RTCSignalingChannelState state;

@property (readonly, strong) NSURL *serverURL;

@property (readonly, weak) id<RTCSignalingChannelDelegate> delegate;

- (instancetype)initWithServerURL: (NSURL *)serverURL
                      andDelegate: (id<RTCSignalingChannelDelegate>)delegate;

- (void)connect;

- (BOOL)write:(id<JSONSerializable>)dataObject;

- (BOOL)writeJSONString:(NSString *)jsonString;

- (void)disconnect;

@end
