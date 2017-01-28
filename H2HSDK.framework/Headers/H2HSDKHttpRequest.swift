//
//  H2HSDKHttpRequest.swift
//  H2H
//
//  Created by charuta.rajopadhye on 15/09/16.
//  Copyright © 2016 Tutor Group. All rights reserved.
//

import Foundation

// webservice constants
let actionScheduleMeeting = "scheduleMeeting"
let actionCreateMeeting = "createMeeting"
let actionJoinMeeting = "joinMeeting"
let actionUserSignUp = "userSignup"
let actionAuthUser = "authUser"
let actionInstantMeeting = "instantMeeting"
let actionSearchMeetingById = "searchMeetingById"
let actionJoinMeetingByEmail = "joinMeetingByEmail"

// server base URL
let ServerBaseURL = "http://52.53.238.68:8080/tutormeetweb/"

public class H2HSDKHttpRequest : NSObject
{
    // shared instance to access this class
    public static let sharedInstance = H2HSDKHttpRequest()
    
    // object recieved from login web service
    var userInfo: UserInfo?
    
    // MARK: Sign up
    public func signUpH2HUser (userName: String,
                               firstName: String,
                               lastName: String,
                               email: String,
                               password: String,
                               locale: String,
                               success:(successMessage: String ) -> Void,
                               failure: (errorMessage: String) -> Void)
    {
        // sign up ws url
        let urlString = "\(ServerBaseURL)message.do"
        
        // params to pass to sign up ws
        let params = [
            "action" : actionUserSignUp,
            "username":userName,
            "email":email,
            "firstName":firstName,
            "lastName":lastName,
            "password":password,
            "locale": locale
        ]
        
        requestWithURL(urlString, params: params, action: actionUserSignUp, completionHandler: { (responseAnyObject, responseUrl, error) in
            
            if let responseDictionary = responseAnyObject as? NSDictionary
            {
                // fetch message and return code recieved form the web service
                let message = responseDictionary["message"] as! String
                let returnCode = responseDictionary["returnCode"] as? NSNumber
                
                // if returnCode is 0
                // the web service has returned with success
                if returnCode != nil && returnCode?.intValue == 0
                {
                    success(successMessage: message)
                }
                else
                {
                    failure(errorMessage: message)
                }
            }
            else
            {
                if (error != nil) && (error?.localizedDescription.isEmpty == false)
                {
                    failure(errorMessage: (error?.localizedDescription)!)
                }
                else
                {
                    failure(errorMessage: "User signup failed.")
                }
            }
        })
    }
    
    // MARK: Login
    // calls login web service
    public func loginWith( email: String,
                           password: String,
                           success: (userInfo: UserInfo) -> Void,
                           failure: (errorMessage: String) -> Void)  {
        
        // request URL
        let urlString = "\(ServerBaseURL)corplogin.do"
        
        // request parameters
        let params = [
            "email": email,
            "password": password ]
        
        requestWithURL(urlString, params: params, action: actionAuthUser, completionHandler: { (responseAnyObject, responseUrl, error) in
            
            if let responseDictionary = responseAnyObject as? NSDictionary
            {
                // fetch message and return code recieved form the web service
                let returnCode = responseDictionary["returnCode"] as? NSNumber
                
                // if returnCode is 0
                // web service has returned with success
                if returnCode != nil && returnCode?.intValue == 0
                {
                    // fill the response in UserInfo model
                    // save this model
                    // 'apiToken' from this response is needed to be set in the header of start and schedule web services
                    // in order to identify the user
                    let userInfo = UserInfo(recordingDefault: responseDictionary["recordingDefault"] as! NSNumber,
                        isCtAdmin: responseDictionary["isCtAdmin"] as! NSNumber,
                        isAdmin: responseDictionary["isAdmin"] as! NSNumber,
                        apiToken: responseDictionary["apiToken"] as! String,
                        uploadLimit: responseDictionary["uploadLimit"] as! NSNumber,
                        screenName: responseDictionary["screenName"] as! String,
                        attendeesLimit: responseDictionary["attendeesLimit"] as! NSNumber,
                        countryCode: responseDictionary["countryCode"] as! String,
                        accountType: responseDictionary["accountType"] as! NSNumber,
                        avatar: responseDictionary["avatar"] as! String,
                        returnCode: responseDictionary["returnCode"] as! NSNumber,
                        logo: responseDictionary["logo"] as! NSNumber,
                        timeZone: responseDictionary["timeZone"] as! String,
                        token: responseDictionary["token"] as! String,
                        userId: responseDictionary["userId"] as! NSNumber,
                        accountSn: responseDictionary["accountSn"] as! NSNumber,
                        email: responseDictionary["email"] as! String,
                        name: responseDictionary["name"] as! String,
                        isSystemChecked: responseDictionary["isSystemChecked"] as! NSNumber,
                        phone: responseDictionary["phone"] as! String)
                    
                    // save user info
                    // so as to use the information in Start and Schedule web services
                    self.userInfo = userInfo
                    
                    success(userInfo: userInfo)
                }
                else
                {
                    let message = responseDictionary["message"] as? String
                    if (message != nil) && (message?.isEmpty == false)
                    {
                        failure(errorMessage: message!)
                    }
                    else
                    {
                        failure(errorMessage: "Login failed.")
                    }
                }
            }
            else
            {
                if (error != nil) && (error?.localizedDescription.isEmpty == false)
                {
                    failure(errorMessage: (error?.localizedDescription)!)
                }
                else
                {
                    failure(errorMessage: "Login failed.")
                }
            }
        })
    }
    
