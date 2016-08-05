//
//  MediaStream.h
//  TutorWebRTC
//
//  Created by Piyush Banerjee on 12/28/15.
//  Copyright © 2015 Spring Computing Technologies Pvt. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "RTCStreamConstants.h"

#import "RTCDataTrack.h"
#import "RTCAudioDataTrack.h"
#import "RTCVideoDataTrack.h"

#import "RTCVideoView.h"


/**
 *  An RTCStream represents the channel or stream through which audio/video data is received from a particular user.
 */
@interface RTCStream : NSObject

/**
 *  All available audio tracks in the stream.
 */
@property (strong, readonly) NSArray<RTCAudioDataTrack *> *audioTracks;

/**
 *  All available video tracks in the stream.
 */
@property (strong, readonly) NSArray<RTCVideoDataTrack *> *videoTracks;

@end
