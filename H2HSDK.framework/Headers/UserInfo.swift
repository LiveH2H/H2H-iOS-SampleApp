//
//  UserInfo.swift
//  H2H
//
//  Created by charuta.rajopadhye on 15/09/16.
//  Copyright © 2016 Tutor Group. All rights reserved.
//

import Foundation

public class UserInfo : NSObject {
    
    public var recordingDefault: NSNumber
    public var isCtAdmin: NSNumber
    public var isAdmin: NSNumber
    public var apiToken: String
    public var uploadLimit: NSNumber
    public var screenName: String
    public var attendeesLimit: NSNumber
    public var countryCode: String
    public var accountType: NSNumber
    public var avatar: String
    public var returnCode: NSNumber
    public var logo: NSNumber
    public var timeZone: String
    public var token: String
    public var userId: NSNumber
    public var accountSn: NSNumber
    public var email: String
    public var name: String
    public var isSystemChecked: NSNumber
    public var phone: String
    
    public init ( recordingDefault: NSNumber,
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