    // MARK: Start meeting
    public func startMeetingWith( description: String,
                                  isGroupMeeting: Bool,
                                  shouldRecordMeeting: Bool,
                                  subject: String,
                                  attendeesEmailList: NSArray,
                                  translatorList: NSArray,
                                  success: (serverURL: String, meetingUri: String, referrer: String, origin: String) -> Void,
                                  failure: (errorMessage: String) -> Void)
    {
        // group meeting
        var meetingType = 6
        if (isGroupMeeting == false)
        {
            // its a webinar
            meetingType = 2;
        }
        
        // create dictionary of all the provided parameters
        let params = [ "action" : actionCreateMeeting,
                       "groupList" :[],
                       "description" : description,
                       "location" : "TC" ,
                       "meetingType" : meetingType,
                       "recordMeeting" : shouldRecordMeeting,
                       "subject" : subject,
                       "emailList" : attendeesEmailList,
                       "translatorList" : translatorList ]
        
        // request URL
        let urlString = "\(ServerBaseURL)corpmeeting.do"
        
        self.requestWithURL(urlString, params: params, action: actionCreateMeeting, completionHandler: { (responseAnyObject, responseUrl, error) in
            
            if let responseDictionary = responseAnyObject as? NSDictionary
            {
                let returnCode = responseDictionary["returnCode"] as? NSNumber
                if returnCode != nil && returnCode?.intValue == 0
                {
                    let serverURL = responseDictionary["serverURL"] as? String
                    let meetingUri = responseDictionary["meetingUri"] as? String
                    let referrer = responseDictionary["referer"] as? String
                    let origin = responseDictionary["origin"] as? String
                    
                    success(serverURL: serverURL!, meetingUri: meetingUri!, referrer: referrer!, origin: origin!)
                }
                else
                {
                    let message = responseDictionary["message"] as? String
                    if (message != nil) && (message?.isEmpty == false)
                    {
                        failure(errorMessage: message!)
                    }
                    else
                    {
                        failure(errorMessage: "Start meeting failed.")
                    }
                }
            }
            else
            {
                if (error != nil) && (error?.localizedDescription.isEmpty == false)
                {
                    failure(errorMessage: (error?.localizedDescription)!)
                }
                else
                {
                    failure(errorMessage: "Starting meeting failed.")
                }
            }
        })
    }
    
    // MARK: Start instant meeting
    public func startInstantMeetingWith (displayName: String,
                                         email: String?,
                                         locale: String,
                                         success: (serverURL: String, meetingUri: String, referrer: String, origin: String) -> Void,
                                         failure: (errorMessage: String) -> Void)
    {
        // request URL
        let urlString = "\(ServerBaseURL)corpmeeting.do"
        
        // request parameters
        var params = [ "action": actionInstantMeeting,
                       "name":   displayName,
                       "locale": locale,
                       "app":    "meet"
        ]
        
        // if email is provided add email to params
        if let emailString = email {
            params["email"] = emailString
        }
        
        requestWithURL(urlString, params: params, action: actionInstantMeeting, completionHandler: { (responseAnyObject, responseUrl, error) in
            
            if let responseDictionary = responseAnyObject as? NSDictionary
            {
                let returnCode = responseDictionary["returnCode"] as? NSNumber
                if returnCode != nil && returnCode?.intValue == 0
                {
                    let serverURL = responseDictionary["serverURL"] as? String
                    let meetingUri = responseDictionary["meetingUri"] as? String
                    let referrer = responseDictionary["referer"] as? String
                    let origin = responseDictionary["origin"] as? String
                    
                    success(serverURL: serverURL!, meetingUri: meetingUri!, referrer: referrer!, origin: origin!)
                    
                }
                else
                {
                    let message = responseDictionary["message"] as? String
                    if (message != nil) && (message?.isEmpty == false)
                    {
                        failure(errorMessage: message!)
                    }
                    else
                    {
                        failure(errorMessage: "Starting instant meeting failed.")
                    }
                }
            }
            else
            {
                if (error != nil) && (error?.localizedDescription.isEmpty == false)
                {
                    failure(errorMessage: (error?.localizedDescription)!)
                }
                else
                {
                    failure(errorMessage: "Starting instant meeting failed.")
                }
            }
        })
    }
    
