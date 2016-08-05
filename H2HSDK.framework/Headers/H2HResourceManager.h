//
//  H2HResourceManager.h
//  H2H
//
//  Created by Anton Ostrovskii on 5/17/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface H2HResourceManager : NSObject

+ (H2HResourceManager *)sharedInstance;

@property (readonly, nonatomic, getter=getStoryboardMain) UIStoryboard *storyboardMain;
@property (readonly, nonatomic, getter=getStoryboardWhiteboard) UIStoryboard *storyboardWhiteboard;
@property (readonly, nonatomic, getter=getStoryboardColorPopup) UIStoryboard *storyboardColorPopup;
@property (readonly, nonatomic, getter=getStoryboardParticipant) UIStoryboard *storyboardParticipant;
@property (readonly, nonatomic, getter=getStoryboardWhiteboardManager) UIStoryboard *storyboardWhiteboardManager;
@property (readonly, nonatomic, getter=getStoryboardNetworkLost) UIStoryboard *storyboardNetworkLost;

@property (readonly, nonatomic, getter=getServerAddress) NSString *serverAddress;
@property (readonly, nonatomic, getter=getWSBaseURL) NSString *wsBaseURL;
@property (readonly, nonatomic, getter=getWebRTCServerURL) NSString *webRTCServerURL;
@property (readonly, nonatomic, getter=getChatServerURL) NSString *chatServerURL;
@property (readonly, nonatomic, getter=getWhiteboardServerURL) NSString *whiteboardServerURL;
@property (readonly, nonatomic, getter=getWhiteboardURL) NSString *whiteboardURL;
@property (readonly, nonatomic, getter=getWSChatWrapperBaseURL) NSString *wsChatWrapperBaseURL;

@property (strong, nonatomic) NSString *origin;
@property (strong, nonatomic) NSString *referrerURL;
@property (strong, nonatomic) NSString *serverURL;

@property (readonly, nonatomic, getter=getClientVersion) NSString *clientVersion;
@property (readonly, nonatomic, getter=getBuildNumber) NSString *buildNumber;
@property (readonly, nonatomic, getter=getMobileClientString) NSString *mobileClientString;

@property (readonly, nonatomic, getter=getDefaultAnimationDuration) NSTimeInterval defaultAnimationDuration;
@property (readonly, nonatomic, getter=getIsHostVideoFirstByDefault) BOOL isHostVideoFirstByDefault;

- (UIImage *)getImageNamed:(NSString *)name;
- (NSString *)getLocalizedString:(NSString *)key comment:(NSString *)comment;
- (UINib *)getNibByName:(NSString *)nibName;

@end