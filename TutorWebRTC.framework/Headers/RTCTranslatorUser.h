//
//  RTCTranslatorUser.h
//  TutorWebRTC
//
//  Created by pratima ghadage on 17/05/16.
//  Copyright © 2016 Spring Computing Technologies Pvt. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RTCTranslatorUser : RTCUser

/**
 *  Launguage code for translation language.
 */
@property (readonly, strong) NSString *languageCode;

/**
 *  Language Name of translation.
 */
@property (readonly, strong) NSString *languageName;

@end
