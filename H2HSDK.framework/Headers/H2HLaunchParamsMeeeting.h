//
//  H2HLaunchParamsMeeeting.h
//  H2H
//
//  Created by Sagar Kasture on 04/05/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface H2HLaunchParamsMeeeting : NSObject

@property (nonatomic, copy)   NSString*         actualEndTime;
@property (nonatomic, copy)   NSString*         actualStartTime;
@property (nonatomic, assign) NSInteger         attendeeCount;
@property (nonatomic, copy)   NSString*         desc;
@property (nonatomic, assign) NSInteger         ID;
@property (nonatomic, copy)   NSString*         location;
@property (nonatomic, assign) BOOL              recording;
@property (nonatomic, copy)   NSString*         scheduledEndTime;
@property (nonatomic, copy)   NSString*         scheduledStartTime;
@property (nonatomic, copy)   NSString*         status;
@property (nonatomic, copy)   NSString*         subject;
@property (nonatomic, copy)   NSString*         type;
@property (nonatomic, copy)   NSMutableArray*   whiteboards;
@property (nonatomic, copy)   NSString*         origin;
@property (nonatomic, copy)   NSString*         originMeetingID;
@property (nonatomic, copy)   NSArray*          inviteesList;

//@property (nonatomic, readonly, getter=getHLSVideoURL) NSString *hlsVideoURL;

@end
