//
//  RTCDataTrackConstants.h
//  TutorWebRTC
//
//  Created by Piyush Banerjee on 3/11/16.
//  Copyright © 2016 Spring Computing Technologies Pvt. Ltd. All rights reserved.
//

#ifndef RTCDataTrackConstants_h
#define RTCDataTrackConstants_h

/**
 *  The error domain of the errors raised by the RTCDataTrack and its subclasses.
 */
#define RTCDataTrackErrorDomain  (@"RTCDataTrackErrorDomain")

/**
 *  The error codes used by the RTCDataTrack and its subclasses.
 */
typedef NS_ENUM(NSInteger, RTCDataTrackError) {
    /**
     *  Indicates that the reason for the failure could not be determined.
     */
    RTCDataTrackErrorUnknown,
    /**
     *  Indicates that the feature is currently not supported.
     */
    RTCDataTrackErrorUnsupportedFeature
};

#endif /* RTCDataTrackConstants_h */
