//
//  H2HPollQuestionModel.h
//  H2H
//
//  Created by pratima ghadage on 04/10/16.
//  Copyright © 2016 Tutor Group. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface H2HPollQuestionModel : NSObject

@property NSString *strPollID;
@property NSString *question;
@property NSString *questionID;

//options array will contain H2HPollQuestionOptionModel object
@property NSArray *options;

@end

@interface H2HPollQuestionOptionModel :NSObject

@property NSString *optionText;
@property NSString *optionID;
@property NSNumber *percentage;

-(instancetype)initWithOptionText:(NSString *)optionText
                         OptionID: (NSString *)optionID
                       Percentage: (NSNumber *)percentage;

@end
