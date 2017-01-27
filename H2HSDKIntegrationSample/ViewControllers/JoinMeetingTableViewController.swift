//
//  JoinMeetingTableViewController.swift
//  H2HSDKIntegrationSample
//
//  Created by charuta.rajopadhye on 25/07/16.
//  Copyright © 2016 Spring Computing Technologies. All rights reserved.
//

import Foundation
import UIKit
import H2HSDK

class JoinMeetingTableViewController : UITableViewController {
    
    // MARK: IBOutlets
    @IBOutlet weak var textFieldEmail: UITextField!
    
    @IBOutlet weak var textFieldMeetingID: UITextField!
    
    // MARK: Lifecycle methods
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // set view controller title & color
        self.navigationItem.title = "Join Meeting"
        self.navigationController?.navigationBar.tintColor
            = UIColor(red: 255/255.0, green: 107/255.0, blue: 100/255.0, alpha: 1.0)
    }

    // MARK: IBActions
    @IBAction func buttonJoinMeetingClicked(sender: AnyObject) {

//        hard code here or fetech data from UI
//        self.textFieldEmail.text = "h2h1@sharklasers.com"
//        self.textFieldMeetingID.text = "0816870757"
        
        self.view.endEditing(true)

        if self.textFieldEmail.text != "" && self.textFieldMeetingID.text != ""
        {
            // display activity indicator
            dispatch_async(dispatch_get_main_queue()) {
                GUIUtility.sharedInstance.displayLoadingView()
            }
            
            // this method calls web services that fetch information that we need to pass to the H2HSDK
            // parameters it takes:
            // 1. meeting id entered by the user
            // 2. email id entered by the user
            // 3. view controller to present the View onto.
            self.joinMeetingWithEmailOnly(self.textFieldMeetingID.text!, email: self.textFieldEmail.text!, fromViewController: self)
        }
    }
    
    // MARK: Utility methods for web service calls
    
    // searches given meeting, joins it while loading the UI on provided view controller
    func joinMeetingWithEmailOnly (meetingId:String, email:String, fromViewController:UIViewController?) -> Void
    {
        // search meeting web service call
        // that searches meeting with given meeting ID
        searchMeetingWith (meetingId, completionHandler: { (responseDictionary, responseUrl, error) in
            
            if(responseDictionary != nil)
            {
                // web service success if returnCode = 0
                let returnCode = responseDictionary!["returnCode"] as? NSNumber
                if returnCode != nil && returnCode?.intValue == 0
                {
                    // collect server URL
                    let serverURL = responseDictionary!["serverURL"] as? String
                    
                    // joins meeting with provided meeting ID
                    self.joinMeetingByEmail(meetingId, email: email, completionHandler: { (responseDictionary, responseUrl, error) in
                        
                        if responseDictionary != nil
                        {
                            // web service success if returnCode = 0
                            let returnCode = responseDictionary!["returnCode"] as? NSNumber
                            if returnCode != nil && returnCode?.intValue == 0
                            {
                                // collect meetingUri, referrer and origin
                                // to pass it to the SDK
                                let meetingUri = responseDictionary!["meetingUri"] as? String
                                let referrer = responseDictionary!["referer"] as? String
                                let origin = responseDictionary!["origin"] as? String
                                
                                dispatch_async(dispatch_get_main_queue(), {
                                    
                                    // hide activity indicator
                                    GUIUtility.sharedInstance.hideLoadingView()

                                    // call method from the H2HSDK with collected information
                                    H2HSDKExt.sharedInstance().joinMeetingWithToken( meetingUri,
                                                                                     onServer: serverURL,
                                                                                     usingOrigin: origin,
                                                                                     withReferrer: referrer,
                                                                                     fromViewController: fromViewController)
                                })
                            }
                            else if let message = responseDictionary!["message"]
                            {
                                print("Join meeting failed, error message:\(message)")
                                GUIUtility.sharedInstance.dismissLoadingAndDisplayAlertWith( "Error: Join meeting failed",
                                    message: message as! String)

                            }
                            else
                            {
                                print("Join meeting failed")
                                GUIUtility.sharedInstance.dismissLoadingAndDisplayAlertWith( "Error",
                                    message: "Join meeting failed")
                            }
                        }
                        else
                        {
                            print("Join meeting failed")
                            GUIUtility.sharedInstance.dismissLoadingAndDisplayAlertWith( "Error",
                                message: "Join meeting failed, no response data")
                        }
                        
                    })
                    
                }
                else if let message = responseDictionary!["message"]
                {
                    print("Search meeting failed, error message:\(message)")
                    GUIUtility.sharedInstance.dismissLoadingAndDisplayAlertWith( "Error: Search meeting failed",
                        message: message as! String)
                }
                else
                {
                    print("Search meeting failed")
                    GUIUtility.sharedInstance.dismissLoadingAndDisplayAlertWith( "Error",
                        message: "Search meeting failed")
                }
            }
            else
            {
                print("Search meeting failed")
                GUIUtility.sharedInstance.dismissLoadingAndDisplayAlertWith( "Error",
                    message: "Search meeting failed, no response data")
            }
        })
        
    }
    
    // searches given meeting, joins it while loading the UI on provided view controller
    func joinMeetingWithDisplayName (meetingId:String, displayName:String, email:String?, phone:String?, fromViewController:UIViewController?)-> Void
    {
        searchMeetingWith(meetingId, completionHandler: { (responseDic, responseUrl, error) in
            
            if(responseDic != nil)
            {
                let returnCode = responseDic!["returnCode"] as? NSNumber
                if returnCode != nil && returnCode?.intValue == 0
                {
                    let serverURL = responseDic!["serverURL"] as? String
                    
                    self.joinInstantMeetingWith( meetingId, displayName: displayName, email: email, phone: phone, completionHandler: { (responseDictionary, responseUrl, error) in
                        
                        if(responseDictionary != nil)
                        {
                            let returnCode = responseDictionary!["returnCode"] as? NSNumber
                            if returnCode != nil && returnCode?.intValue == 0
                            {
                                let meetingUri = responseDictionary!["meetingUri"] as? String
                                let referrer = responseDictionary!["referer"] as? String
                                let origin = responseDictionary!["origin"] as? String
                                
                                
                                dispatch_async(dispatch_get_main_queue(), {
                                    H2HSDKExt.sharedInstance().joinMeetingWithToken ( meetingUri,
                                                                                      onServer: serverURL,
                                                                                      usingOrigin: origin,
                                                                                      withReferrer: referrer,
                                                                                      fromViewController: fromViewController)
                                })
                                
                            }
                            else if let message = responseDictionary!["message"]
                            {
                                print("Join meeting failed, error message:\(message)")
                                GUIUtility.sharedInstance.dismissLoadingAndDisplayAlertWith( "Error: Join meeting failed",
                                                                                             message: message as! String)
                            }
                            else
                            {
                                print("Join meeting failed")
                                GUIUtility.sharedInstance.dismissLoadingAndDisplayAlertWith( "Error",
                                                                                             message: "Join meeting failed")
                            }
                        }
                        else
                        {
                            print("Join meeting failed")
                            GUIUtility.sharedInstance.dismissLoadingAndDisplayAlertWith( "Error",
                                                                                         message: "Join meeting failed, no response data")
                        }
                        
                    })
                }
                else if let message = responseDic!["message"]
                {
                    print("Search meeting failed, error message:\(message)")
                    GUIUtility.sharedInstance.dismissLoadingAndDisplayAlertWith( "Error: Search meeting failed",
                                                                                 message: message as! String)
                }
                else
                {
                    print("Search meeting failed")
                    GUIUtility.sharedInstance.dismissLoadingAndDisplayAlertWith( "Error",
                        message: "Search meeting failed")
                }
            
            }
            else
            {
                print("Search meeting failed")
                GUIUtility.sharedInstance.dismissLoadingAndDisplayAlertWith( "Error",
                                                                             message: "Search meeting failed, no response data")
            }
            
        })
    }
    
    // searches for meeting with given meeting ID
    private func searchMeetingWith ( meetingId:String, completionHandler:(NSDictionary?, NSURLResponse?, NSError?)-> Void )
    {
        // request URL
        let urlString = "\(H2HServerURL)corpmeeting.do"
        
        // request parameters
        let params = [ "action":"searchMeetingById",
                       "meetingId":meetingId
                     ]
        
        requestWithURL(urlString, params: params, completionHandler: { (responseDictionary, responseUrl, error) in
            
            completionHandler(responseDictionary, responseUrl, error)
            
        })
    }
    
    // joins meeting with meeting ID and email provided
    private func joinMeetingByEmail ( meetingId:String, email:String, completionHandler:(NSDictionary?, NSURLResponse?, NSError?)-> Void )
    {
        // request URL
        let urlString = "\(H2HServerURL)message.do"

        // request parameters
        let params = [
                       "action": "joinMeetingByEmail",
                       "meetingId": meetingId,
                       "email": email
                      ]
        
        requestWithURL(urlString, params: params, completionHandler: { (responseDictionary, responseUrl, error) in
            
            completionHandler(responseDictionary, responseUrl, error)
        })
    }
    
    // joins meeting with meetingId, displayName, email, phone provided
    private func joinInstantMeetingWith( meetingId:String, displayName:String, email:String?, phone:String?, completionHandler:(NSDictionary?, NSURLResponse?, NSError?) -> Void )
    {
        // request URL
        let urlString = "\(H2HServerURL)corpmeeting.do"
        
        // request parameters
        var params = [ "action": "joinInstantMeeting",
                       "name": displayName,
                       "meetingId": meetingId
                     ]
        
        // if email is provided add email to params
        if let emailString = email {
            params["email"] = emailString
        }
        
        requestWithURL(urlString, params: params, completionHandler: { (responseDictionary, responseUrl, error) in
            
            completionHandler(responseDictionary, responseUrl, error)
        })
    }
    
    // boilerplate method for web service calls
    private func requestWithURL ( urlString:String, params:Dictionary<String, AnyObject>, completionHandler:(NSDictionary?, NSURLResponse?, NSError?) -> Void )
    {
        // request URL
        let components:NSURLComponents! = NSURLComponents(string: urlString)
        
        var jsonData:NSData? = nil
        do
        {
            // convert params to NSData
            jsonData = try NSJSONSerialization.dataWithJSONObject(params, options: [])
            
        }
        catch let error as NSError
        {
            GUIUtility.sharedInstance.dismissLoadingAndDisplayAlertWith( "Error: JSON Parsing",
                                                                         message: error.localizedDescription)
            print("json error: \(error.localizedDescription)")
            return
        }
        let jsonString = String.init(data: jsonData!, encoding: NSUTF8StringEncoding)
        
        // add json query item
        let queryItems:[NSURLQueryItem] = [NSURLQueryItem.init(name: "json", value: jsonString)]
        components.queryItems = queryItems
        
        let request:NSMutableURLRequest! = NSMutableURLRequest.init(URL: components.URL!, cachePolicy: .UseProtocolCachePolicy, timeoutInterval: 60.0)
        
        let postDataTask = NSURLSession.sharedSession().dataTaskWithRequest(request, completionHandler: { (data, response, error) in
            
            do
            {
                if let dataUnwraped = data
                {
                    // convert response data to NSDictionary
                    let jsonDictionary = try NSJSONSerialization.JSONObjectWithData(dataUnwraped, options: [])
                    completionHandler(jsonDictionary as? NSDictionary, response, error)
                }
                else
                {
                    var errorString: String = "Server not available, please try again later"
                    if let errorUnrapped = error
                    {
                        errorString = errorUnrapped.localizedDescription
                    }
                    GUIUtility.sharedInstance.dismissLoadingAndDisplayAlertWith( "Error: No data recieved",
                        message: errorString)
                }
            }
            catch let error as NSError {
                print("json error: \(error.localizedDescription)")

                GUIUtility.sharedInstance.dismissLoadingAndDisplayAlertWith( "Error: JSON Parsing",
                                                                             message: error.localizedDescription)
            }
            
        })
        
        postDataTask.resume()
    }
    
    // MARK: TextField delegate
    func textFieldShouldReturn(textField: UITextField) -> Bool {
        self.view.endEditing(true)
        return false
    }
}
