//
//  H2HNewThemeColorTableCell.h
//  H2H
//
//  Created by pratima ghadage on 17/08/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol CellThemeColorDelegate <NSObject>
- (void)didClickColorIndex:(NSInteger)colorIndex;
@end

@interface H2HNewThemeColorTableCell : UITableViewCell

-(void)deSelectAllColorsExceptBlack;

-(void)deSelectAllColors;

-(void)selectColorIndex:(EnumThemeColor)index;

@property id deleagte;

@end
