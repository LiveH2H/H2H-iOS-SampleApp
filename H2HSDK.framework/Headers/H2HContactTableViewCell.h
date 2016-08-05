//
//  H2HContactTableViewCell.h
//  H2H
//
//  Created by FauadAnwar on 16/03/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface H2HContactTableViewCell : UITableViewCell

@property (weak, nonatomic) IBOutlet UIImageView *imageViewProfilePicture;
@property (weak, nonatomic) IBOutlet UILabel *labelName;
@property (weak, nonatomic) IBOutlet UIImageView *imageViewselectionImage;
@property (weak, nonatomic) IBOutlet UILabel *labelInitials;

@end
