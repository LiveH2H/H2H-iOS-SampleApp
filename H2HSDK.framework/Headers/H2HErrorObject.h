//
//  H2HErrorObject.h
//  H2H
//
//  Created by Sagar Kasture on 09/06/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "H2HErrorConstants.h"

/**
 *  Class to describe error model.
 */
@interface H2HErrorObject : NSObject

/**
 *  error description
 */
@property (copy) NSString* localizedDescription;

/**
 *  severity of an error
 */
@property (assign) H2HERROR_SEVERITY severity;

/**
 *  type of an error.
 */
@property (assign) H2HERROR_TYPE type;
@end
