//
//  H2HVideoParticipantsDelegate.h
//  DevMeetingView
//
//  Created by Anton Ostrovskii on 3/24/16.
//  Copyright © 2016 TutorGroup. All rights reserved.
//

#ifndef H2HVideoParticipantsDelegate_h
#define H2HVideoParticipantsDelegate_h

#import <UIKit/UIKit.h>

@protocol H2HVideoParticipantsDelegate <NSObject>
- (void)setRTCUsers:(NSArray<RTCUser*>*)rtcUsers animated:(BOOL)animated;
- (NSArray<RTCUser*>*)getRTCUsers;
- (void)addRTCUser:(RTCUser *)user animated:(BOOL)animated;
- (void)removeRTCUser:(RTCUser *)user animated:(BOOL)animated;


@property (strong, nonatomic, getter=getVideoParticipants) NSMutableArray *videoParticipants;
- (void)setVideoParticipants:(NSMutableArray *)videoParticipants animated:(BOOL)animated;



@required
@property (strong, nonatomic, getter=getParticipants) NSMutableArray *participants;
- (void)setParticipants:(NSMutableArray *)participants animated:(BOOL)animated;
- (void)clearParticipantsAnimated:(BOOL)animated;
- (void)addParticipant:(id)participant animated:(BOOL)animated;
- (void)removeParticipant:(id)participant animated:(BOOL)animated;
- (void)reloadParticipantsAnimated:(BOOL)animated;
- (void)setRTCUsers:(NSArray<RTCUser*>*)rtcUsers animated:(BOOL)animated;
- (NSArray<RTCUser*>*)getRTCUsers;

@optional
- (void)addParticipantView:(id)participant animated:(BOOL)animated;
- (void)removeParticipantView:(id)participant animated:(BOOL)animated;
- (void)layoutParticipantsAddSubviews:(BOOL)addSubviews;
- (void)addParicipantTapGestureRecognizers;
- (void)didTapParticipant:(id)participant;
- (void)assertParticipantsCount;

@end

#endif