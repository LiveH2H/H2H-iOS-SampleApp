//
//  H2HNewParticipantsManager.h
//  H2H
//
//  Created by Kalyani.Chinchane on 22/08/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface H2HNewParticipantsManager : NSObject

//sorted array of particiapnts
@property (readwrite,nonatomic) NSMutableArray *arrayParticipants;

//handRaiseEvent list
@property (readwrite,nonatomic) NSMutableArray *arrayRaisedHandParticipants;

//sorted array of invitees
@property (readwrite,nonatomic) NSMutableArray *arrayInvitees;

//returns a sorted list of participants
- (NSArray *) getSortedParticipantList;

//method to remove user name from the raiseHand array
- (void) removeObjectFromArrayRaisedHandForUserName:(NSString *)username;

//method to add object in rasie hand array to avoid duplicate enteries
- (void) addObjectToArrayRaisedHandForUserName:(NSString *)username;

//method to get initial List of invitees 
-(NSArray *)getInviteesInitialList;

//method to get SortedInviteeList on events received
-(NSArray *)getSortedInviteeList;

//method to remove user from the invitees List
- (void) removeUserFromInviteesList:(RTCUser *)user;

//method to add user in invitees List
- (void) addUserToInviteesList:(RTCUser *)user;

@end
