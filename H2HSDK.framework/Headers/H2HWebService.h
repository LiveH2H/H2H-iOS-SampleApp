//
//  H2HWebService.h
//  H2H
//
//  Created by Sagar Kasture on 14/04/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "H2HWebServiceDelegate.h"
#import "H2HErrorObject.h"
#import "Reachability.h"

@interface H2HWebService : NSObject
/**
 * Reference to sender of request.Once response is received call back will be given on this object.
 */
@property(nonatomic,weak) id<H2HWebServiceDelegate> delegate ;

/**
 * @brief This is init method to create instance of this class.This must be called by in child class's init method.
 *
 * @param path Url path component for request
 * @param headers HTTP header fields specific to request
 * @param body HTTP Body of request it could be Json or key value encoded string.
 * @param requestType HTTP Request type 'GET' or 'POST'
 *
 * @return Instance of class.
 */
-(id)initWithRequest:(NSString*)path
              header:(NSDictionary*)headers
                body:(id)body
        RequestType :(NSString *)requestType
          andBaseURL:(NSString*) baseURL ;

/**
 * @brief Parses response.
 *
 * @details This method will be implemented by child classes and have their own parsing logic.
 *
 * @param response of request in dictionary format.
 *
 * @return
 */
-(void)parseResponse:(NSDictionary *)response ;

/**
 * @brief Parses response.
 *
 * @details This method will be implemented by child classes and have their own parsing logic.
 *
 * @param response of request in dictionary format.
 *
 * @param HMError
 *      $hmError -In case of failer of error will be sent in this param.
 *
 * @return
 */
-(void)parseAsyncResponse:(NSDictionary *)response andError:(H2HErrorObject**)error;

/**
 * @brief Sends synchronous webservice request.
 *
 * @details This method will send synchronous request.
 *
 * @param HMError
 *      $hmError -In case of failer of error will be sent in this param.
 * @return Response in NSDictionary format.
 */
-(void)sendSyncRequest:(H2HErrorObject**)error;


/**
 * @brief Sends synchronous webservice request.
 *
 * @details This method will send synchronous request.
 *
 * @param error - In case of failer of error will be sent in this param.
 *
 * @return void.
 */
-(void)sendAsyncRequest:(H2HErrorObject**)error;

/**
 * @brief sends response to caller of webservice
 *
 * @details This method is called by subclass once response parsing is complete.
 *
 * @param id
 *      $response -Model object created from response
 * @return
 */
-(void) sendResponse:(id)response;
@end
