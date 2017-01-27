//
//  H2HContactPickerViewController.h
//  H2H
//
//  Created by charuta.rajopadhye on 19/10/16.
//  Copyright © 2016 Tutor Group. All rights reserved.
//

#import <UIKit/UIKit.h>

@import Contacts;

@class H2HContactPickerViewController;

@protocol H2HContactPickerDelegate <NSObject>

- (void) H2HContactPicker:(H2HContactPickerViewController *)picker didSelectContacts:(NSArray<CNContact*> *)contacts;

@end

@interface H2HContactPickerViewController : UIViewController

@property (nonatomic, weak) id<H2HContactPickerDelegate> contactPickerDelegate;

@end
