//
//  H2HWebViewCellViewController.h
//  H2H
//
//  Created by Sagar Kasture on 14/01/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum
{
    WEB_CONTENT_TYPE_URL,
    WEB_CONTENT_TYPE_IMAGE
} WEB_CONTENT_TYPE;



@interface H2HWebCellViewController : UIViewController

@property NSString* stringURl;
@property WEB_CONTENT_TYPE webContentType;

@end
