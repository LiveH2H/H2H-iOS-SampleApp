//
//  h2hPollViewController.h
//  tutorSampleApp
//
//  Created by pratima ghadage on 03/10/16.
//  Copyright © 2016 pratima ghadage. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "H2HPollQuestionModel.h"

@class H2HPollViewController;


@protocol PollResultDelegate <NSObject>
-(void)submitPollWithSelectedOptions:(NSArray *)optionsArray andRemainingTime:(NSTimeInterval) timeRemaining;
-(void)loadPollSummary;
@end

@interface H2HPollViewController : UIViewController

@property UINavigationController* parentNavigationController;
@property NSArray *questionsArray;
@property NSTimeInterval startTime;
@property NSTimeInterval endTime;
@property NSTimeInterval timerDuration;

@property NSString *topicForQuestions;

@property (weak, nonatomic) id<PollResultDelegate>delegate;

@property NSString *meetingID;
@property NSString *pollID;

@property (nonatomic) BOOL bIsEmbeddedInWhitebaord;

@end
