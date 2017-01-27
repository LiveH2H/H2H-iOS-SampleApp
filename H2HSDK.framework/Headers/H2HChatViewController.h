//
//  H2HChatViewController.h
//  H2H
//
//  Created by Sagar Kasture on 08/03/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <UIKit/UIKit.h>

@class H2HChatViewController;

@protocol H2HChatViewControllerDelegate <NSObject>
@optional
- (BOOL)isVisible;
- (BOOL)isGridModeVisible;
- (void)chatViewController:(H2HChatViewController *)sender chatModeChanged:(ChatMode)chatMode;
- (void)chatViewController:(H2HChatViewController *)sender chatViewModeChanged:(H2HNewChatViewMode)chatViewMode;
- (void)chatViewController:(H2HChatViewController *)sender keyboardVisibilityChangedTo:(BOOL)isKeyboardVisible;
@end

@protocol H2HOverlayChatViewControllerDelegate <NSObject>
@required
- (void)moveUpOverLayChat:(NSNotification*)aNotification;
- (void)moveDownOverLayChat:(NSNotification*)aNotification;
@end

@interface H2HChatViewController : UIViewController
-(void) replayToMessage;
- (void)replyToMessageWithText:(NSString *)text;
- (void)markReadForCurrentChat;
- (void)startChatClientConnection;

@property (weak, nonatomic) id<H2HOverlayChatViewControllerDelegate> overlayChatDelegate;
@property (weak, nonatomic) id<H2HChatViewControllerDelegate> chatDelegate;
@property (nonatomic, setter=setMode:, getter=getMode) ChatMode mode;
@property (nonatomic, setter=setViewMode:, getter=getViewMode) H2HNewChatViewMode viewMode;

@property (nonatomic) ChatModeForIphone viewModeiPhone;

@property (nonatomic, setter=setBackground:) UIColor *background;
@property (nonatomic, setter=setTransparent:) BOOL transparent;
@property (weak, nonatomic) IBOutlet UITextView *textViewMessage;

@property (weak, nonatomic) IBOutlet NSLayoutConstraint *constraintTableViewTop;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *constraintToolBarHeight;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *constraintToolBarTop;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *constraintHeightHeaderView;

@property (nonatomic) BOOL isLiveChatOn;

// this method is used to prepare initial ui setup for chat view
-(void)prepareChatView;

@end