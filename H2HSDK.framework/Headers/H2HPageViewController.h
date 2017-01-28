//
//  H2HPageViewController.h
//  H2H
//
//  Created by Anton Ostrovskii on 6/16/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <UIKit/UIKit.h>

@class H2HPageViewController;

@protocol H2HPageViewControllerDelegate <NSObject>

@required
- (void)onPrevionsPageFromSender:(H2HPageViewController *)sender;
- (void)onNextPageFromSender:(H2HPageViewController *)sender;

@optional
- (void)onShakeActivePageToLeftFromSender:(H2HPageViewController *)sender;
- (void)onShakeActivePageToRightFromSender:(H2HPageViewController *)sender;

@end

@interface H2HPageViewController : UIViewController

@property (nonatomic, setter=setPagesCount:, getter=getPagesCount) NSInteger pagesCount;
@property (nonatomic, readonly, getter=getCurrentPage) NSInteger currentPage;
@property (weak, nonatomic) id<H2HPageViewControllerDelegate> delegate;

- (void)onPreviousPage:(UIButton *)sender;
- (void)onNextPage:(UIButton *)sender;

@end