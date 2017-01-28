//
//  RTCMediaConstraint.h
//  TutorWebRTC
//
//  Created by Sagar Kasture on 13/09/16.
//  Copyright © 2016 Spring Computing Technologies Pvt. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RTCMediaConstraint : NSObject

@property (nonatomic, copy) NSString* heightConstraint;
@property (nonatomic, copy) NSString* widthConstraint;
@property (nonatomic, copy) NSString* frameRate;

-(instancetype)initWithHeight:(NSString*)heightConstraint
                     andWidth:(NSString*)widthConstraint
                 andFrameRate:(NSString*)frameRate;
@end
