//
//  H2HContactInfoModel.h
//  H2H
//
//  Created by Aditya Deshmane on 19/10/16.
//  Copyright © 2016 Tutor Group. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface H2HContactInfoModel : NSObject

@property(nonatomic, copy) NSString *personName;
@property(nonatomic, copy) NSString *personEmail;
@property BOOL isCellSelected;

-(instancetype) initInfoWithName:(NSString *)name WithEmail:(NSString *)email withSelection:(BOOL) isSelected;

@end