    // MARK: Search meeting
    private func searchMeetingWith( meetingID: String,
                                   success: (serverURL: String) -> Void,
                                   failure: (errorMessage: String) -> Void)
    {
        // request URL
        let urlString = "\(ServerBaseURL)corpmeeting.do"
        
        // request parameters
        let params = [ "action": actionSearchMeetingById,
                       "meetingId": meetingID
        ]
        
        requestWithURL(urlString, params: params, action: actionSearchMeetingById, completionHandler: { (responseAnyObject, responseUrl, error) in
            
            if let responseDictionary = responseAnyObject as? NSDictionary
            {
                // web service success if returnCode = 0
                let returnCode = responseDictionary["returnCode"] as? NSNumber
                if returnCode != nil && returnCode?.intValue == 0
                {
                    // collect server URL
                    let serverURL = responseDictionary["serverURL"] as? String
                    success(serverURL: serverURL!)
                }
                else
                {
                    let message = responseDictionary["message"] as? String
                    if (message != nil) && (message?.isEmpty == false)
                    {
                        failure(errorMessage: message!)
                    }
                    else
                    {
                        failure(errorMessage: "Search meeting failed")
                    }
                }
            }
            else
            {
                if (error != nil) && (error?.localizedDescription.isEmpty == false)
                {
                    failure(errorMessage: (error?.localizedDescription)!)
                }
                else
                {
                    failure(errorMessage: "Search meeting failed.")
                }
            }
        })
    }
    
    // MARK: Join meeting with email
    public func joinMeetingWithEmail (meetingId: String,
                                      email: String,
                                      success: (serverURL: String, meetingUri: String, referrer: String, origin: String) -> Void,
                                      failure: (errorMessage: String) -> Void)
    {
        // search meeting API call
        // that searches meeting with given meeting ID
        H2HSDKHttpRequest.sharedInstance.searchMeetingWith( meetingId,
                                                            success: { (serverURL) in
                                                                
        // search meeting returned with success, call join meeting API
        // request URL for join meeting
        let urlString = "\(ServerBaseURL)message.do"
                                                                
        // request parameters
        let params = [
            "action": actionJoinMeetingByEmail,
            "meetingId": meetingId,
            "email": email
         ]
                                                                
        self.requestWithURL(urlString, params: params, action: actionJoinMeetingByEmail, completionHandler: { (responseAnyObject, responseUrl, error) in
                                                                    
            if let responseDictionary = responseAnyObject as? NSDictionary
            {
                // web service success if returnCode = 0
                let returnCode = responseDictionary["returnCode"] as? NSNumber
                if returnCode != nil && returnCode?.intValue == 0
                {
                    // collect meetingUri, referrer and origin
                    let meetingUri = responseDictionary["meetingUri"] as? String
                    let referrer = responseDictionary["referer"] as? String
                    let origin = responseDictionary["origin"] as? String
                    
                    success(serverURL: serverURL, meetingUri: meetingUri!, referrer: referrer!, origin: origin!)
                }
                else
                {
                    let message = responseDictionary["message"] as? String
                    if (message != nil) && (message?.isEmpty == false)
                    {
                        failure(errorMessage: message!)
                    }
                    else
                    {
                        failure(errorMessage: "Join meeting failed.")
                    }
                }
            }
            else
            {
                if (error != nil) && (error?.localizedDescription.isEmpty == false)
                {
                    failure(errorMessage: (error?.localizedDescription)!)
                }
                else
                {
                    failure(errorMessage: "Join meeting failed.")
                }
            }
            
        })
    },
    failure: { (errorMessage) in
                                                                
        // search meeting returned with failure, display error message
        failure(errorMessage: errorMessage)
        
        })
     }
    
