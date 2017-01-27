//
//  H2HPhoneToolbarViewController.h
//  H2H
//
//  Created by Aditya Deshmane on 23/08/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol H2HCustomToolbar <NSObject>

@end


@interface H2HPhoneToolbarViewController : UIViewController

@property(weak,nonatomic) UIViewController     *vcParent;

-(void)setParticipantBadgeIconVisibility:(BOOL)shouldShow;
-(void)setTranslatorButtonHidden:(BOOL)shouldHide;

@end