//
//  H2HLocalizationManager.h
//  H2H
//
//  Created by atul.ghorpade on 02/09/16.
//  Copyright © 2016 Tutor Group. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface H2HLocalizationManager : NSObject


// a singleton:
+ (H2HLocalizationManager*) sharedLocalizationManager;

// this gets the string localized:
- (NSString*) localizedStringForKey:(NSString*) key;

//set a new language:
- (void) setLanguage:(NSString*) lang;


-(void)applyCustomLanguage;

@end
