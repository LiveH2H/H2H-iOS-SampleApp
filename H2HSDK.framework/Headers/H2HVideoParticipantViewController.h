//
//  H2HVideoParticipantViewController.h
//  H2H
//
//  Created by Anton Ostrovskii on 4/1/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TutorWebRTC/TutorWebRTC.h>

@interface H2HVideoParticipantViewController : UIViewController<RTCVideoViewDelegate>

@property (weak, nonatomic, setter=setRTCUser:) RTCUser *rtcUser;
- (id)initWithRTCUser:(RTCUser *)rtcUser;
- (void)onRemoteVideoEnabled:(BOOL)isEnabled;
- (void)updateVideoOffLabelVisibility;
@end