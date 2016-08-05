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

@interface H2HUserActionManager : NSObject

@property (nonatomic, strong) H2HLaunchParameters*  launchParameters;

@property (nonatomic, strong) NSArray*  whiteboards;

@property (nonatomic, strong) H2HInitializeChatModel* initializeChatModel;

/*! @brief  Stores RTC multi cast session manager instance. */
@property (strong) RTCMulticastSessionManager* sessionManager;

/*!
 * @discussion Gets the shared instance of this class.
 * @return instancetype is the instance of this class.
 */
+(instancetype) sharedInstance;

/*!
 * @discussion Method to connect to RTC session.
 */
-(void) connectToWebRTCServer;

/*!
 * @discussion Method to toggle audio stream.
 */
-(void) toggleAudio;

/*!
 * @discussion Method to toggle video stream.
 */
-(void) toggleVideo;

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
- (void)leaveMeeting;

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
-(void) optionEndSessionTapped;

/*!
 * @discussion Resets all the tiles to their original layout.
 */
-(void) resetTilesTapped;

-(void) setChatBadgeIconVisibility:(BOOL)shouldShow;

/*!
 * @discussion Check whether RTC user is a local user
 */
- (BOOL)isLocalUser:(RTCUser *)user;

@end