    // MARK: Join meeting with meeting id
    public func joinMeetingByMeetingID (meetingId: String,
                                        success: (serverURL: String, meetingUri: String, referrer: String, origin: String) -> Void,
                                        failure: (errorMessage: String) -> Void)
    {
        // search meeting API call
        // that searches meeting with given meeting ID
        self.searchMeetingWith( meetingId,
                                success: { (serverURL) in
                                    
        // if search meeting returns successfully, call join meeting
        // request URL for join meeting
        let urlString = "\(ServerBaseURL)corpmeeting.do"
                                    
        // request params
        let params = [
           "action": actionJoinMeeting,
           "meetingId": meetingId
        ]
                                    
        self.requestWithURL(urlString, params: params, action: actionJoinMeeting, completionHandler: { (responseAnyObject, responseUrl, error) in
                                        
        if let responseDictionary = responseAnyObject as? NSDictionary
        {
             let returnCode = responseDictionary["returnCode"] as? NSNumber
             if(returnCode != nil && returnCode?.intValue == 0)
             {
                // fetch meetingUri referrer origin
                let meetingUri = responseDictionary["meetingUri"] as? String
                let referrer = responseDictionary["referer"] as? String
                let origin = responseDictionary["origin"] as? String
                
                success(serverURL: serverURL, meetingUri: meetingUri!, referrer: referrer!, origin: origin!)
             }
             else
             {
                let message = responseDictionary["message"] as? String
                if (message != nil) && (message?.isEmpty == false)
                {
                    failure(errorMessage: message!)
                }
                else
                {
                    failure(errorMessage: "Join meeting failed.")
                }
            }
        }
        else
        {
            if (error != nil) && (error?.localizedDescription.isEmpty == false)
            {
                failure(errorMessage: (error?.localizedDescription)!)
            }
            else
            {
                failure(errorMessage: "Join returned with improper response.")
            }
        }
            
                                    })
                            },
                            failure: { (errorMessage) in
                
                                // search meeting returned with failure
                                failure(errorMessage: errorMessage)
                                
                                     })
    }
    
    // MARK: Schedule meeting
    public func scheduleMeetingWith( description: String,
                                     isGroupMeeting: Bool,
                                     shouldRecordMeeting: Bool,
                                     subject: String,
                                     attendeesEmailList: NSArray,
                                     translatorList: NSArray,
                                     startDateTime: NSDate,
                                     endDateTime: NSDate,
                                     success: (meetingID: String) -> Void,
                                     failure: (errorMessage: String) -> Void)
    {
        // group meeting
        var meetingType = 6
        if (isGroupMeeting == false)
        {
            // its a webinar
            meetingType = 2;
        }
        
        let timeZone = NSTimeZone.localTimeZone().name
        
        var start = startDateTime.timeIntervalSince1970
        start *= 1000.0
        let startTime = NSNumber( double: floor(start) )

        let shareDate = self.getUTCFormatDate(startDateTime) as String
        let length = self.getMeetingLengthInMinutes(startDateTime, endDate: endDateTime)
        
        // create dictionary of all the provided parameters
        let params = [ "action" : actionScheduleMeeting,
                       "groupList" :[],
                       "meetingSn" : "",
                       "timeZone" : timeZone,
                       "shareDate" : shareDate,
                       "startTime" : startTime,
                       "length" : length,
                       "description" : description,
                       "location" : "TC" ,
                       "meetingType" : meetingType,
                       "recordMeeting" : shouldRecordMeeting,
                       "subject" : subject,
                       "emailList" : attendeesEmailList,
                       "translatorList" : translatorList ]
        
        // request URL
        let urlString = "\(ServerBaseURL)corpmeeting.do"
        
        self.requestWithURL(urlString, params: params, action: actionScheduleMeeting, completionHandler: { (responseAnyObject, responseUrl, error) in
            
            if let responseDictionary = responseAnyObject as? NSDictionary
            {
                let returnCode = responseDictionary["returnCode"] as? NSNumber
                if(returnCode != nil && returnCode?.intValue == 0)
                {
                    let meetingID: String = responseDictionary["meetingId"] as! String
                    success(meetingID: meetingID)
                }
                else
                {
                    let message = responseDictionary["message"] as? String
                    if (message != nil) && (message?.isEmpty == false)
                    {
                        failure(errorMessage: message!)
                    }
                    else
                    {
                        failure(errorMessage: "Schedule meeting failed.")
                    }
                }
            }
            else
            {
                if (error != nil) && (error?.localizedDescription.isEmpty == false)
                {
                    failure(errorMessage: (error?.localizedDescription)!)
                }
                else
                {
                    failure(errorMessage: "Schedule meeting failed.")
                }
            }
        })
    }
    
