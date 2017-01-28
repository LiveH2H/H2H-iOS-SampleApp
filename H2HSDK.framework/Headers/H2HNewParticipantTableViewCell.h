//
//  H2HParticipantTableViewCell.h
//  H2H
//
//  Created by pratima ghadage on 25/01/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "H2HParticipantModel.h"
#import "H2HNewParticipantsViewController.h"

@protocol CellDelegate <NSObject>
- (void)didClickOnCellAtIndex:(NSInteger)cellIndex withData:(NSInteger)buttonIndexTapped;
@end

@interface H2HNewParticipantTableViewCell : UITableViewCell

@property (weak, nonatomic) id<CellDelegate>delegate;
@property (assign, nonatomic) NSInteger cellIndex;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *constraintWidthBtnActionIndicator;

-(void)setCellDataSource:(H2HParticipantModel *)participant;

@end
