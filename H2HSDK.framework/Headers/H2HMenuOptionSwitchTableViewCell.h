//
//  H2HMenuOptionSwitchTableViewCell.h
//  H2H
//
//  Created by pratima ghadage on 15/01/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <UIKit/UIKit.h>
@protocol H2HMenuOptionSwitchCellDelegate <NSObject>

@optional
-(void)cellSwitchValueChanged:(UITableViewCell *)cell;

@end

@interface H2HMenuOptionSwitchTableViewCell : UITableViewCell

//@property (weak, nonatomic) IBOutlet UILabel *labelOfCell;
//@property (weak, nonatomic) IBOutlet UISwitch *switchOfCell;
 @property UISwitch *switchInCell;
-(id)initWithTitle:(NSString *)title;
@property (nonatomic, weak) id<H2HMenuOptionSwitchCellDelegate> delegate;
@end
