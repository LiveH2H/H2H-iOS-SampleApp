//
//  SignUpTableViewController.swift
//  H2HSDKIntegrationSample
//
//  Created by charuta.rajopadhye on 21/07/16.
//  Copyright © 2016 Spring Computing Technologies. All rights reserved.
//

import Foundation
import UIKit

class SignUpTableViewController : UITableViewController {
    
    // MARK: IBOutlets
    @IBOutlet weak var textFieldUserName: UITextField!
    
    @IBOutlet weak var textFieldFirstName: UITextField!
    
    @IBOutlet weak var textFieldLastName: UITextField!
    
    @IBOutlet weak var textFieldEmail: UITextField!
    
    @IBOutlet weak var textFieldPassword: UITextField!
    
    @IBOutlet weak var buttonSignUp: UIButton!

    
    // MARK: Lifecycle methods
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // navigation title & color
        self.navigationItem.title = "Sign Up"
        self.navigationController?.navigationBar.tintColor
            = UIColor(red: 255/255.0, green: 107/255.0, blue: 100/255.0, alpha: 1.0)
    }
    
    // MARK: IBActions
    @IBAction func buttonSignUpClicked(sender: AnyObject) {
        
//        hard code here or enter details from UI
//        textFieldUserName.text = "user name"
//        textFieldFirstName.text = "xyz"
//        textFieldLastName.text = "abc"
//        textFieldEmail.text = "h2h1001211@sharklasers.com"
//        textFieldPassword.text = "h2h10"
        
        self.view.endEditing(true)

        // check no information is missing
        if self.textFieldUserName.text != "" &&
           self.textFieldFirstName.text != "" &&
           self.textFieldLastName.text != "" &&
           self.textFieldEmail.text != "" &&
           self.textFieldPassword.text != ""
        {
            // display activity indicator
            dispatch_async(dispatch_get_main_queue()) {
                GUIUtility.sharedInstance.displayLoadingView()
            }
            
            // call sign up web service
            // this call takes the following parameters:
            // 1. user name entered by the user
            // 2. user's first name
            // 3. user's last name
            // 4. user's email address
            // 5. user's password
            self.signUpWith( textFieldUserName.text!,
                             firstName: textFieldFirstName.text!,
                             lastName: textFieldLastName.text!,
                             email: textFieldEmail.text!,
                             password: textFieldPassword.text!)
        }
    }
    
    
    // MARK: Web calls
    
    // calls sign up web service
    func signUpWith(userName: String, firstName: String, lastName: String, email: String, password: String) -> Void {
        
        // sign up ws url
        let urlString = "\(H2HServerURL)message.do"
        
        // fetch preferred language of the user, to pass as locale
        // to the web service
        let arrayLanguages = NSLocale.preferredLanguages()
        let language = arrayLanguages[0]

        // params to pass to sign up ws
        let params = [
                       "action" : "userSignup",
                       "username":userName,
                       "email":email,
                       "firstName":firstName,
                       "lastName":lastName,
                       "password":password,
                       "locale": language
                     ]

        requestWithURL(urlString, params:  params , completionHandler: { (responseDictionary, responseUrl, error) in
            
            // fetch message and return code recieved form the web service
            let message = responseDictionary!["message"] as! String
            let returnCode = responseDictionary!["returnCode"] as! Int
 
            // if returnCode is 0
            // the web service has returned with success
            var alertTitle: String
            if returnCode == 0
            {
                alertTitle = "Sign up Successful"
            }
            else
            {
                alertTitle = "Sign up Failed"
            }
            
            // display alert with message and title per web service return result
            GUIUtility.sharedInstance.dismissLoadingAndDisplayAlertWith(alertTitle, message: message)
        })
    }
    
    // boilerplate method to for web service call
    private func requestWithURL( urlString:String, params:Dictionary<String, AnyObject>, completionHandler:(NSDictionary?, NSURLResponse?, NSError?) ->Void )
    {
        // set request URL
        let request : NSMutableURLRequest = NSMutableURLRequest(URL: NSURL(string: urlString)!)
        // set request type
        request.HTTPMethod = "POST"
        
        var jsonData: NSData? = nil
        do
        {
            // convert params to NSData
            jsonData = try NSJSONSerialization.dataWithJSONObject(params, options: [])
            
        }
        catch let error as NSError {
            print("json error: \(error.localizedDescription)")
            GUIUtility.sharedInstance.dismissLoadingAndDisplayAlertWith( "Error: JSON Parsing",
                                                                         message: error.localizedDescription)
            return
        }
        
        // set request body
        // convert json in NSData to String
        let jsonString = String.init(data: jsonData!, encoding: NSUTF8StringEncoding)
        let body = "json=" + jsonString!
        print("Sign up request body: ", body)
        let bodyEncoded : NSString = body.stringByAddingPercentEncodingWithAllowedCharacters(NSCharacterSet.URLHostAllowedCharacterSet())!
        let httpBody : NSData? = bodyEncoded.dataUsingEncoding(NSUTF8StringEncoding)
        request.HTTPBody = httpBody
        
        // set reuest headers
        request.setValue("application/x-www-form-urlencoded; charset=utf-8", forHTTPHeaderField: "Content-Type")
        request.setValue(NSString(format:"%llu", httpBody!.length) as String, forHTTPHeaderField: "Content-Length")
        
        let postDataTask = NSURLSession.sharedSession().dataTaskWithRequest(request, completionHandler: { (data, response, error) in
            
            do
            {
                if let dataUnwraped = data
                {
                    // convert response data to NSDictionary
                    let jsonDictionary = try NSJSONSerialization.JSONObjectWithData(dataUnwraped, options: [])
                    // send the response NSDictionary to calling method's handler
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