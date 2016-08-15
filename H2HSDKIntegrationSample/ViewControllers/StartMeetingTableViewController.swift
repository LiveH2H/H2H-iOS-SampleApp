//
//  StartMeetingTableViewController.swift
//  H2HSDKIntegrationSample
//
//  Created by charuta.rajopadhye on 21/07/16.
//  Copyright © 2016 Spring Computing Technologies. All rights reserved.
//

import Foundation
import UIKit
import H2HSDK

// defined in order to know what component user is 
// interacting with w.r.t selection list
enum SelectedUIElement {
 
    case SelectLanguage1
    case SelectLanguage2
    case SelectLanguage3
    case MeetingType
}

class StartMeetingTableViewController : UITableViewController, SelectedStringDelegate {
    
    // MARK: Properties
    
    // default selected server location is set
    // if updated by the user, it is stored in this variable
    var selectedServerLocation: NSIndexPath = NSIndexPath(forRow: 0, inSection: 0)
    
    // this enum hold the UI element user is interacting with
    // so that we know on which UI element the user selection is to be displayed
    // in case it comes from the selection list delegate
    var selectedUIElement: SelectedUIElement = .SelectLanguage1
    
    // this dictionary contains all the languages and their respective codes
    // that are available for translation.
    var dictionaryLanguageOptions: [String:String] =
        [
            "English"    : "en",
            "Chinese"    : "zh",
            "Japanese"   : "ja",
            "Spanish"    : "es",
            "Russian"    : "ru",
            "German"     : "de",
            "French"     : "fr",
            "Arabic"     : "ar",
            "Portuguese" : "pt",
            "Malay"      : "ms"
    ]
    
    // defines the type of meetings
    var dictionaryMeetingType : [String: Int] =
        [
            "Group Meeting" : 6,
            "LiveShare"     : 2
        ]
    
    // array with objects of type: ServerDetailsModel
    // gets filled in response to web service: fetch server list
    var arrayServerDetails = [ServerDetailsModel]()
    
    // MARK: Lifecycle methods
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.navigationItem.title = "Start a Meeting"
        self.navigationController?.navigationBar.tintColor
            = UIColor(red: 255/255.0, green: 107/255.0, blue: 100/255.0, alpha: 1.0)
        
