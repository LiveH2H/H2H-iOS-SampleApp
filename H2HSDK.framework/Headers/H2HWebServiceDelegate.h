//
//  H2HWebServiceDelegate.h
//  H2H
//
//  Created by Sagar Kasture on 14/04/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#ifndef H2HWebServiceDelegate_h
#define H2HWebServiceDelegate_h

#import "H2HErrorObject.h"

@class H2HWebService;

@protocol H2HWebServiceDelegate <NSObject>

@required

/**
 * @brief Request sucessfully executed callback
 *
 * @details This method is required method .The class that sends webservice request must implement this method.
 *
 * @param responseModel web service response will be stored in this DS
 *
 * @return
 */

-(void)requestSucceed:(H2HWebService*)webService response:(id)responseModel;
/**
 * @brief Request failed callback
 *
 * @details This method is required method .The class that sends webservice request must implement this method.
 *
 * @param error Error or exception occured while sending webservice request.
 *
 * @return
 */
-(void)requestFailed:(H2HWebService*)webService error:(H2HErrorObject*)error ;

@end
#endif /* H2HWebServiceDelegate_h */
