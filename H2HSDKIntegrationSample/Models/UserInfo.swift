//
//  UserInfo.swift
//  H2HSDKIntegrationSample
//
//  Created by charuta.rajopadhye on 28/07/16.
//  Copyright © 2016 Spring Computing Technologies. All rights reserved.
//

import Foundation

class UserInfo : NSObject {
    
    var recordingDefault: NSNumber
    var isCtAdmin: NSNumber
    var isAdmin: NSNumber
    var apiToken: String
    var uploadLimit: NSNumber
    var screenName: String
    var attendeesLimit: NSNumber
    var countryCode: String
    var accountType: NSNumber
    var avatar: String
    var returnCode: NSNumber
    var logo: NSNumber
    var timeZone: String
    var token: String
    var userId: NSNumber
    var accountSn: NSNumber
    var email: String
    var name: String
    var isSystemChecked: NSNumber
    var phone: String

    init ( recordingDefault: NSNumber,
           isCtAdmin: NSNumber,
           isAdmin: NSNumber,
           apiToken: String,
           uploadLimit: NSNumber,
           screenName: String,
           attendeesLimit: NSNumber,
           countryCode: String,
           accountType: NSNumber,
           avatar: String,
           returnCode: NSNumber,
           logo: NSNumber,
           timeZone: String,
           token: String,
           userId: NSNumber,
           accountSn: NSNumber,
           email: String,
           name:String,
           isSystemChecked: NSNumber,
           phone: String )
    {
        self.recordingDefault = recordingDefault
        self.isCtAdmin = isCtAdmin
        self.isAdmin = isAdmin
        self.apiToken = apiToken
        self.uploadLimit = uploadLimit
        self.screenName = screenName
        self.attendeesLimit = attendeesLimit
        self.countryCode = countryCode
        self.accountType = accountType
        self.avatar = avatar
        self.returnCode = returnCode
        self.logo = logo
        self.timeZone = timeZone
        self.token = token
        self.userId = userId
        self.accountSn = accountSn
        self.email = email
        self.name = name
        self.isSystemChecked = isSystemChecked
        self.phone = phone
    }
}