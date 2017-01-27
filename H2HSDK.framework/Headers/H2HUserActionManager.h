//
//  H2HUserActionManager.h
//  H2H
//
//  Created by Sagar Kasture on 19/01/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "H2HContainer.h"
#import "H2HLaunchParameters.h"
#import "H2HInitializeChatModel.h"
#import "TutorWebRTC/RTCMulticastSessionManager.h"
#import "H2HNewParticipantsManager.h"
#import "H2HVideoConferenceViewController.h"

/**
 * recording states.
 */
typedef NS_ENUM (NSInteger, RecordingState) {
    /**
     *  Denotes recorder at default state
     */
    RecordingStateNone = 0,
    /**
     *  Denotes recording started
     */
    RecordingStateStarted = 1,
    /**
     *  Denotes recording stopped
     */
    RecordingStateStopped = 2,
    /**
     *  Denotes recording stopped
     */
    RecordingStateEnded = 3
    
};

@protocol H2HNewRecorderViewDelegate <NSObject>

//protocol to delegate recorder timer ticks
- (void)timerDidTick;

@end

@interface H2HUserActionManager : NSObject

@property (nonatomic, strong) H2HLaunchParameters*  launchParameters;

@property (nonatomic, strong) NSArray*  whiteboards;

@property (nonatomic, strong) H2HInitializeChatModel* initializeChatModel;

@property (strong)H2HNewParticipantsManager* participantManager;

//raise hand permission will be updated if host changes permission
@property (nonatomic,readwrite) BOOL isHandRaiseEnabled;

//recording started is to maintain if recording started or not 
@property (nonatomic,readwrite) BOOL isRecordingStarted;

//chat permissions will be updated if host changes permission
@property (nonatomic,readwrite) BOOL isChatEnabled;

/*! @brief  Stores RTC multi cast session manager instance. */
@property (strong) RTCMulticastSessionManager* sessionManager;

/*! maintains the current recording state of UI*/
@property RecordingState currentRecordingState;

/*! maintains the timer for recording */
@property NSTimer *recordingTimer;

/*!total time of recording in seconds */
@property int currentTimeInSeconds;

@property (nonatomic, readwrite) BOOL isMicrophoneAvailable;
@property (nonatomic, readwrite) BOOL isCameraAvailable;


/* recorder delegate  */
@property (nonatomic, weak) id <H2HNewRecorderViewDelegate> delegate;

/*!
 * @discussion Gets the shared instance of this class.
 * @return instancetype is the instance of this class.
 */
+(instancetype) sharedInstance;

/*!
 * @discussion Method to connect to RTC session.
 */
-(void) connectToWebRTCServer;

-(void) joinRoomCheck;
/*!
 * @discussion Method to toggle audio stream.
 */
-(void) toggleAudio;

/*!
 * @discussion Method to toggle video stream.
 */
-(void) toggleVideo;

/*!
 * @discussion Method to notify server that toggle media is denied
 */
-(void) toggleMediaDenied:(RTCMediaToggleData *)mediaData;

/*!
 * @discussion Adds a new tile to existing layout.
 * @param type is the type of tile that needs to be added.
 * @param object iss any specific data that might be required by tile for it's initialization.
 */
-(void) addTileWithType:(CONTAINER_TYPE)type andObject:(NSObject*)object;

/*!
 * @discussion <#description#>
 * @param <#param description#>
 * @return <#return description#>
 */
-(void) pickImageFromCamera;

/*!
 * @discussion <#description#>
 * @param <#param description#>
 * @return <#return description#>
 */
-(void) pickImage;

#pragma MenuOptions Interactions
/*!
 * @discussion Shows option for searching.
 */
-(void) optionSearchTapped;

/*!
 * @discussion Toggles record meeting.
 * @param state is the value that is changed.
 */
-(void) optionRecordSessionStateChanged:(BOOL)state;

/*!
 * @discussion Toggles speech to text.
 * @param state is the value that is changed.
 */
-(void) optionSpeechToTextStateChanged:(BOOL)state;

/*!
 * @discussion Ends the current session.
 */
- (void)leaveMeetingWithReason:(NSString*)leaveReason;

/*!
 * @discussion Ends the current session after asking if user wants to disconnect.
 */
- (void)leaveMeetingConfirmation;

/*!
 * @discussion Send Raise Hand request.
 */
- (void)raiseHand;

/*!
 * @discussion Ends the current session, navigates to "Join the meeting" scene.
 */
-(void) optionEndSessionTappedWithReason:(NSString*)reason;

/*!
 * @discussion Resets all the tiles to their original layout.
 */
-(void) resetTilesTapped;

-(void) setChatBadgeIconVisibility:(BOOL)shouldShow;

/*!
 * @discussion Check whether RTC user is a local user
 */
- (BOOL)isLocalUser:(RTCUser *)user;

-(void)showNetworkStatus;

-(void)showNetworkStatusForUser:(NSString *)userName;

/*!
 * @discussion Host needs to toggle media So show UI to get approval
 */
-(void)hostNeedsToToggleMediaType:(NSString *)mediaType andAction:(BOOL)action;

/*!
 * @discussion show alert that host has toggled media
 */
-(void)showMediaDissabledByHost;

/*!
 * @discussion inform start recorder
 */
- (void)startRecordingTimer;
/*!
 * @discussion inform stop recorder
 */
- (void)stopRecordingTimer;
/*!
 * @discussion inform to update chat permissions
 */
- (void) updateChatPermission:(BOOL)isEnabled;
/*!
 * @discussion inform to update hand raise permissions
 */
- (void) updateHandRaisePermission:(BOOL)isEnabled;

/*!
 * @discussion sets the live support user message
 */
- (void) setLiveSuportUserMessage : (NSString *) userMessage;

/*!
 * @discussion returns the live support user message
 */
- (NSString *) getLiveSupportUserMessage;
/*!
 * @discussion displays confirmation alert to user when enable/unmute media request is received.
 */
- (void) showConfirmationAlertForToggleMedia:(RTCMediaToggleData *)mediaData;
@end