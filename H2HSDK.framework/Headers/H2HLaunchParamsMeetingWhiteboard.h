//
//  H2HWhiteboard.h
//  H2H
//
//  Created by Sagar Kasture on 14/04/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface H2HMeetingWhiteboard : NSObject

@property (nonatomic, copy) NSString* blank;
@property (nonatomic, copy) NSString* desc;
@property (nonatomic, assign) long ID;
@property (nonatomic, copy) NSArray* pages;
@property (nonatomic, copy) NSString* presentation;
@property (nonatomic, copy) NSString* status;
@property (nonatomic, assign) bool isFinished;

- (id)initWithJson:(id)json;

@end