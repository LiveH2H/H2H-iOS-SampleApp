//
//  H2HNewBaseCollectionCell.h
//  H2H
//
//  Created by Anton Ostrovskii on 8/28/16.
//  Copyright © 2016 Tutor Group. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "H2HCollectionProtocol.h"

@interface H2HNewBaseCollectionCell : UICollectionViewCell<H2HChildToCellNotifyDelegate>

@property (strong, nonatomic) UIView *viewBottom;
@property (strong, nonatomic) UIView *viewCellContent;
@property (strong, nonatomic) UIButton *buttonExpand;

@property (nonatomic, weak) id<H2HCellToCollectionNotifyDelegate> delegate;

@end