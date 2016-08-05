//
//  InitializeChatWebService.h
//  WebRTCWebService
//
//  Created by charuta.rajopadhye on 11/05/16.
//  Copyright © 2016 charuta.rajopadhye. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "H2HWebService.h"

@interface H2HInitializeChatWebService : H2HWebService

-(instancetype) initWithJID:(NSString *) jid
                      token:(NSString *) token
            displayUserName:(NSString *) displayUserName
                     origin:(NSString *) origin
                  meetingID:(NSString *) meetingID
               andPresenter:(BOOL)       isPresenter;

@end
