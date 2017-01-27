//
//  H2HNewMoreOptionsTableViewCell.h
//  H2H
//
//  Created by pratima ghadage on 11/08/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol CellDelegate <NSObject>
- (void)didClickOnCellAccessoryAtIndex:(NSInteger)cellIndex withState:(BOOL)switchState;
@end

@interface H2HNewMoreOptionsTableViewCell : UITableViewCell
typedef enum
{
    OPTIONS_DETAIL_CELL,
    OPTIONS_SWITCH_CELL,
    OPTIONS_SHOW_TIMER_CELL,
    OPTIONS_SHOW_OVERLAY_CELL
    
}CELL_TYPE;

@property (nonatomic) CELL_TYPE cellType;

@property (assign, nonatomic) NSInteger cellIndex;

@property BOOL isSwitchON;

@property (weak, nonatomic) id<CellDelegate>delegate;


@end
