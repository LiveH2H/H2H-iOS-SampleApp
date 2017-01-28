//
//  H2HPollSubmitAnswerWebService.h
//  H2H
//
//  Created by pratima ghadage on 06/10/16.
//  Copyright © 2016 Tutor Group. All rights reserved.
//

#import "H2HWebService.h"

@interface H2HPollSubmitAnswerWebService : H2HWebService
- (instancetype)initWithPollID:(NSString *)pollID
                  andMeetingID:(NSString *)meetingID
                    forAnswers:(NSArray *)questionAnswersArray
                    forSummary:(BOOL)isForSummary;
@end
