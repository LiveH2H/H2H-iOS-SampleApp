//
//  H2HChatPopUpCell.h
//  H2H
//
//  Created by FauadAnwar on 31/03/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface H2HChatPopUpCell : UITableViewCell
@property (weak, nonatomic) IBOutlet UILabel *labelName;
@property (weak, nonatomic) IBOutlet UILabel *labelCount;
@property (weak, nonatomic) IBOutlet UIImageView *badgeIcon;

@end
