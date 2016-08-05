//
//  RTCVideoView.h
//  TutorWebRTC
//
//  Created by Piyush Banerjee on 1/8/16.
//  Copyright © 2016 Spring Computing Technologies Pvt. Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>


@class RTCVideoView;

/**
 *  The RTCVideoViewDelegate protocol defines methods that inform the delegate
 *  of the changes in rendering and other aspects of the RTCVideoView.
 */
@protocol RTCVideoViewDelegate <NSObject>

/**
 *  Informs the delegate that the size of the video view has changed.
 *
 *  @param videoView The video view whose size has changed.
 *  @param size      The new size of the video view.
 */
- (void) videoView: (RTCVideoView *)videoView
didChangeVideoSize: (CGSize)size;

@end


/**
 *  The view to be used for rendering the video data received through an RTCVideoDataTrack line.
 */
@interface RTCVideoView : UIView

/**
 *  The delegate of the video view.
 */
@property (readwrite, weak) id<RTCVideoViewDelegate> delegate;

/**
 *  Clears the graphics rendering context of the video view.
 */
- (void)clearGraphicsContext;

@end
