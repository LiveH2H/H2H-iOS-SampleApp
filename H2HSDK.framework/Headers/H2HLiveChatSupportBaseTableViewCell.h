//
//  H2HLiveChatSupportBaseTableViewCell.h
//  H2H
//
//  Created by Anton Ostrovskii on 8/1/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <UIKit/UIKit.h>

static CGFloat liveChatSupportCellMargin = 5.0f;
static CGFloat liveChatSupportCellBulbSize = 32.0f;
static CGFloat liveChatSupportCellFontSize = 13.0f;
static CGFloat liveChatSupportCellInnerMargin = 15.0f;

@interface H2HLiveChatSupportBaseTableViewCell : UITableViewCell

@property (strong, nonatomic) UITextView *textView;
@property (strong, nonatomic) UILabel *nameLabel;
@property (strong, nonatomic) UIView *nameBulb;
@property (strong, nonatomic) UIImageView *quoteTriangle;

- (void)setMessage:(NSString *)message;
+ (CGFloat)estimatedCellHeightByText:(NSString *)cellText andWidth:(CGFloat)cellWidth;

@end