//
//  H2HNewThemeDefaultTableCell.h
//  H2H
//
//  Created by pratima ghadage on 17/08/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <UIKit/UIKit.h>
@protocol CellThemeDefaultDelegate <NSObject>

- (void)didClickDefaultColor;

@end

@interface H2HNewThemeDefaultTableCell : UITableViewCell

-(void)deSelectDefault;
-(void)selectDefault;
-(void)setCurrentlySelectedColorAsDefaultColor:(EnumThemeColor) color;

@property id delegate;

@property (weak, nonatomic) IBOutlet UILabel *labelDefaultThemeColor;

@end