        // initialize views
        self.initializeViewsAndData()
    }
    
    // MARK: IBOutlets

    // Meeting subject cell
    @IBOutlet weak var textFieldMeetingSubject: UITextField!
    
    // Meeting description cell
    @IBOutlet weak var textFieldMeetingDescription: UITextField!
    
    // Invite attendees cell
    @IBOutlet weak var textFieldAttendee1Email: UITextField!
    @IBOutlet weak var textFieldAttendee2Email: UITextField!
    @IBOutlet weak var textFieldAttendee3Email: UITextField!
    
    // Invite Translators Cell
    // View Translator 1
    @IBOutlet weak var textFieldTranslatorEmail1: UITextField!
    @IBOutlet weak var buttonSelectTranslatorLanguage1: UIButton!

    // View Translator 2
    @IBOutlet weak var textFieldTranslatorEmail2: UITextField!
    @IBOutlet weak var buttonSelectTranslatorLanguage2: UIButton!

    // View Translator 3
    @IBOutlet weak var textFieldTranslatorEmail3: UITextField!
    @IBOutlet weak var buttonSelectTranslatorLanguage3: UIButton!
    
    // Meeting type cell
    @IBOutlet weak var labelSelectedMeetingType: UILabel!
    
    // Record meeting
    @IBOutlet weak var switchRecordMeeting: UISwitch!
    
    // Server Location cell
  //  @IBOutlet weak var labelSelectedServerLocation: UILabel!
    
    
    // MARK: IBActions
    
    // Invite Translators IBActions
    @IBAction func buttonSelectTranslatorLanguage1Clicked(sender: AnyObject) {
        self.buttonSelectTranslatorLanguage1.setTitle("", forState: UIControlState.Normal)
        self.buttonSelectTranslatorLanguage1.setTitle("", forState: UIControlState.Highlighted)
        self.buttonSelectTranslatorLanguage1.setTitle("", forState: UIControlState.Selected)
        selectedUIElement = .SelectLanguage1
    }
    
    @IBAction func buttonSelectTranslatorLanguage2Clicked(sender: AnyObject) {
        self.buttonSelectTranslatorLanguage2.setTitle("", forState: UIControlState.Normal)
        self.buttonSelectTranslatorLanguage2.setTitle("", forState: UIControlState.Highlighted)
        self.buttonSelectTranslatorLanguage2.setTitle("", forState: UIControlState.Selected)
        selectedUIElement = .SelectLanguage2
    }
    
    @IBAction func buttonSelectTranslatorLanguage3Clicked(sender: AnyObject) {
        self.buttonSelectTranslatorLanguage3.setTitle("", forState: UIControlState.Normal)
        self.buttonSelectTranslatorLanguage3.setTitle("", forState: UIControlState.Highlighted)
        self.buttonSelectTranslatorLanguage3.setTitle("", forState: UIControlState.Selected)
        selectedUIElement = .SelectLanguage3
    }
    
    // start meeting IBAction
    @IBAction func buttonStartMeetingClicked(sender: AnyObject) {
        
        // hard code data here or collect from the UI
//        self.textFieldMeetingSubject.text = "Meeting subject"
//        self.textFieldMeetingDescription.text = "Meeting description"
//        self.textFieldAttendee1Email.text = "h2h1@sharklasers.com"
//        self.textFieldTranslatorEmail1.text = "h2h3@sharklasers.com"
//        self.buttonSelectTranslatorLanguage1.setTitle("French" as String, forState: UIControlState.Normal)
//        self.buttonSelectTranslatorLanguage1.setTitle("French" as String, forState: UIControlState.Highlighted)
//        self.buttonSelectTranslatorLanguage1.setTitle("French" as String, forState: UIControlState.Selected)
//        self.switchRecordMeeting.setOn(true, animated: false)
        
        self.view.endEditing(true)

        // display activity indicator
        dispatch_async(dispatch_get_main_queue()) {
            GUIUtility.sharedInstance.displayLoadingView()
        }

        // collect data filled on the UI by the user
        // to send it to start meeting web service
        self.collectDataEntered()
    }
    
    // MARK: SelectedStringDelegate methods
    // this method is called when an item from selection list is selected
    func selectionList(selectionList: SelectionListViewController,  didSelectString: NSString, fromDataSource: NSArray, atIndexPath: NSIndexPath) {
        switch selectedUIElement {
        
        case .SelectLanguage1:
            // set selected string as button title
            self.buttonSelectTranslatorLanguage1.setTitle(didSelectString as String, forState: UIControlState.Normal)
            self.buttonSelectTranslatorLanguage1.setTitle(didSelectString as String, forState: UIControlState.Highlighted)
            self.buttonSelectTranslatorLanguage1.setTitle(didSelectString as String, forState: UIControlState.Selected)
            break

        case .SelectLanguage2:
            // set selected string as button title
            self.buttonSelectTranslatorLanguage2.setTitle(didSelectString as String, forState: UIControlState.Normal)
            self.buttonSelectTranslatorLanguage2.setTitle(didSelectString as String, forState: UIControlState.Highlighted)
            self.buttonSelectTranslatorLanguage2.setTitle(didSelectString as String, forState: UIControlState.Selected)
            break
            
        case .SelectLanguage3:
            // set selected string as button title
            self.buttonSelectTranslatorLanguage3.setTitle(didSelectString as String, forState: UIControlState.Normal)
            self.buttonSelectTranslatorLanguage3.setTitle(didSelectString as String, forState: UIControlState.Highlighted)
            self.buttonSelectTranslatorLanguage3.setTitle(didSelectString as String, forState: UIControlState.Selected)
            break
            
        case .MeetingType:
            // set selected string as label title
            self.labelSelectedMeetingType.text = didSelectString as String
            break
        }
    }
    
    // MARK: Segue
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {

        if segue.identifier == "STARTMEETING_TO_SELECTIONLIST_LANGUAGESELECTION1" ||
           segue.identifier == "STARTMEETING_TO_SELECTIONLIST_LANGUAGESELECTION2" ||
           segue.identifier == "STARTMEETING_TO_SELECTIONLIST_LANGUAGESELECTION3"
        {
            // navigating to language selection UI.
            let selectionListViewController = segue.destinationViewController as! SelectionListViewController;
            // configure delegate
            selectionListViewController.delegate = self
            // pass array of languages (keys from dictionary: dictionaryLanguageOptions)
            selectionListViewController.arrayTableViewDataSource = Array(dictionaryLanguageOptions.keys)
        }
        else if segue.identifier == "STARTMEETING_TO_SELECTIONLIST_SELECTMEETING"
        {
            // navigating to select, meeting type.
            let selectionListViewController = segue.destinationViewController as! SelectionListViewController;
            // configure delegate
            selectionListViewController.delegate = self
            // pass array of meeting type (keys from dictionary: dictionaryMeetingType)
            selectionListViewController.arrayTableViewDataSource = Array(dictionaryMeetingType.keys)
        }
        else if segue.identifier == "STARTMEETING_TO_SELECTIONLIST_SERVERLOCATION"
        {
            // navigating to select, server location.
            let selectionListViewController = segue.destinationViewController as! SelectionListViewController;
            // configure delegate
            selectionListViewController.delegate = self
            
            // arrayServerNames: should contain all the server country names
            let arrayServerNames: NSMutableArray = []
            
            // create an array of country names
            // from the array of ServerDetailsModel we fetch from the server
            // to display the same in a select list
            for serverDetailsModel in self.arrayServerDetails {
            
                let stringCountryName = serverDetailsModel.stringCountryName
                arrayServerNames.addObject(stringCountryName)
            }
            
            // provide the selection list, an array of server names for the user to select
            // server location
            selectionListViewController.arrayTableViewDataSource = arrayServerNames
        }
    }
    
    // MARK: TableView delegates
    override func tableView(tableView: UITableView, didSelectRowAtIndexPath indexPath: NSIndexPath) {
        
        switch indexPath.row {
            
        // meeting type cell
        case 4:
            selectedUIElement = .MeetingType
            break
            
        default:
            break
        }
    }
    
    // MARK: Web service calls
 
    // calls web service fetch server list
    private func fetchServerList (completionHandler:(AnyObject?, NSURLResponse?, NSError?) -> Void )
    {
        // request URL
        let urlString = "\(H2HServerURL)corpmeeting.do"
        
        // request parameters
        let params = ["action": "getWebRTCServerList"]
        
        requestWithURL(urlString, params: params, action: "getWebRTCServerList", completionHandler: { (responseAnyObject, responseUrl, error) in
            
            completionHandler(responseAnyObject, responseUrl, error)
        })
    }
    
    // boilerplate method to for web service call
    private func requestWithURL(urlString:String, params:Dictionary<String, AnyObject>, action: String, completionHandler:(AnyObject?, NSURLResponse?, NSError?)->Void)
    {
        // request URL set
        let request : NSMutableURLRequest = NSMutableURLRequest (URL: NSURL(string: urlString)!)
        // request type set
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
        
        // convert json in NSData to String
        let jsonString = String.init(data: jsonData!, encoding: NSUTF8StringEncoding)

        var body: String = ""
        if action == "createMeeting"
        {
            body = "action=createMeeting&json=" + jsonString!
            
            // if action is of type: createMeeting
            // set apiToken in the header
            // this api token is recieved from the login web service
            request.setValue(Core.sharedInstance.userInfo?.apiToken, forHTTPHeaderField: "apiToken")
        }
        else if action == "getWebRTCServerList"
        {
            body = "json=" + jsonString!
        }
        
        // set request body
        let bodyEncoded : NSString = body.stringByAddingPercentEncodingWithAllowedCharacters(NSCharacterSet.URLHostAllowedCharacterSet())!
        let httpBody : NSData? = bodyEncoded.dataUsingEncoding(NSUTF8StringEncoding)
        request.HTTPBody = httpBody

        // set common other request headers
        request.setValue("application/x-www-form-urlencoded; charset=utf-8", forHTTPHeaderField: "Content-Type")
        request.setValue(NSString(format:"%llu", httpBody!.length) as String, forHTTPHeaderField: "Content-Length")

        //let postDataTask = NSURLSession.sharedSession().dataTaskWithRequest(request, completionHandler: { (data, response, error) in
        let postDataTask = ((UIApplication.sharedApplication().delegate) as! AppDelegate!).getURLSession().dataTaskWithRequest(request, completionHandler: { (data, response, error) in
            do
            {
                if let dataUnrapped = data
                {
                    let jsonObject = try NSJSONSerialization.JSONObjectWithData(dataUnrapped, options: [])
                    
                    let array = jsonObject as? NSMutableArray
                    if array == nil
                    {
                        // in case of create meeting the object is of type dictionary
                        let dictionary = jsonObject as? NSMutableDictionary
                        completionHandler(dictionary, response, error)
                    }
                    else
                    {
                        // in case of server list, object is of type array
                        completionHandler(array, response, error)
                    }
                }
                else
                {
                    print("Error: No data recieved")
                    GUIUtility.sharedInstance.dismissLoadingAndDisplayAlertWith( "Error: Response",
                                                                                  message: "No data recieved from server")
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
    
    // starts meeting on provided view controller
    func startMeetingWith(params: NSDictionary, onViewController: UIViewController) -> Void {
        
        self.startMeeting(params, completionHandler: { (responseDictionary, responseUrl, error) in
            
            if(responseDictionary != nil)
            {
                let serverURL = responseDictionary!["serverURL"] as? String
                let meetingUri = responseDictionary!["meetingUri"] as? String
                let referrer = responseDictionary!["referer"] as? String
                let origin = responseDictionary!["origin"] as? String

                dispatch_async(dispatch_get_main_queue(), {
                    
                    // hide activity indicator
                    GUIUtility.sharedInstance.hideLoadingView()

                    // call join method from H2HSDK with parameters recieved from the web service
                    H2HSDKExt.sharedInstance().joinMeetingWithToken( meetingUri,
                                                                     onServer: serverURL,
                                                                     usingOrigin: origin,
                                                                     withReferrer: referrer,
                                                                     fromViewController: onViewController)
                })
            }
            else
            {
                print("Start meeting failed")
                GUIUtility.sharedInstance.dismissLoadingAndDisplayAlertWith( "Error: Start meeting",
                    message: "No data recieved")
            }
            
        })
    }
    
    // calls start meeting web service
    private func startMeeting(params: NSDictionary, completionHandler:(NSDictionary?, NSURLResponse?, NSError?)->Void)
    {
        // request URL
        let urlString = "\(H2HServerURL)corpmeeting.do"
        
        self.requestWithURL(urlString, params: params as! Dictionary<String, AnyObject>, action: "createMeeting", completionHandler: { (responseAnyObject, responseUrl, error) in
            
            let responseDictionary = responseAnyObject as! NSDictionary
            if responseDictionary["returnCode"] as? Int != 0
            {
                GUIUtility.sharedInstance.dismissLoadingAndDisplayAlertWith( "Error: Start meeting",
                    message: (responseDictionary["message"] as? String)!)
            }
            else
            {
                completionHandler(responseDictionary, responseUrl, error)
            }
        })
    }

    // MARK: Utility methods
    
    func handleSelectServerLocationClick()  {
        
        // display activity indicator
         dispatch_async(dispatch_get_main_queue()) {
            GUIUtility.sharedInstance.displayLoadingView()
        }
        
        // call web service to fetch the list of available servers
        self.fetchServerList({ (responseAnyObject, responseUrl, error) in
            
            if responseAnyObject != nil
            {
                // web service success
                let responseArray = responseAnyObject as? NSMutableArray
                self.arrayServerDetails.removeAll()
                
                // iterate over response array and create objects of: ServerDetailsModel
                for dictonary in responseArray! {
                    
                    // fetch data recieved and create ServerDetailsModel model
                    let countryNameEN = dictonary["countryNameEN"] as! String
                    let location = dictonary["location"] as! String
                    let serverURL = dictonary["serverURL"] as! String
                    let serverDetails = ServerDetailsModel( stringCountryName: countryNameEN, stringServerLocation: location, stringServerURL: serverURL)
                    self.arrayServerDetails.append(serverDetails)
                }
                
                // add default server to the list
                let serverDetailsDefault = ServerDetailsModel( stringCountryName: "Default", stringServerLocation: "TC", stringServerURL: "")
                self.arrayServerDetails.insert(serverDetailsDefault, atIndex: 0)
                
                dispatch_async(dispatch_get_main_queue()) {
                    
                    GUIUtility.sharedInstance.hideLoadingView()
                    // navigate to selection list with server names for user to select from
                    self.performSegueWithIdentifier("STARTMEETING_TO_SELECTIONLIST_SERVERLOCATION", sender: nil)
                }
            }
            else
            {
                print("fetching server list failed")
                GUIUtility.sharedInstance.dismissLoadingAndDisplayAlertWith( "Error: fetching server list",
                    message: "No data recieved")
            }
        })
    }
    
    // provide initial values/defaults to UI components
    func initializeViewsAndData() -> Void {
        
        self.labelSelectedMeetingType.text = "Group Meeting"
   //     self.labelSelectedServerLocation.text = "Default"
        
        // add default server, to the list of servers available
        let serverDetailsDefault = ServerDetailsModel( stringCountryName: "Default", stringServerLocation: "TC", stringServerURL: "")
        self.arrayServerDetails.insert(serverDetailsDefault, atIndex: 0)
    }
    
    // collect data entered on the UI, by the user
    func collectDataEntered() -> Void {
        
        let meetingSubject: String = self.textFieldMeetingSubject.text!
        let meetingDescription: String = self.textFieldMeetingDescription.text!
        
        let attendeesEmail: NSMutableArray = []
        if self.textFieldAttendee1Email.text != ""
        {
            attendeesEmail.addObject(self.textFieldAttendee1Email.text!)
        }
        
        if self.textFieldAttendee2Email.text != ""
        {
            attendeesEmail.addObject(self.textFieldAttendee2Email.text!)
        }
        
        if self.textFieldAttendee3Email.text != ""
        {
            attendeesEmail.addObject(self.textFieldAttendee3Email.text!)
        }
        
        var serverLocation: String = "TC" // default server location
        // get server location selected by the user
        // if not, use default
        let serverDetailsModel = arrayServerDetails[(selectedServerLocation.row)]
        serverLocation = serverDetailsModel.stringServerLocation
        
        let meetingType = dictionaryMeetingType[self.labelSelectedMeetingType.text!]
        
        let recordMeeting = self.switchRecordMeeting.on
        
        let translatorList: NSMutableArray = []
        
        var translator1Dictionary: NSMutableDictionary = [:]
        var translator2Dictionary: NSMutableDictionary = [:]
        var translator3Dictionary: NSMutableDictionary = [:]
        
        if ( self.textFieldTranslatorEmail1.text != "" ) &&
            (self.buttonSelectTranslatorLanguage1.currentTitle != "Select language" && self.buttonSelectTranslatorLanguage1.currentTitle != "" )
        {
            translator1Dictionary = [ "email" : self.textFieldTranslatorEmail1.text!,
                                      "lang"  : self.dictionaryLanguageOptions [self.buttonSelectTranslatorLanguage1.currentTitle!]! ]
            translatorList.addObject(translator1Dictionary)
        }
        
        if ( self.textFieldTranslatorEmail2.text != "" ) &&
            (self.buttonSelectTranslatorLanguage2.currentTitle != "Select language" && self.buttonSelectTranslatorLanguage2.currentTitle != "" )
        {
            translator2Dictionary = [ "email" : self.textFieldTranslatorEmail2.text!,
                                      "lang"  : self.dictionaryLanguageOptions [self.buttonSelectTranslatorLanguage2.currentTitle!]! ]
            translatorList.addObject(translator2Dictionary)
        }
        
        if ( self.textFieldTranslatorEmail3.text != "" ) &&
            (self.buttonSelectTranslatorLanguage3.currentTitle != "Select language" && self.buttonSelectTranslatorLanguage3.currentTitle != "" )
        {
            translator3Dictionary = [ "email" : self.textFieldTranslatorEmail3.text!,
                                      "lang"  : self.dictionaryLanguageOptions [self.buttonSelectTranslatorLanguage3.currentTitle!]! ]
            translatorList.addObject(translator3Dictionary)
        }
        
        // create dictionary of all the provided parameters
        let params = [ "action" : "createMeeting",
                       "groupList" :[],
                       "description" : meetingDescription,
                       "location" : serverLocation ,
                       "meetingType" : meetingType!,
                       "recordMeeting" : recordMeeting,
                       "subject" : meetingSubject,
                       "emailList" : attendeesEmail,
                       "translatorList" : translatorList ]

        // call start meeting web service with params 
        self.startMeetingWith(params, onViewController: self)
    }
    
    // MARK: TextField delegate
    func textFieldShouldReturn(textField: UITextField) -> Bool {
        self.view.endEditing(true)
        return false
    }
 }