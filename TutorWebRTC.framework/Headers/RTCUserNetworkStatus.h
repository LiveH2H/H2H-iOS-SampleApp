//
//  RTCUserNetworkStatus.h
//  TutorWebRTC
//
//  Created by pratima ghadage on 25/07/16.
//  Copyright © 2016 Spring Computing Technologies Pvt. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RTCUserNetworkStatus : NSObject

typedef NS_ENUM(NSInteger, RTCNetworkStatus) {
    RTCNetworkStatusGood,
    RTCNetworkStatusOk,
    RTCNetworkStatusBad,
    RTCNetworkStatusUnknown
};

@property NSInteger outVideoDroppedFrames;

//Number of audio packets lost
@property NSInteger audioPacketsLost;
//Number of video packets lost
@property NSInteger vidoeoPacketsLost;

@property NSInteger audioRtt;
@property NSInteger videoRtt;

// picture loss count
@property NSInteger pliCount;

@property double videoJitter;
@property double audioJitter;

//Audio bit rate in  kbits/sec
@property double audioBitrate;
//Video bit rate in  kbits/sec
@property double videoBitrate;

@property RTCNetworkStatus networkStatus;

-(NSString *) getNetworkStatusInfo;

// contains the entire dictionary as it is, recieved from the server
// with entire set of keys and values.
@property (nonatomic) NSDictionary* dictNetworkStatusFromServer;

@end
