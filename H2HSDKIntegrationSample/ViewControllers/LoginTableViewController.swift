//
//  LoginTableViewController.swift
//  H2HSDKIntegrationSample
//
//  Created by charuta.rajopadhye on 21/07/16.
//  Copyright © 2016 Spring Computing Technologies. All rights reserved.
//

import Foundation
import UIKit

class LoginTableViewController : UITableViewController {
    
    // MARK: IBOutlets
    @IBOutlet weak var textFieldEmail: UITextField!
    
    @IBOutlet weak var textFieldPassword: UITextField!
    
    
    // MARK: Lifecycle methods
    override func viewDidLoad() {
        super.viewDidLoad()
    
        // set view controller title & color
        self.navigationItem.title = "Login"
        self.navigationController?.navigationBar.tintColor
            = UIColor(red: 255/255.0, green: 107/255.0, blue: 100/255.0, alpha: 1.0)
    }
    
    // MARK: IBActions
    @IBAction func buttonLoginClicked(sender: AnyObject) {
        
//        hard code data here, or fetch from the UI
//        textFieldEmail.text = "h2h1@sharklasers.com"
//        textFieldPassword.text = "h2h1"
        
        self.view.endEditing(true)

        if textFieldEmail.text != "" &&
           textFieldPassword.text != ""
        {
            // display activity indicator
            dispatch_async(dispatch_get_main_queue()) {
                GUIUtility.sharedInstance.displayLoadingView()
            }

            // call login web service
            // this method needs 2 parameters:
            // 1. email address
            // 2. password
            self.loginWith( textFieldEmail.text!,
                            password: textFieldPassword.text!)
        }
    }
    
    // boilerplate method to for web service call
    private func requestWithURL( urlString:String, params:Dictionary<String, AnyObject>, completionHandler:(NSDictionary?, NSURLResponse?, NSError?) ->Void )
    {
        // create request with URL
        let request : NSMutableURLRequest = NSMutableURLRequest(URL: NSURL(string: urlString)!)
        // set request method
        request.HTTPMethod = "POST"

        var jsonData:NSData? = nil
        do
        {
            // convert params to NSData
            jsonData = try NSJSONSerialization.dataWithJSONObject(params, options: [])
            
        }
        catch let error as NSError {
            
            GUIUtility.sharedInstance.dismissLoadingAndDisplayAlertWith( "Error: JSON Parsing",
                                                                         message: error.localizedDescription)
            print("json error: \(error.localizedDescription)")
            return
        }
        
        // set request body
        // convert json in NSData to String
        let jsonString = String.init(data: jsonData!, encoding: NSUTF8StringEncoding)
        let body = "action=authUser&json=" + jsonString!
        let bodyEncoded : NSString = body.stringByAddingPercentEncodingWithAllowedCharacters(NSCharacterSet.URLHostAllowedCharacterSet())!
        let httpBody : NSData? = bodyEncoded.dataUsingEncoding(NSUTF8StringEncoding)
        request.HTTPBody = httpBody
        
        // set request headers
        request.setValue("application/x-www-form-urlencoded; charset=utf-8", forHTTPHeaderField: "Content-Type")
        request.setValue(NSString(format:"%llu", httpBody!.length) as String, forHTTPHeaderField: "Content-Length")
        
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
    
    // MARK: Web calls
    
    // calls login web service
    func loginWith(email: String, password: String) -> Void {
        
        // request URL
        let urlString = "\(H2HServerURL)corplogin.do"
        
        // request parameters
        let params = [
                       "email": email,
                       "password": password ]
        
        requestWithURL(urlString, params: params, completionHandler: { (responseDictionary, responseUrl, error) in

            // fetch message and return code recieved form the web service
            var message: String = ""
            let returnCode = responseDictionary!["returnCode"] as! Int
            
            // if returnCode is 0
            // web service has returned with success
            var alertTitle: String
            if returnCode == 0
            {
                // fill the response in UserInfo model
                // save this model in Core
                // 'apiToken' from this response is needed to be set in the header of start and schedule web services
                // in order to identify the user
                let userInfo = UserInfo(recordingDefault: responseDictionary!["recordingDefault"] as! NSNumber,
                    isCtAdmin: responseDictionary!["isCtAdmin"] as! NSNumber,
                    isAdmin: responseDictionary!["isAdmin"] as! NSNumber,
                    apiToken: responseDictionary!["apiToken"] as! String,
                    uploadLimit: responseDictionary!["uploadLimit"] as! NSNumber,
                    screenName: responseDictionary!["screenName"] as! String,
                    attendeesLimit: responseDictionary!["attendeesLimit"] as! NSNumber,
                    countryCode: responseDictionary!["countryCode"] as! String,
                    accountType: responseDictionary!["accountType"] as! NSNumber,
                    avatar: responseDictionary!["avatar"] as! String,
                    returnCode: responseDictionary!["returnCode"] as! NSNumber,
                    logo: responseDictionary!["logo"] as! NSNumber,
                    timeZone: responseDictionary!["timeZone"] as! String,
                    token: responseDictionary!["token"] as! String,
                    userId: responseDictionary!["userId"] as! NSNumber,
                    accountSn: responseDictionary!["accountSn"] as! NSNumber,
                    email: responseDictionary!["email"] as! String,
                    name: responseDictionary!["name"] as! String,
                    isSystemChecked: responseDictionary!["isSystemChecked"] as! NSNumber,
                    phone: responseDictionary!["phone"] as! String)
                
                // save user info in core
                // so as to use the information in Start and Schedule web services
                Core.sharedInstance.userInfo = userInfo

                alertTitle = "Login successful"
                message = "Login successful, you can now start or schedule meetings."
            }
            else
            {
                alertTitle = "Login Failed"
                message = responseDictionary!["message"] as! String
            }
            
            dispatch_async(dispatch_get_main_queue()) {
                
                // hide activity indicator
                GUIUtility.sharedInstance.hideLoadingView()
                
                // display alert with message and title per web service return result
                GUIUtility.sharedInstance.dismissLoadingAndDisplayAlertWith(alertTitle, message: message)
            }
        })
    }
    
    // MARK: TextField delegate
    func textFieldShouldReturn(textField: UITextField) -> Bool {
        self.view.endEditing(true)
        return false
    }
}