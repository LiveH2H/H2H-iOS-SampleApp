//
//  H2HSDKExt.h
//  H2HSDKExt
//
//  Created by Anton Ostrovskii on 5/16/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "H2HLoadingView.h"
#import "H2HUserActionManager.h"
#import "H2HLaunchParameterWebService.h"
#import "H2HContainerManager.h"
#import "H2HChatViewController.h"

#define SYSTEM_VERSION_EQUAL_TO(v) \
([[[UIDevice currentDevice] systemVersion] compare:v \
options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v) \
([[[UIDevice currentDevice] systemVersion] compare:v \
options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v) \
([[[UIDevice currentDevice] systemVersion] compare:v \
options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v) \
([[[UIDevice currentDevice] systemVersion] compare:v \
options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v) \
([[[UIDevice currentDevice] systemVersion] compare:v \
options:NSNumericSearch] != NSOrderedDescending)

#define kCustomizationHideTranslator            @"kCustomizationHideTranslator"
#define kCustomizationHideTranscript            @"kCustomizationHideTranscript"
#define kCustomizationLogoImage                 @"kCustomizationLogoImage"
#define kCustomizationLanguage                  @"kCustomizationLanguage"
#define kCustomizationUseFabricJSWhiteboard     @"kCustomizationUseFabricJSWhiteboard"
#define kCustomizationUseAttendeeIdForWB        @"kCustomizationUseAttendeeIdForWB"
#define kCustomizationHideParticipantsIcon      @"kCustomisztionHideParticipantsIcon"
#define kCustomizationHideInviteUsersByEmail    @"kCustomizationHideInviteUsersByEmail"

#define kCustomLanguageDefault          nil
#define kCustomLanguageEnglish          @"english"
#define kCustomLanguageChinese          @"chinese"

@interface H2HSDKExt : NSObject <H2HWebServiceDelegate>

+ (H2HSDKExt *)sharedInstance;
@property (weak, nonatomic) UIViewController *externalParentViewController;

- (void)joinMeetingWithToken:(NSString *)token onServer:(NSString *)serverURL usingOrigin:(NSString *)origin withReferrer:(NSString *)referrerURL fromViewController:(UIViewController *)parentViewController;
- (void)joinMeetingWithToken:(NSString *)token onServer:(NSString *)serverURL usingOrigin:(NSString *)origin withReferrer:(NSString *)referrerURL fromViewController:(UIViewController *)parentViewController withCustomizationParameters:(NSDictionary *)customizationParameters;
- (void)joinMeetingWithToken:(NSString *)token onServer:(NSString *)serverURL usingOrigin:(NSString *)origin withReferrer:(NSString *)referrerURL fromViewController:(UIViewController *)parentViewController withCustomizationParameters:(NSDictionary *)customizationParameters andInviteURL:(NSString *)inviteURL;
- (void)leaveMeetingWithReason:(NSString*)reason;

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;
- (void)applicationWillResignActive:(UIApplication *)application;
- (void)applicationDidEnterBackground:(UIApplication *)application;
- (void)applicationWillEnterForeground:(UIApplication *)application;
- (void)applicationDidBecomeActive:(UIApplication *)application;
- (void)applicationWillTerminate:(UIApplication *)application;
- (void)application:(UIApplication *)application handleActionWithIdentifier:(NSString *)identifier forLocalNotification:(UILocalNotification *)notification completionHandler:(void (^)())completionHandler;
- (void)application:(UIApplication *)application handleActionWithIdentifier:(NSString *)identifier forLocalNotification:(UILocalNotification *)notification withResponseInfo:(NSDictionary *)responseInfo completionHandler:(void (^)())completionHandler;

@end