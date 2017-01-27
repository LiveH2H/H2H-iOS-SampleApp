//
//  H2HNewVideoConferenceBaseViewController.h
//  H2H
//
//  Created by Anton Ostrovskii on 9/26/16.
//  Copyright © 2016 Tutor Group. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "H2HNewVideoConferenceNavigationButton.h"
#import "H2HNewVideoParticipantViewController.h"
#import "H2HUserActionManager.h"
#import <TutorWebRTC/TutorWebRTC.h>
#import "AppConstants.h"
#import "H2HNewTranscriptViewController.h"
#import "H2HUserSettingsManager.h"

typedef NS_OPTIONS(NSUInteger, H2HNewVideoConferenceViewMode) {
    H2HNewVideoConferenceViewModeStandard = 0,
    H2HNewVideoConferenceViewModeGallery = 1 << 0,
};

@interface H2HNewVideoConferenceBaseViewController : UIViewController <H2HNewVideoConferenceNavigationButtonDelegate>

@property (readonly, getter=getViewModeButtonWidth) CGFloat viewModeButtonWidth;
@property (readonly, getter=getViewModeButtonHeight) CGFloat viewModeButtonHeight;
@property (readonly, getter=getViewModeButtonInnerMargin) CGFloat viewModeButtonInnerMargin;
@property (readonly, getter=getViewModeButtonOuterMargin) CGFloat viewModeButtonOuterMargin;
@property (readonly, getter=getStandardViewModeOuterMargin) CGFloat standardViewModeOuterMargin;
@property (readonly, getter=getStandardViewModeOutterMarginMultiplier) CGFloat standardViewModeOutterMarginMultiplier;
@property (readonly, getter=getStandardViewModeVideoButtonWidthMultiplier) CGFloat standardViewModeVideoButtonWidthMultiplier;
@property (readonly, getter=getStandardViewModeMainVideosCount) NSInteger standardViewModeMainVideosCount;
@property (readonly, getter=getStandardViewModeMaxBottomVideosCount) NSInteger standardViewModeMaxBottomVideosCount;
@property (readonly, getter=getGalleryViewModeMaxVideosCount) NSInteger galleryViewModeMaxVideosCount;
@property (readonly, getter=getStandardViewModeSmallVideoWidthMultiplier) CGFloat standardViewModeSmallVideoWidthMultiplier;
@property (readonly, getter=getStandardViewModeSmallVideoHeightMultiplier) CGFloat standardViewModeSmallVideoHeightMultiplier;

@property (strong, nonatomic) UIButton *buttonStandardViewMode;
@property (strong, nonatomic) UIButton *buttonGalleryViewMode;
@property (strong, nonatomic) UIView *contentView;

@property (strong, nonatomic) UIButton *buttonStandardViewPreviousVideos;
@property (strong, nonatomic) UIButton *buttonStandardViewNextVideos;

@property (strong, nonatomic) UIActivityIndicatorView *activityIndicatorView;
@property (strong, nonatomic) UILabel *statusLabel;
@property (strong, nonatomic) UILabel *webinarSubjectLabel;
@property (strong, nonatomic) UILabel *hostStatusLabel;

@property (strong, nonatomic) NSMutableArray *participants;
@property (nonatomic, readonly, getter=getVideoPagesCount) NSInteger videoPagesCount;
@property (nonatomic) NSInteger currentVideoPage;
@property (nonatomic, readonly, getter=getVisibleParticipants) NSMutableArray *visibleParticipants;

@property (strong, nonatomic) H2HNewVideoConferenceNavigationButton *prevButton;
@property (strong, nonatomic) H2HNewVideoConferenceNavigationButton *nextButton;

@property (strong, nonatomic) H2HNewTranscriptViewController *transcriptViewController;

@property (nonatomic) BOOL isTappedOnParticipant;
@property (nonatomic) BOOL startedJoiningRoom;

@property (nonatomic, getter=getViewMode, setter=setViewMode:) H2HNewVideoConferenceViewMode viewMode;
@property (nonatomic, getter=getViewModeButtonsHidden, setter=setViewModeButtonsHidden:) BOOL isViewModeButtonsHidden;

- (void)addObservers;
- (void)removeObservers;
- (void)prepareUI;
- (void)updateLayoutAnimated:(BOOL)animated;
- (void)sortParticipants;
- (UIView *)getParticipantViewByIndex:(NSInteger)index;
- (UIView *)getParticipantViewByIndex:(NSInteger)index fromParticipants:(NSArray *)participants;
- (void)setSubviews:(NSArray *)subviews;
- (void)setupGestureRecognizers:(NSArray *)subviews;
- (void)setMainVideoConstraintsForStandardMode:(UIView *)view;
- (void)setSubviews:(NSArray *)subviews aboveSubview:(UIView *)underlyingView;
- (void)setSmallVideoConstraintsForStandardMode:(UIView *)view;
- (void)setSmallVideosConstraintsForStandardMode:(NSArray *)views;
- (void)setVideoNavigationButtonConstraints:(H2HNewVideoConferenceNavigationButton *)button;
- (void)setVideoNavigationButtonsConstraints:(NSArray *)buttons;
- (void)transcriptLanguageChangedTo:(TranscriptLanguage)language;
- (void)roomUserChangedHandler:(NSNotification *)notification;

@end