    // MARK: Utility method
    // boilerplate method to for web service call
    private func requestWithURL(urlString:String, params:Dictionary<String, AnyObject>, action: String, completionHandler:(AnyObject?, NSURLResponse?, NSError?)->Void)
    {
        // request URL set
        let request : NSMutableURLRequest = NSMutableURLRequest (URL: NSURL(string: urlString)!)
        request.HTTPMethod = "POST"
        
        var jsonData:NSData? = nil
        do
        {
            // convert params to NSData
            jsonData = try NSJSONSerialization.dataWithJSONObject(params, options: [])
        }
        catch let error as NSError {
            completionHandler(nil, nil, error)
            return
        }
        
        // convert json in NSData to String
        let jsonString = String.init(data: jsonData!, encoding: NSUTF8StringEncoding)
        
        var body: String = ""
        if action == actionScheduleMeeting || action == actionCreateMeeting
        {
            body = "action=" + action + "&json=" + jsonString!
            
            // if action is of type: scheduleMeeting or createMeeting
            // set apiToken in the header
            // this api token is recieved from the login web service
            if let token = self.userInfo?.apiToken
            {
                request.setValue(token, forHTTPHeaderField: "apiToken")
            }
            else
            {
                request.setValue("", forHTTPHeaderField: "apiToken")
            }
        }
        else if action == actionJoinMeeting || action == actionUserSignUp
        {
            body = "json=" + jsonString!
        }
        else if action == actionAuthUser || action == actionInstantMeeting || action == actionSearchMeetingById || action == actionJoinMeetingByEmail
        {
            body = "action=" + action + "&json=" + jsonString!
        }
        
        // set request body
        let bodyEncoded : NSString = body.stringByAddingPercentEncodingWithAllowedCharacters(NSCharacterSet.URLHostAllowedCharacterSet())!
        let httpBody : NSData? = bodyEncoded.dataUsingEncoding(NSUTF8StringEncoding)
        request.HTTPBody = httpBody
        
        // set common other request headers
        request.setValue("application/x-www-form-urlencoded; charset=utf-8", forHTTPHeaderField: "Content-Type")
        request.setValue(NSString(format:"%llu", httpBody!.length) as String, forHTTPHeaderField: "Content-Length")
        
        let postDataTask = NSURLSession.sharedSession().dataTaskWithRequest(request, completionHandler: { (data, response, error) in
            
            do
            {
                if let dataUnrapped = data
                {
                    let jsonObject = try NSJSONSerialization.JSONObjectWithData(dataUnrapped, options: [])
                    
                    // json oject can eith be an array or a dictionary
                    let array = jsonObject as? NSMutableArray
                    if array == nil
                    {
                        let dict = jsonObject as? NSMutableDictionary
                        if(dict == nil)
                        {
                            let error = NSError(domain: "No Data", code: 0, userInfo: [NSLocalizedDescriptionKey:"No data recieved from server."])
                            completionHandler(nil, nil, error)
                        }
                        else
                        {
                            completionHandler(dict, response, error)
                        }
                    }
                    else
                    {
                        completionHandler(array, response, error)
                    }
                }
                else
                {
                    let error = NSError(domain: "No Data", code: 0, userInfo: [NSLocalizedDescriptionKey:"No data recieved from server."])
                    completionHandler(nil, nil, error)
                }
            }
            catch let error as NSError {
                completionHandler(nil, nil, error)
            }
        })
        
        postDataTask.resume()
    }
    
    // returns date in UTC format
    func getUTCFormatDate(date: NSDate) -> NSString {
        
        let dateFormatter = NSDateFormatter()
        let timeZone = NSTimeZone(name: "UTC")
        dateFormatter.timeZone = timeZone
        dateFormatter.dateFormat = "yyyy-MM-dd HH:mm:ss"
        return dateFormatter.stringFromDate(date)
    }
    
    // calculate meeting length
    func getMeetingLengthInMinutes(startDate: NSDate, endDate: NSDate) -> NSNumber {
        
        let timeIntervalLengthInSeconds = endDate.timeIntervalSinceDate(startDate)
        let lengthInMinutes = NSNumber( double: floor( timeIntervalLengthInSeconds/60 ) )
        return lengthInMinutes
    }
}
