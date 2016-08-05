//
//  VideoCollectionViewCell.h
//  H2H
//
//  Created by Sagar Kasture on 26/02/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <TutorWebRTC/TutorWebRTC.h>
#import <UIKit/UIKit.h>

@interface VideoCollectionViewCell : UICollectionViewCell<RTCVideoViewDelegate>

@property (weak, nonatomic) IBOutlet UIImageView *blankVideoImageView;
@property (weak, nonatomic) IBOutlet RTCVideoView *videoView;
@property (strong) RTCUser *user;

@end
