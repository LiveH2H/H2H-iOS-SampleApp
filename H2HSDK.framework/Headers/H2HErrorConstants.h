//
//  H2HErrorConstants.h
//  H2H
//
//  Created by Sagar Kasture on 09/06/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#ifndef H2HErrorConstants_h
#define H2HErrorConstants_h

/**
 *  Enum to identify error type
 */
typedef NS_ENUM(NSUInteger, H2HERROR_TYPE) {
    /**
     *  No specified error type.
     */
    H2HERROR_TYPE_NONE,
    
    /**
     *  server side error.
     */
    H2HERROR_TYPE_SERVER,
    
    /**
     *  error from XMPP or chat module.
     */
    H2HERROR_TYPE_CHAT,
    
    /**
     *  error from webRTC framework.
     */
    H2HERROR_TYPE_WEBRTC,
    
    /**
     *  error from application side.
     */
    H2HERROR_TYPE_APP,
    
    /**
     *  Information
     */
    H2HERROR_TYPE_INFO,
    
    /**
     *  Warning
     */
    H2HERROR_TYPE_WARNING,
    
    H2HERROR_TYPE_WEB_SERVICE_PARSE
};

/**
 *  Enum for severity of the error. This value will decide the type of action to be taken.
 */
typedef NS_ENUM(NSUInteger, H2HERROR_SEVERITY) {
    /**
     *  No action is to be taken.
     */
    H2HERROR_SEVERITY_NO_ACTION,
    
    /**
     *  For this severity level, we will leave the meeting and display an alert.
     */
    H2HERROR_SEVERITY_ABORT_MEETING,
    
    /**
     *  Only alert will be displayed. No action will be taken on alert.
     */
    H2HERROR_SEVERITY_SHOW_ALERT
};

#endif /* H2HErrorConstants_h */
