//
//  H2HBaseCollectionCell.h
//  H2H
//
//  Created by Sagar Kasture on 14/01/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "H2HCollectionProtocol.h"

@interface H2HBaseCollectionCell : UICollectionViewCell

@property (weak, nonatomic) IBOutlet UIView *viewBottom;
@property (weak, nonatomic) IBOutlet UIView *viewCellContent;
@property (weak, nonatomic) IBOutlet UIButton *buttonExpand;

@property (nonatomic, weak) id<H2HCellToCollectionNotifyDelegate> delegate;

@end
