//
//  H2HHTTPCommunication.h
//  H2H
//
//  Created by Sagar Kasture on 14/04/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol HTTPCommunicationProtocol<NSObject>

//handle async response
- (void)receivedAsyncResponse:(NSData *)receivedData andError:(H2HErrorObject**)error;

@end

@interface H2HHTTPCommunication : NSObject

@property (nonatomic, weak) id <HTTPCommunicationProtocol> delegate;
/**
 * @brief Server hostname.
 *
 */
@property(nonatomic,copy)NSString *baseServerUrl ;

/*!
 * @discussion This is init method to create instance of this class.This must be called by in child class's init method.
 *
 * @param path Url path component for request
 * @param headers HTTP header fields specific to request
 * @param body HTTP Body of request or encoded string with key value
 * @param requestType HTTP Request type 'GET' or 'POST'
 *
 * @return Instance of class.
 */
-(id)initWithRequest:(NSString*)path
              header:(NSDictionary*)headers
                body:(id)body
        RequestType :(NSString *)requestType;

/**
 * @discussion Sends synchronous webservice request.
 * @param error - In case of failer of error will be sent in this param.
 * @return NSData is response to the synchronous request.
 */
-(NSData *)sendSyncRequest:(H2HErrorObject**)error;

/**
 * @discussion Sends asynchronous webservice request.
 * @param errorObj - In case of failer of error will be sent in this param.
 * @return void.
 */
- (void)sendAsyncRequest:(H2HErrorObject**)errorObj;
@end
