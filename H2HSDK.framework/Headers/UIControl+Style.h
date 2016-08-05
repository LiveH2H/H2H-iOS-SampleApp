//
//  UIControl+Style.h
//  H2H
//
//  Created by Sagar Kasture on 01/03/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <UIKit/UIKit.h>

#pragma mark - UINavigationBar
@interface UINavigationBar (Style)
typedef NS_ENUM(NSUInteger, UINAVIGATIONBAR_STYLE)
{
    UINAVIGATIONBAR_STYLE_ASR
};
-(void) setStyle:(UINAVIGATIONBAR_STYLE)style;
@end

#pragma mark - UIView
@interface UIView (Style)
typedef NS_ENUM(NSUInteger, UIVIEW_STYLE)
{
    UIVIEW_STYLE_JOIN_MEETING,
    UIVIEW_STYLE_JOIN_MEETING_CONTENT,
    UIVIEW_STYLE_USER_MESSAGE_BACKGROUND,
    UIVIEW_STYLE_PARTICIPANT_MESSAGE_BACKGROUND,
    UIVIEW_STYLE_PARTICIPANT_MESSAGE_BACKGROUND_PLAIN,
    UIVIEW_STYLE_USER_MESSAGE_BACKGROUND_PLAIN
};
-(void) setStyle:(UIVIEW_STYLE)style;
@end

#pragma mark - UILabel
@interface UILabel (Style)
typedef NS_ENUM(NSUInteger, UILABEL_STYLE)
{
    UILABEL_STYLE_JOIN_MEETING_TITLE,
    UILABEL_STYLE_JOIN_MEETING_ERROR,
    UILABEL_STYLE_CHAT_TITLE,
    UILABEL_STYLE_USER_MESSAGE,
    UILABEL_STYLE_PARTICIPANT_MESSAGE,
    UILABEL_STYLE_JOIN_MEETING_FOOTER,
    UILABEL_STYLE_JOIN_MEETING_PLACEHOLDER
};
-(void) setStyle:(UILABEL_STYLE)style;
@end

#pragma mark - UITextField
@interface UITextField (Style)
typedef NS_ENUM(NSUInteger, UITEXTFIELD_STYLE)
{
    UITEXTFIELD_STYLE_JOIN_MEETING
};
-(void) setStyle:(UITEXTFIELD_STYLE)style;
@end

#pragma mark - UITextView
@interface UITextView (Style)
typedef NS_ENUM(NSUInteger, UITEXTVIEW_STYLE)
{
    UITEXTVIEW_STYLE_USER_MESSAGE,
    UITEXTVIEW_STYLE_PARTICIPANT_MESSAGE
};
-(void) setStyle:(UITEXTVIEW_STYLE)style;
@end

#pragma mark - UIButton
@interface UIButton (Style)
typedef NS_ENUM(NSUInteger, UIBUTTON_STYLE)
{
    UIBUTTON_STYLE_JOIN_MEETING,
    UIBUTTON_STYLE_VIDEO_VIEW_TOGGLE
};
-(void) setStyle:(UIBUTTON_STYLE)style;
@end

#pragma mark - UITableView
@interface UITableView (Style)
typedef NS_ENUM(NSUInteger, UITABLEVIEW_STYLE)
{
    UITABLEVIEW_STYLE_MESSAGES
};
-(void) setStyle:(UITABLEVIEW_STYLE)style;
@end

#pragma mark - UITableViewCell
@interface UITableViewCell (Style)
typedef NS_ENUM(NSUInteger, UITABLEVIEWCELL_STYLE)
{
    UITABLEVIEWCELL_STYLE_MESSAGES
};
-(void) setStyle:(UITABLEVIEWCELL_STYLE)style;
@end