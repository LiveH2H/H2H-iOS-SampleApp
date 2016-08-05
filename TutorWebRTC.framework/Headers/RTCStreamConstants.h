//
//  RTCStreamConstants.h
//  TutorWebRTC
//
//  Created by Piyush Banerjee on 3/15/16.
//  Copyright © 2016 Spring Computing Technologies Pvt. Ltd. All rights reserved.
//

#ifndef RTCStreamConstants_h
#define RTCStreamConstants_h

/**
 *  The error domain of the errors raised by the RTCStream and its subclasses.
 */
#define RTCStreamErrorDomain    (@"RTCStreamErrorDomain")

/**
 *  The error codes used by the RTCDataTrack and its subclasses.
 */
typedef NS_ENUM(NSInteger, RTCStreamError) {
    
    RTCStreamErrorUnknown
};

#endif /* RTCStreamConstants_h */
