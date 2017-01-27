//
//  H2HContactPickerTableViewCell.h
//  H2H
//
//  Created by aditya.deshmane on 19/10/16.
//  Copyright © 2016 Tutor Group. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface H2HContactPickerTableViewCell : UITableViewCell

-(void) setName:(NSString*) name andEmailAddress:(NSString*) emailAddress withSelected:(BOOL) isSelected;

-(void) setCellSelected:(BOOL) isSelected;

@end
