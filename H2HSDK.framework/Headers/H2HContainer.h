//
//  H2HContainer.h
//  H2H
//
//  Created by Sagar Kasture on 14/01/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

@interface H2HContainer : NSObject<NSCoding>

typedef enum
{
    CONTAINER_TYPE_NONE,
    CONTAINER_TYPE_WEB,
    CONTAINER_TYPE_CHAT,
    CONTAINER_TYPE_GOOGLE_DRIVE,
    CONTAINER_TYPE_DROPBOX,
    CONTAINER_TYPE_WHITEBOARD,
    CONTAINER_TYPE_VIDEO,
    CONTAINER_TYPE_IMAGE,
    CONTAINER_TYPE_ADD
}CONTAINER_TYPE;

@property (nonatomic, strong) NSString* title;
@property (nonatomic, assign) CONTAINER_TYPE type;
@property (nonatomic, assign) CGSize size;
@property (nonatomic, strong) NSObject* object;

@end