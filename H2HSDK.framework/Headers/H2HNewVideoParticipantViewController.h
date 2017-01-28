//
//  H2HVideoParticipantViewControllerNew.h
//  H2H
//
//  Created by Anton Ostrovskii on 8/17/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TutorWebRTC/TutorWebRTC.h>

@interface H2HNewVideoParticipantViewController : UIViewController<RTCVideoViewDelegate>

@property (weak, nonatomic, setter=setRTCUser:) RTCUser *rtcUser;

- (id)initWithRTCUser:(RTCUser *)rtcUser;
- (void)onRemoteVideoEnabled:(BOOL)isEnabled;
- (void)updateVideoOffLabelVisibility;

@end