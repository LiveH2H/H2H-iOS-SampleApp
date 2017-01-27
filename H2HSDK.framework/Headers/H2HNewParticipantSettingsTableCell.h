//
//  H2HNewParticipantSettingsTableCell.h
//  H2H
//
//  Created by pratima ghadage on 16/08/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol CellDelegate <NSObject>
- (void)didClickOnCellAccessoryAtIndex:(NSInteger)cellIndex withState:(BOOL)switchState;
@end

@interface H2HNewParticipantSettingsTableCell : UITableViewCell

@property BOOL isSwicthON;

@property (weak, nonatomic) id<CellDelegate>delegate;

@property (assign, nonatomic) NSInteger cellIndex;

-(void)setParticipantSettings:(NSString *)setting;

@end
