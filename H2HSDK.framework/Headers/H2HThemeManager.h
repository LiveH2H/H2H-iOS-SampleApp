//
//  H2HThemeManager.h
//  H2H
//
//  Created by Aditya Deshmane on 31/08/16.
//  Copyright © 2016 Tutor Group. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface H2HThemeManager : NSObject

+ (H2HThemeManager *)sharedInstance;

@property(nonatomic) UIColor *colorCurrentTheme;

-(UIColor*)getUIColorForThemeColorEnum:(EnumThemeColor) iThemeColor;

-(EnumThemeColor)getEnumForThemeUIColor:(UIColor*) color;


@end
