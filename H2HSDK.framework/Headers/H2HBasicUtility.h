//
//  H2HBasicUtility.h
//  H2H
//
//  Created by charuta.rajopadhye on 13/04/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface H2HBasicUtility : NSObject

+ (BOOL) isStringNilOrEmpty: (NSString *) string;
+(void) showAlert:(UIAlertController*)alert;
+(BOOL)isIPhone;
//+(BOOL)shouldUseFabricJSWhiteboard;

+ (UIView *)roundCornersOnView:(UIView *)view onTopLeft:(BOOL)tl topRight:(BOOL)tr bottomLeft:(BOOL)bl bottomRight:(BOOL)br radius:(float)radius;

+(NSString *)getFirstCharcterOfEachWordCapitalized:(NSString *)data;

+(BOOL) enableVBPieCharts;

+(NSString *)getTestConnectionMessageFor:(RTCTestConnectionData *)testConnectionData;


@end



@interface NSString (Sanity)

- (BOOL) isEmpty;

@end
