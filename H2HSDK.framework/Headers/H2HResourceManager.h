//
//  H2HResourceManager.h
//  H2H
//
//  Created by Anton Ostrovskii on 5/17/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "H2HNotificationViewController.h"
#import "H2HNewNotificationViewController.h"

@interface H2HResourceManager : NSObject

+ (H2HResourceManager *)sharedInstance;

@property (readonly, nonatomic, getter=getStoryboardMain) UIStoryboard *storyboardMain;
@property (readonly, nonatomic, getter=getStoryboardMainPad) UIStoryboard *storyboardMainPad;
@property (readonly, nonatomic, getter=getStoryboardMainPhone) UIStoryboard *storyboardMainPhone;
@property (readonly, nonatomic, getter=getStoryboardWhiteboard) UIStoryboard *storyboardWhiteboard;
@property (readonly, nonatomic, getter=getStoryboardColorPopup) UIStoryboard *storyboardColorPopup;
@property (readonly, nonatomic, getter=getStoryboardSelectWhiteBoard) UIStoryboard *storyboardSelectWhiteBoard;
@property (readonly, nonatomic, getter=getStoryboardParticipant) UIStoryboard *storyboardParticipant;
@property (readonly, nonatomic, getter=getStoryboardWhiteboardManager) UIStoryboard *storyboardWhiteboardManager;
@property (readonly, nonatomic, getter=getStoryboardNetworkLost) UIStoryboard *storyboardNetworkLost;
@property (readonly, nonatomic, getter=getStoryboardMoreOptions) UIStoryboard *storyboardMoreOptions;
@property (readonly, nonatomic, getter=getStoryboardNetworkStatus) UIStoryboard *storyboardNetworkStatus;
@property (readonly, nonatomic, getter=getStoryboardLiveSupportIssues) UIStoryboard *storyboardLiveSupportIssues;
@property (readonly, nonatomic, getter=getStoryboardVideoConference) UIStoryboard *storyboardVideoConference;
@property (readonly, nonatomic, getter=getStoryboardWhiteboardForPhone) UIStoryboard *storyboardWhiteboardForPhone;
@property (readonly, nonatomic, getter=getStoryboardContactsPicker) UIStoryboard *getStoryboardContactsPicker;
@property (readonly, nonatomic, getter=getStoryboardSubmitSupportRequest) UIStoryboard *getStoryboardSubmitSupportRequest;
@property (readonly, nonatomic, getter=getStoryboardTestConnection) UIStoryboard *storyboardTestConnection;
@property (readonly, nonatomic, getter=getStoryboardCommonUtiLity) UIStoryboard *stoyboardCommonUtility;


//Fabric JS Whiteboard Storyboards
@property (readonly, nonatomic, getter=getStoryboardFabricJSWhiteboard) UIStoryboard *storyboardFabricJSWhiteboard;
@property (readonly, nonatomic, getter=getStoryboardFabricJSWhiteboardCustomMenu) UIStoryboard *storyboardFabricJSWhiteboardCustomMenu;
@property (readonly, nonatomic, getter=getStoryboardFabricJSWhiteboardSelection) UIStoryboard *storyboardFabricJSWhiteboardSelection;

//POLL Storyboard
@property (readonly, nonatomic, getter=getStoryboardPoll) UIStoryboard *storyboardPoll;


@property (readonly, nonatomic, getter=getStoryboardChat) UIStoryboard *storyboardChat;
@property (readonly, nonatomic, getter=getStoryboardIPhoneUtility) UIStoryboard *storyboardIPhoneUtility;
@property (readonly, nonatomic, getter=getStoryboardMeetingIDDropDown) UIStoryboard *storyboardMeetingIDDropDown;
@property (readonly, nonatomic, getter=getStoryboardNewIPhoneChat) UIStoryboard *sstoryboardNewIPhoneChat;


