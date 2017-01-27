//
//  H2HPollListModel.h
//  H2H
//
//  Created by charuta.rajopadhye on 12/10/16.
//  Copyright © 2016 Tutor Group. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface H2HPollListModel : NSObject

/*
 
 {
 description = "";
 endTime = 1476252294340;
 pollId = "C8775301-3A21-4AFA-A1A0-4B046FE357D9";
 questions =     (
 {
 options =             (
 {
 color = "<null>";
 optionId = "59E0700D-7C1F-4A92-A091-8FCB97B05BC0";
 percentage = 0;
 text = dvdsvds;
 totalPickedCount = 0;
 },
 {
 color = "<null>";
 optionId = "5BEDC42C-1569-4209-88B0-E51B064DABE7";
 percentage = 0;
 text = dvdsvds;
 totalPickedCount = 0;
 }
 );
 questionId = "10D84341-4631-44D0-B00A-09DD80F1B73C";
 text = "kai sarkha badeltat";
 }
 );
 startTime = 1476251994340;
 title = vsdvdvsd;
 type = 0;
 }

 */

@property (nonatomic, strong) NSString *pollDescription;
@property (nonatomic, strong) NSString *title;

@property (nonatomic, strong) NSString *pollId;
@property double endTime;
@property double startTime;
@property double type;

// contains array of type H2HChartOptionsModel
@property (nonatomic, strong) NSArray *options;

@end