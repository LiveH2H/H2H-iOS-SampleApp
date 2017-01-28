//
//  H2HLaunchParamsUser.h
//  H2H
//
//  Created by Sagar Kasture on 04/05/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface H2HLaunchParamsUser : NSObject

@property (nonatomic, copy)     NSString* avatar;
@property (nonatomic, copy)     NSString* emailAddress;
@property (nonatomic, copy)     NSString* firstName;
@property (nonatomic, copy)     NSString* displayLocaleCode;
@property (nonatomic, copy)     NSString* lastName;
@property (nonatomic, copy)     NSString* loginEMail;
@property (nonatomic, copy)     NSString* origin;
@property (nonatomic, copy)     NSString* displayName;
@property (nonatomic, copy)     NSString* userID;
@property (nonatomic, copy)     NSString* originUserID;

@end
