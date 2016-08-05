//
//  H2HErrorHandler.h
//  H2H
//
//  Created by Sagar Kasture on 09/06/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "H2HErrorObject.h"

@interface H2HErrorHandler : NSObject

+(void) performActionForError: (H2HErrorObject*)error
                    forObject: (id)object
                 withSelector: (SEL)selector;

/**
 *  Creates and displays alert of type Yes-No or Ok-Cancel (YNOC) and performs positive action if selected.
 *
 *  @param message  Message that needs to be displayed on alert.
 *  @param buttons  Array of strings for titles of button (Yes-No, Ok-Cancel)
 *                  Note - These needs to be in positive followed by negative action sequence (e.g. Yes, No).
 *  @param selector method that needs to be execured for positive action.
 *  @param object   object on which selector method is to be called.
 */
+(void) performYNOCAlertWithMessage:(NSString*)message
                    andButtonTitles:(NSArray*)buttons
                  andPositiveAction:(SEL)selector
                           onObject:(id)object;

+(NSString*) getMessageForError:(H2HErrorObject*)error;

@end
