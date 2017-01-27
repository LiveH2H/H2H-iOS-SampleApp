//
//  H2HUserSettingsManager.h
//  H2H
//
//  Created by Anton Ostrovskii on 8/24/16.
//  Copyright © 2016 Tutor Group. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface H2HUserSettingsManager : NSObject

+ (H2HUserSettingsManager *)sharedInstance;

@property (nonatomic, getter=getLiveSupportLanguage, setter=setLiveSupportLanguage:) NSString *liveSupportLanguage;

@property (nonatomic, getter=getIsChatOverlayEnabled, setter=setIsChatOverlayEnabled:) BOOL isChatOverlayEnabled;
@property (nonatomic, getter=getIsLiveTranscriptEnabled, setter=setIsLiveTranscriptEnabled:) BOOL isLiveTranscriptEnabled;
@property (nonatomic, getter=getIsAutomaticallyHideToolbar, setter=setIsAutomaticallyHideToolbar:) BOOL isAutomaticallyHideToolbar;

@end