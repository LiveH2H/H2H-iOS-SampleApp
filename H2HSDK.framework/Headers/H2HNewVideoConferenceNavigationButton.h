//
//  H2HNewVideoConferenceNavigationButton.h
//  H2H
//
//  Created by Anton Ostrovskii on 8/22/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_OPTIONS(NSUInteger, H2HNewVideoConferenceNavigationButtonDirection) {
    H2HNewVideoConferenceNavigationButtonDirectionNone = 0,
    H2HNewVideoConferenceNavigationButtonDirectionPrevious = 1 << 0,
    H2HNewVideoConferenceNavigationButtonDirectionNext = 2 << 0
};

@class H2HNewVideoConferenceNavigationButton;

@protocol H2HNewVideoConferenceNavigationButtonDelegate <NSObject>
@required
- (void)videoConferenceNavigationButtonTouched:(H2HNewVideoConferenceNavigationButton *)sender;
@end

@interface H2HNewVideoConferenceNavigationButton : UIButton

- (id)initWithDirection:(H2HNewVideoConferenceNavigationButtonDirection)direction;
- (id)initWithDirection:(H2HNewVideoConferenceNavigationButtonDirection)direction andText:(NSString *)text;
- (id)initWithDirection:(H2HNewVideoConferenceNavigationButtonDirection)direction andText:(NSString *)text andDelegate:(id<H2HNewVideoConferenceNavigationButtonDelegate>)delegate;

@property (nonatomic, readonly) H2HNewVideoConferenceNavigationButtonDirection direction;
@property (nonatomic, setter=setText:, getter=getText) NSString *text;
@property (nonatomic, weak) id<H2HNewVideoConferenceNavigationButtonDelegate> delegate;

@end