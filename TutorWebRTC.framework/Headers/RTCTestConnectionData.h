//
//  RTCTestConnectionData.h
//  TutorWebRTC
//
//  Created by Sagar Kasture on 11/01/17.
//  Copyright © 2017 Spring Computing Technologies Pvt. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RTCJoinRoomFailData : NSObject

@property (readonly) BOOL isICEGatheringDone;
@property (readonly) BOOL didICECandidateFound;
@property (readonly) BOOL isAudioFlowing;
@property (readonly) BOOL isVideoFlowing;

-(instancetype) initWithIsICEGatheringDone:(BOOL)isICEGatheringDone
                didICECandidateFound:(BOOL)didICECandidateFound
                      isAudioFlowing:(BOOL)isAudioFlowing
                      isVideoFlowing:(BOOL)isVideoFlowing;

// We will not allow init
-(instancetype) init UNAVAILABLE_ATTRIBUTE;
@end

@interface RTCTestConnectionData : RTCJoinRoomFailData

@property (readonly) BOOL isKMSWorking;
@property (readonly) BOOL isNetworkBad;

-(instancetype) initWithIsKMSWorking:(BOOL)isKMSWorking
                        isNetworkBad:(BOOL)isNetworkBad
                  isICEGatheringDone:(BOOL)isICEGatheringDone
                didICECandidateFound:(BOOL)didICECandidateFound
                      isAudioFlowing:(BOOL)isAudioFlowing
                      isVideoFlowing:(BOOL)isVideoFlowing;

// We will not allow init
-(instancetype) init UNAVAILABLE_ATTRIBUTE;
@end
