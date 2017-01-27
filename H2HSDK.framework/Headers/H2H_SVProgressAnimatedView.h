//
//  H2H_SVProgressAnimatedView.h
//  H2H_SVProgressHUD, https://github.com/H2H_SVProgressHUD/H2H_SVProgressHUD
//
//  Copyright (c) 2016 Tobias Tiemerding. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface H2H_SVProgressAnimatedView : UIView

@property (nonatomic, assign) CGFloat radius;
@property (nonatomic, assign) CGFloat strokeThickness;
@property (nonatomic, strong) UIColor *strokeColor;
@property (nonatomic, assign) CGFloat strokeEnd;

@end