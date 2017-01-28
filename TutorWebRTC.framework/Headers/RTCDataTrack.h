//
//  RTCDataTrack.h
//  TutorWebRTC
//
//  Created by Piyush Banerjee on 3/11/16.
//  Copyright © 2016 Spring Computing Technologies Pvt. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "RTCDataTrackConstants.h"


/**
 *  An abstraction of a data stream.
 */
@interface RTCDataTrack : NSObject

/**
 *  Indicates whether the data track is enabled or disabled.
 */
@property(readonly, nonatomic) BOOL isEnabled;

/**
 *  Enables or disables a data track.
 *
 *  @param isEnabled A boolean value to indicate whether the track is to be enabled or disabled.
 *  @param error     Holds @p nil if the new value was successfully set. Else a valid error object detailing the cause of failure.
 *
 *  @return Returns @p true on success. Else returns @p false.
 */
-(BOOL)setEnabled: (BOOL)isEnabled
            error: (NSError *_Nonnull __autoreleasing *_Nonnull)error;

@end
