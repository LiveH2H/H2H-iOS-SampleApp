//
//  RTCVideoDataTrack.h
//  TutorWebRTC
//
//  Created by Piyush Banerjee on 1/8/16.
//  Copyright © 2016 Spring Computing Technologies Pvt. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "RTCVideoView.h"
#import "RTCDataTrack.h"


/**
 *  A data stream consisting of video data.
 */
@interface RTCVideoDataTrack : RTCDataTrack

/**
 *  Adds the specified RTCVideoView to the video rendering queue.
 *
 *  @param videoRenderer The RTCVideoView to be used for rendering the video data.
 *
 *  @return Returns @p true if addition was successful. Else returns @p false.
 */
- (BOOL)addRenderer:(RTCVideoView *)videoRenderer;

/**
 *  Removes the specified RTCVideoView from the video rendering queue.
 *
 *  @param videoRenderer The RTCVideoView to be removed.
 *
 *  @return Returns @p true if removal was successful. Else returns @p false.
 */
- (BOOL)removeRenderer:(RTCVideoView *)videoRenderer;

@end