@property (readonly, nonatomic, getter=getServerAddress) NSString *serverAddress;
@property (readonly, nonatomic, getter=getWSBaseURL) NSString *wsBaseURL;
@property (readonly, nonatomic, getter=getWebRTCServerURL) NSString *webRTCServerURL;
@property (readonly, nonatomic, getter=getAdminConsoleURL) NSString *adminConsoleURL;
@property (readonly, nonatomic, getter=getChatServerURL) NSString *chatServerURL;
@property (readonly, nonatomic, getter=getWhiteboardServerURL) NSString *whiteboardServerURL;
@property (readonly, nonatomic, getter=getWhiteboardURL) NSString *whiteboardURL;
@property (readonly, nonatomic, getter=getWSChatWrapperBaseURL) NSString *wsChatWrapperBaseURL;
@property (readonly, nonatomic, getter=getIssueURL) NSString *issueURL;
@property (readonly, nonatomic, getter=getLiveChatSupportURL) NSString *liveChatSupportURL;
@property (readonly, nonatomic, getter=getWSLiveSupportDeskProNodeURL) NSString *wsLiveSupportDeskProNodeURL;

@property (strong, nonatomic) NSString *origin;
@property (strong, nonatomic) NSString *referrerURL;
@property (strong, nonatomic) NSString *serverURL;
@property (strong, nonatomic) NSString *inviteURL;

// Customisation parameters
@property (nonatomic, assign) BOOL customHideTranslator;
@property (nonatomic, assign) BOOL customHideTranscript;
@property (nonatomic, assign) BOOL customHideChat;
@property (nonatomic, assign) BOOL customHideVideoTile;
@property (nonatomic, assign) BOOL customHideVideoControl;
@property (nonatomic, assign) BOOL customHideAudioControl;
@property (nonatomic, assign) BOOL customHideRaiseHand;
@property (nonatomic, assign) BOOL customHideLiveSupport;
@property (nonatomic, assign) BOOL customHideWhiteboard;
@property (nonatomic, assign) BOOL customHidePoll;
@property (nonatomic, assign) BOOL customRecordingEnabled;
@property (nonatomic, assign) BOOL customLockUIEnabled;
@property (nonatomic, assign) BOOL customHideInviteParticipant;

@property (nonatomic, assign) BOOL isAudioOnly;

@property (strong, nonatomic) UIImage *customLogoImage;
@property (strong, nonatomic) NSString *customLanguage;
@property (nonatomic) Boolean customUseFabricJSWhiteboard;
@property (nonatomic) Boolean customUseFabricJSWhiteboardMemoryOptimisation;
@property (nonatomic) Boolean customUseAttendeeIdForWB;
@property (nonatomic) Boolean customHideParticipantsIcon;
@property (nonatomic) Boolean customHideInviteUsersByEmail;

@property (nonatomic, assign) BOOL customUseDeskProLiveSupport;
@property (nonatomic, assign) BOOL shouldEnableTestConnection;

@property (strong, nonatomic) H2HNotificationViewController *notificationViewController;
@property (strong, nonatomic) H2HNewNotificationViewController *smartNotificationViewController;

@property (readonly, nonatomic, getter=getClientVersion) NSString *clientVersion;
@property (readonly, nonatomic, getter=getBuildNumber) NSString *buildNumber;
@property (readonly, nonatomic, getter=getMobileClientString) NSString *mobileClientString;

@property (readonly, nonatomic, getter=getDefaultAnimationDuration) NSTimeInterval defaultAnimationDuration;
@property (readonly, nonatomic, getter=getDefaultTranscriptDisplayingDuration) NSTimeInterval defaultTranscriptDisplayingDuration;
@property (readonly, nonatomic, getter=getDefaultToolBarAppearanceDuration) NSTimeInterval defaultToolBarAppearanceDuration;
@property (readonly, nonatomic, getter=getIsHostVideoFirstByDefault) BOOL isHostVideoFirstByDefault;
@property (readonly, nonatomic, getter=getVideoParticipantsMaxCount) NSInteger videoParticipantsMaxCount;
@property (readonly, nonatomic, getter=getWSLiveSupportChatBaseURL) NSString *wsLiveSupportChatBaseURL;
- (NSBundle *)getBundle;
- (UIImage *)getImageNamed:(NSString *)name;
- (NSString *)getLocalizedString:(NSString *)key comment:(NSString *)comment;
- (UINib *)getNibByName:(NSString *)nibName;

- (void)showSuccessMessageWithText:(NSString *)text;
- (void)showErrorMessageWithText:(NSString *)text;
- (void)updateCustomParametersForMeetingType:(NSString*)meetingType;

@end
