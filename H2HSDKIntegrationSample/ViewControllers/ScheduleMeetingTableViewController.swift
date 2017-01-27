//
//  ScheduleMeetingTableViewController.swift
//  H2HSDKIntegrationSample
//
//  Created by charuta.rajopadhye on 25/07/16.
//  Copyright © 2016 Spring Computing Technologies. All rights reserved.
//

import Foundation
import UIKit
import H2HSDK

// denotes the date cell with which the user is
// currently interacting
enum SelectedDate {
    
    case StartDate
    case EndDate
}

class ScheduleMeetingTableViewController : UITableViewController, SelectedStringDelegate, DatePickerSelectedDateDelegate {

    // MARK: IBOutlets
    
    // cell meeting subject
    @IBOutlet weak var textFieldMeetingSubject: UITextField!

    // cell meeting description
    @IBOutlet weak var textFieldMeetingDescription: UITextField!
    
    // cell invite attendees
    @IBOutlet weak var textFieldAttendee1Email: UITextField!
    @IBOutlet weak var textFieldAttendee2Email: UITextField!
    @IBOutlet weak var textFieldAttendee3Email: UITextField!
    
    // cell live translators
    // view live translator 1
    @IBOutlet weak var textFieldTranslator1Email: UITextField!
    @IBOutlet weak var buttonSelectLanguageTranslator1: UIButton!

    // view live translator 2
    @IBOutlet weak var textFieldTranslator2Email: UITextField!
    @IBOutlet weak var buttonSelectLanguageTranslator2: UIButton!
    
    // view live translator 3
    @IBOutlet weak var textFieldTranslator3Email: UITextField!
    @IBOutlet weak var buttonSelectLanguageTranslator3: UIButton!

    // cell meeting type
    @IBOutlet weak var labelSelectedMeetingType: UILabel!
    
    // cell meeting start date
    @IBOutlet weak var labelSelectedStartDate: UILabel!
    
    // cell meeting end date
    @IBOutlet weak var labelSelectedEndDate: UILabel!
    
    // cell record meeting
    @IBOutlet weak var switchRecordMeeting: UISwitch!
    
    // cell server location
  //  @IBOutlet weak var labelSelectedServerLocation: UILabel!
    

    // MARK: Properties
    
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
    
    // denotes the type of meeting
    var dictionaryMeetingType : [String: Int] =
        [
            "Group Meeting" : 6,
            "LiveShare"     : 2
        ]
    
    // array with objects of type: ServerDetailsModel
    // gets filled in response to web service: fetch server list
   // var arrayServerDetails = [ServerDetailsModel]()
    
    // the date user is interacting with
    var selectedDateType: SelectedDate = .StartDate
    
    // default selected server location is set
    // if updated by the user, it is stored in this variable
    var selectedServerLocation: NSIndexPath = NSIndexPath(forRow: 0, inSection: 0)
    
    // MARK: Lifecycle methods
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // set view controller title & color
        self.navigationItem.title = "Schedule Meeting"
        self.navigationController?.navigationBar.tintColor
            = UIColor(red: 255/255.0, green: 107/255.0, blue: 100/255.0, alpha: 1.0)
        
        // initialize views
        self.initializeViewsAndData()
    }
    
    // MARK: IBActions
    @IBAction func buttonSelectTranslatorLanguage1Clicked(sender: AnyObject) {
        self.buttonSelectLanguageTranslator1.setTitle("", forState: UIControlState.Normal)
        self.buttonSelectLanguageTranslator1.setTitle("", forState: UIControlState.Highlighted)
        self.buttonSelectLanguageTranslator1.setTitle("", forState: UIControlState.Selected)
        selectedUIElement = .SelectLanguage1
    }
    
    @IBAction func buttonSelectTranslatorLanguage2Clicked(sender: AnyObject) {
        self.buttonSelectLanguageTranslator2.setTitle("", forState: UIControlState.Normal)
        self.buttonSelectLanguageTranslator2.setTitle("", forState: UIControlState.Highlighted)
        self.buttonSelectLanguageTranslator2.setTitle("", forState: UIControlState.Selected)
        selectedUIElement = .SelectLanguage2
    }
    
    @IBAction func buttonSelectTranslatorLanguage3Clicked(sender: AnyObject) {
        self.buttonSelectLanguageTranslator3.setTitle("", forState: UIControlState.Normal)
        self.buttonSelectLanguageTranslator3.setTitle("", forState: UIControlState.Highlighted)
        self.buttonSelectLanguageTranslator3.setTitle("", forState: UIControlState.Selected)
        selectedUIElement = .SelectLanguage3
    }
    
    @IBAction func buttonScheduleMeetingClicked(sender: AnyObject) {
        
        // hard code data here or collect from the UI
//        self.textFieldMeetingSubject.text = "Meeting subject"
//        self.textFieldMeetingDescription.text = "Meeting description"
//        self.textFieldAttendee1Email.text = "h2h1@sharklasers.com"
//        self.textFieldTranslator1Email.text = "h2h2@sharklasers.com"
//        self.buttonSelectLanguageTranslator1.setTitle("French" as String, forState: UIControlState.Normal)
//        self.buttonSelectLanguageTranslator1.setTitle("French" as String, forState: UIControlState.Highlighted)
//        self.buttonSelectLanguageTranslator1.setTitle("French" as String, forState: UIControlState.Selected)
//        self.switchRecordMeeting.setOn(true, animated: false)
        
        self.view.endEditing(true)

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
            self.buttonSelectLanguageTranslator1.setTitle(didSelectString as String, forState: UIControlState.Normal)
            self.buttonSelectLanguageTranslator1.setTitle(didSelectString as String, forState: UIControlState.Highlighted)
            self.buttonSelectLanguageTranslator1.setTitle(didSelectString as String, forState: UIControlState.Selected)
            break
            
        case .SelectLanguage2:

            // set selected string as button title
            self.buttonSelectLanguageTranslator2.setTitle(didSelectString as String, forState: UIControlState.Normal)
            self.buttonSelectLanguageTranslator2.setTitle(didSelectString as String, forState: UIControlState.Highlighted)
            self.buttonSelectLanguageTranslator2.setTitle(didSelectString as String, forState: UIControlState.Selected)
            break
            
        case .SelectLanguage3:

            // set selected string as button title
            self.buttonSelectLanguageTranslator3.setTitle(didSelectString as String, forState: UIControlState.Normal)
            self.buttonSelectLanguageTranslator3.setTitle(didSelectString as String, forState: UIControlState.Highlighted)
            self.buttonSelectLanguageTranslator3.setTitle(didSelectString as String, forState: UIControlState.Selected)
            break
            
        case .MeetingType:

            // set selected string as label title
            self.labelSelectedMeetingType.text = didSelectString as String
            break
            
       /* case .ServerLocation:
            
            self.selectedServerLocation = atIndexPath
            self.labelSelectedServerLocation.text = didSelectString as String
            break*/
        }
    }
    
    // MARK: TableView delegates
    override func tableView(tableView: UITableView, didSelectRowAtIndexPath indexPath: NSIndexPath) {
        
        switch indexPath.row {
            
        // cell meeting type
        case 4:
            selectedUIElement = .MeetingType
            break
       
            
        default:
            break
            
        }
    }
    
    // MARK: Web service calls

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
            GUIUtility.sharedInstance.dismissLoadingAndDisplayAlertWith( "Error: JSON Parsing",
                                                                         message: error.localizedDescription)
            print("json error: \(error.localizedDescription)")
            return
        }
        
        // convert json in NSData to String
        let jsonString = String.init(data: jsonData!, encoding: NSUTF8StringEncoding)
        
        var body: String = ""
        if action == "scheduleMeeting"
        {
            body = "action=scheduleMeeting&json=" + jsonString!

            // if action is of type: scheduleMeeting
            // set apiToken in the header
            // this api token is recieved from the login web service
            request.setValue(Core.sharedInstance.userInfo?.apiToken, forHTTPHeaderField: "apiToken")
        }
        else if action == "getWebRTCServerList" || action == "searchMeetingById" || action == "joinMeeting"
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
        
        let postDataTask = NSURLSession.sharedSession().dataTaskWithRequest(request, completionHandler: { (data, response, error) in
            
            do
            {
                if let dataUnrapped = data
                {
                    let jsonObject = try NSJSONSerialization.JSONObjectWithData(dataUnrapped, options: [])
                    
                    let array = jsonObject as? NSMutableArray
                    if array == nil
                    {
                        // in case of schedule meeting the object is of type dictionary
                        let dict = jsonObject as? NSMutableDictionary
                        completionHandler(dict, response, error)
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
    
    // calls web service fetch server list
    private func fetchServerList(completionHandler:(AnyObject?, NSURLResponse?, NSError?)->Void)
    {
        let urlString = "\(H2HServerURL)corpmeeting.do"
        let params = ["action":"getWebRTCServerList"]
        
        requestWithURL(urlString, params: params, action: "getWebRTCServerList", completionHandler: { (responseAnyObject, responseUrl, error) in
            
            completionHandler(responseAnyObject, responseUrl, error)
            print (responseAnyObject)
        })
    }

    // schedules meeting with given params
    func scheduleMeetingWith (params: NSDictionary) -> Void {
        
        // display activity indicator
        dispatch_async(dispatch_get_main_queue()) {
            GUIUtility.sharedInstance.displayLoadingView()
        }

        // calls, schedule meeting web service
        self.scheduleMeeting(params, completionHandler: { (responseDictionary, responseUrl, error) in
            
            if(responseDictionary != nil)
            {
                dispatch_async(dispatch_get_main_queue(), {
                    
                    // hide activity indicator
                    GUIUtility.sharedInstance.hideLoadingView()
                    
                    // create the alert
                    let alert = UIAlertController( title: "Schedule Meeting Successful",
                                                   message: "Do you want to start the meeting right away?",
                                                   preferredStyle: UIAlertControllerStyle.Alert)
                    // add the actions (buttons)
                    alert.addAction(UIAlertAction(title: "Start", style: UIAlertActionStyle.Default, handler: { action in
                        
                        // display activity indicator
                        GUIUtility.sharedInstance.displayLoadingView()
                        
                        let meetingID: String = responseDictionary!["meetingId"] as! String
                        self.joinScheduledMeeting(meetingID, fromViewController: self)
                        
                    }))
                    
                    alert.addAction(UIAlertAction(title: "No", style: UIAlertActionStyle.Cancel, handler: nil))
                    
                    // show the alert
                    self.presentViewController(alert, animated: true, completion: nil)
                })
            }
            else
            {
                print("Schedule meeting failed")
                GUIUtility.sharedInstance.dismissLoadingAndDisplayAlertWith( "Error: Schedule meeting",
                    message: "No data recieved")
            }
            
        })
    }
    
    // calls, schedule meeting web service
    private func scheduleMeeting (params: NSDictionary, completionHandler:(NSDictionary?, NSURLResponse?, NSError?) -> Void )
    {
        // request URL
        let urlString = "\(H2HServerURL)corpmeeting.do"
        
        self.requestWithURL(urlString, params: params as! Dictionary<String, AnyObject>, action: "scheduleMeeting", completionHandler: { (responseAnyObject, responseUrl, error) in
            
            let responseDictionary = responseAnyObject as! NSDictionary
            if responseDictionary["returnCode"] as? Int != 0
            {
                GUIUtility.sharedInstance.dismissLoadingAndDisplayAlertWith( "Error: Scheduling meeting",
                    message: (responseDictionary["message"] as? String)!)
            }
            else
            {
                completionHandler(responseDictionary, responseUrl, error)
            }
        })
    }

    // searches for meeting with given meeting ID
    private func searchMeetingWith (meetingId:String, completionHandler:(NSDictionary?, NSURLResponse?, NSError?) -> Void )
    {
        // request URL
        let urlString = "\(H2HServerURL)corpmeeting.do"
        
        // request parameters
        let params = [
                       "action":"searchMeetingById",
                       "meetingId":meetingId
                     ]
        
        requestWithURL (urlString, params: params, action: "searchMeetingById", completionHandler: { (responseAnyObject, responseUrl, error) in
            
            if let responseDictionary = responseAnyObject as? NSDictionary
            {
                // get start and end time of meeting from the response
                let startTime: NSNumber = responseDictionary["startTime"] as! NSNumber
                let endTime: NSNumber = responseDictionary["endTime"] as! NSNumber
                
                // check if meeting time is in bounds to start meeting
                if self.checkIfCanJoinWith(startTime, endTime: endTime)
                {
                    completionHandler(responseDictionary, responseUrl, error)
                }
                else
                {
                    // hide activity indicator
                    dispatch_async(dispatch_get_main_queue()) {
                        GUIUtility.sharedInstance.hideLoadingView()
                        
                        let alertController = UIAlertController (title: "Could not join meeting",
                            message: "Cannot join this meeting, because it's not started as yet or time slot is invalid", preferredStyle: .Alert)
                        
                        let defaultAction = UIAlertAction (title: "Ok", style: .Cancel, handler: nil)
                        alertController.addAction (defaultAction)
                        
                        self.presentViewController (alertController, animated: true, completion: nil)
                    }
                }
            }
            else
            {
                GUIUtility.sharedInstance.dismissLoadingAndDisplayAlertWith( "Error: Search ",
                    message: "Search returned with improper response")
                print("Search returned with improper response")
            }
        })
    }
    
    // joins meeting with meetingId provided
    private func joinMeetingByMeetingID( meetingId:String, completionHandler:(NSDictionary?, NSURLResponse?, NSError?)-> Void )
    {
        // request URL
        let urlString = "\(H2HServerURL)corpmeeting.do"
        
        // request params
        let params = [
                        "action": "joinMeeting",
                        "meetingId": meetingId
                     ]
        
        self.requestWithURL(urlString, params: params, action: "joinMeeting", completionHandler: { (responseAnyObject, responseUrl, error) in
            
            if let responseDictionary = responseAnyObject as? NSDictionary
            {
                completionHandler(responseDictionary, responseUrl, error)
            }
            else
            {
                GUIUtility.sharedInstance.dismissLoadingAndDisplayAlertWith( "Error: Join Meeting ",
                    message: "Join returned with improper response")
                print("Join returned with improper response")
            }
        })
    }
    
    // MARK: Utility methods
    
  /*  func handleSelectServerLocationClick()  {
        
        GUIUtility.sharedInstance.displayLoadingView()
        
        // call web service to fetch the list of available servers
        self.fetchServerList({ (responseAnyObject, responseUrl, error) in
            
            if responseAnyObject != nil
            {
                // web service success
                let responseArray = responseAnyObject as? NSMutableArray
              //  self.arrayServerDetails.removeAll()
                
                // iterate over response array and create objects of: ServerDetailsModel
                for dictonary in responseArray! {
                    
                    // fetch data recieved and create ServerDetailsModel model
                    let countryNameEN = dictonary["countryNameEN"] as! String
                    let location = dictonary["location"] as! String
                    let serverURL = dictonary["serverURL"] as! String
                    let serverDetails = ServerDetailsModel( stringCountryName: countryNameEN, stringServerLocation: location, stringServerURL: serverURL)
             //       self.arrayServerDetails.append(serverDetails)
                }
                
                // add default server to the list
                let serverDetailsDefault = ServerDetailsModel( stringCountryName: "Default", stringServerLocation: "TC", stringServerURL: "")
            //    self.arrayServerDetails.insert(serverDetailsDefault, atIndex: 0)

                dispatch_async(dispatch_get_main_queue()) {

                    GUIUtility.sharedInstance.hideLoadingView()
                    // navigate to selection list with server names for user to select from
                    self.performSegueWithIdentifier("SCHEDULEMEETING_TO_SELECTIONLIST_SERVERLOCATION", sender: nil)
                }
            }
            else
            {
                GUIUtility.sharedInstance.dismissLoadingAndDisplayAlertWith( "Error: Join Meeting ",
                    message: "Join meeting failed")
                print("Join meeting failed")
            }
            
        })
    }*/
    
    // provide initial values/defaults to UI components
    func initializeViewsAndData() -> Void {
        
        self.labelSelectedMeetingType.text = "Group Meeting"
      //  self.labelSelectedServerLocation.text = "Default"
        
        // add default server, to the list of servers available
      /*  let serverDetailsDefault = ServerDetailsModel( stringCountryName: "Default", stringServerLocation: "TC", stringServerURL: "")
        self.arrayServerDetails.insert(serverDetailsDefault, atIndex: 0)*/
        
        let todayDate: NSDate = NSDate()
        let dateToSet = self.getNextHourDateFrom(todayDate)
        let dateFormatter = NSDateFormatter()
        dateFormatter.dateFormat = "dd-MM-yyyy, hh:mm a"
        let dateString = dateFormatter.stringFromDate(dateToSet)
        
        self.labelSelectedStartDate.text = dateString
        
        let dateEnd = self.getNextHourDateFrom(dateToSet)
        
        let dateOneHourAheadString = dateFormatter.stringFromDate(dateEnd)

        self.labelSelectedEndDate.text = dateOneHourAheadString
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
        
      //  var serverLocation: String = "TC" // default server location
        // get server location selected by the user
        // if not, use default
      //  let serverDetailsModel = arrayServerDetails[(selectedServerLocation.row)]
      //  serverLocation = serverDetailsModel.stringServerLocation
        
        let meetingType = dictionaryMeetingType[self.labelSelectedMeetingType.text!]
        
        let recordMeeting = self.switchRecordMeeting.on

        let translatorList: NSMutableArray = []
        
        var translator1Dictionary: NSMutableDictionary = [:]
        var translator2Dictionary: NSMutableDictionary = [:]
        var translator3Dictionary: NSMutableDictionary = [:]
        
        if ( self.textFieldTranslator1Email.text != "" ) &&
           (self.buttonSelectLanguageTranslator1.currentTitle != "Select language" && self.buttonSelectLanguageTranslator1.currentTitle != "" )
        {
            translator1Dictionary = [ "email" : self.textFieldTranslator1Email.text!,
                                      "lang"  : self.dictionaryLanguageOptions [self.buttonSelectLanguageTranslator1.currentTitle!]! ]
            translatorList.addObject(translator1Dictionary)
        }
        
        if ( self.textFieldTranslator2Email.text != "" ) &&
            (self.buttonSelectLanguageTranslator2.currentTitle != "Select language" && self.buttonSelectLanguageTranslator2.currentTitle != "" )
        {
            translator2Dictionary = [ "email" : self.textFieldTranslator2Email.text!,
                                      "lang"  : self.dictionaryLanguageOptions [self.buttonSelectLanguageTranslator2.currentTitle!]! ]
            translatorList.addObject(translator2Dictionary)
        }
        
        if ( self.textFieldTranslator3Email.text != "" ) &&
            (self.buttonSelectLanguageTranslator3.currentTitle != "Select language" && self.buttonSelectLanguageTranslator3.currentTitle != "" )
        {
            translator3Dictionary = [ "email" : self.textFieldTranslator3Email.text!,
                                      "lang"  : self.dictionaryLanguageOptions [self.buttonSelectLanguageTranslator3.currentTitle!]! ]
            translatorList.addObject(translator3Dictionary)
        }
        
        let dateFormatter = NSDateFormatter()
        dateFormatter.dateFormat = "dd-MM-yyyy, hh:mm a"

        let startDateSet = dateFormatter.dateFromString(self.labelSelectedStartDate.text!)! as NSDate
        var endDateSet: NSDate!
        // if end date is not set
        // set it ahead of start date set
        if self.labelSelectedEndDate.text == ""
        {
            let dateEnd = self.getNextHourDateFrom(startDateSet)
            let dateOneHourAheadString = dateFormatter.stringFromDate(dateEnd)
            self.labelSelectedEndDate.text = dateOneHourAheadString
            endDateSet = dateEnd
        }
        else
        {
            endDateSet = dateFormatter.dateFromString(self.labelSelectedEndDate.text!)! as NSDate
        }

        var start = startDateSet.timeIntervalSince1970
        start *= 1000.0
        
        // create dictionary of all the provided parameters
        let params = [ "action" : "scheduleMeeting",
                       "groupList" :[],
                       "meetingSn" : "",
                       "timeZone" : NSTimeZone.localTimeZone().name,
                       "shareDate" : self.getUTCFormatDate(startDateSet),
                       "startTime" : NSNumber( double: floor(start) ),
                       "length" : self.getMeetingLengthInMinutes(startDateSet, endDate: endDateSet),
                       "description" : meetingDescription,
                       "location" : "TC" ,
                       "meetingType" : meetingType!,
                       "recordMeeting" : recordMeeting,
                       "subject" : meetingSubject,
                       "emailList" : attendeesEmail,
                       "translatorList" : translatorList ]
        
        // call schedule meeting web service with params
        self.scheduleMeetingWith(params)
    }
    
    func joinScheduledMeeting(meetingID: String, fromViewController: UIViewController) -> Void {
        
        // search meeting with given ID
        self.searchMeetingWith(meetingID, completionHandler: { (responseDictionary, responseUrl, error) in
            
            if(responseDictionary != nil)
            {
                let returnCode = responseDictionary!["returnCode"] as? NSNumber
                if(returnCode != nil && returnCode?.intValue == 0)
                {
                    // collect server URL from response
                    let serverURL = responseDictionary!["serverURL"] as? String
                    
                    // join meeting with given meeting ID
                    self.joinMeetingByMeetingID(meetingID, completionHandler: { (responseDictionary, responseUrl, error) in
                        
                        if(responseDictionary != nil)
                        {
                            let returnCode = responseDictionary!["returnCode"] as? NSNumber
                            if(returnCode != nil && returnCode?.intValue == 0)
                            {
                                // fetch meetingUri referrer origin
                                // to provide it to the H2HSDK
                                let meetingUri = responseDictionary!["meetingUri"] as? String
                                let referrer = responseDictionary!["referer"] as? String
                                let origin = responseDictionary!["origin"] as? String
                                
                                dispatch_async(dispatch_get_main_queue(), {
                                    
                                    // hide activity indicator
                                    GUIUtility.sharedInstance.hideLoadingView()
                                    
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
    
    // calculate meeting length
    func getMeetingLengthInMinutes(startDate: NSDate, endDate: NSDate) -> NSNumber {
        
        let timeIntervalLengthInSeconds = endDate.timeIntervalSinceDate(startDate)
        let lengthInMinutes = NSNumber( double: floor( timeIntervalLengthInSeconds/60 ) )
        return lengthInMinutes
    }
    
    // returns date in UTC format
    func getUTCFormatDate(date: NSDate) -> NSString {
        
        let dateFormatter = NSDateFormatter()
        let timeZone = NSTimeZone(name: "UTC")
        dateFormatter.timeZone = timeZone
        dateFormatter.dateFormat = "yyyy-MM-dd HH:mm:ss"
        return dateFormatter.stringFromDate(date)
    }
    
    // checks if current time is within start and end time bounds
    // in order to start the meeting
    func checkIfCanJoinWith(startTime: NSNumber, endTime: NSNumber) -> Bool {
        
        let start: NSDate = NSDate(timeIntervalSince1970: Double(startTime)/1000)
        let oneHrBeforeStart: NSDate = NSDate(timeInterval: -3600, sinceDate: start)
        let end: NSDate = NSDate(timeIntervalSince1970: Double(endTime)/1000)
        let now = NSDate()
        
        if isDate(now, betweenStartDate: oneHrBeforeStart, andEndDate: end)
        {
            return true
        }
        
        return false
    }
    
    func isDate(date: NSDate, betweenStartDate: NSDate, andEndDate: NSDate) -> Bool {
        
        if date.compare(betweenStartDate) == NSComparisonResult.OrderedDescending && date.compare(andEndDate) == NSComparisonResult.OrderedAscending
        {
            return true
        }
        else
        {
            return false
        }
    }
    
    // calculates date of next hour
    func getNextHourDateFrom(date: NSDate) -> NSDate {
        let timeStamp: NSTimeInterval = date.timeIntervalSince1970
        let currentHour: NSTimeInterval = timeStamp - fmod(timeStamp, 3600)
        let nextHour: NSTimeInterval = currentHour + 3600
        
        return NSDate(timeIntervalSince1970: nextHour)
    }
    
    // MARK: Segue
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        
        if segue.identifier == "SCHEDULEMEETING_TO_SELECTIONLIST_LANGUAGESELECTION1" ||
            segue.identifier == "SCHEDULEMEETING_TO_SELECTIONLIST_LANGUAGESELECTION2" ||
            segue.identifier == "SCHEDULEMEETING_TO_SELECTIONLIST_LANGUAGESELECTION3"
        {
            // navigating to language selection UI.
            let selectionListViewController = segue.destinationViewController as! SelectionListViewController;
            // configure delegate
            selectionListViewController.delegate = self
            // pass array of languages (keys from dictionary: dictionaryLanguageOptions)
            selectionListViewController.arrayTableViewDataSource = Array(dictionaryLanguageOptions.keys)
        }
        else if segue.identifier == "SCHEDULEMEETING_TO_SELECTIONLIST_SELECTMEETING"
        {
            // navigating to select, meeting type.
            let selectionListViewController = segue.destinationViewController as! SelectionListViewController;
            // configure delegate
            selectionListViewController.delegate = self
            // pass array of meeting type (keys from dictionary: dictionaryMeetingType)
            selectionListViewController.arrayTableViewDataSource = Array(dictionaryMeetingType.keys)
        }
        else if segue.identifier == "SCHEDULEMEETING_TO_DATEPICKER_STARTDATE"
        {
            // navigating to select, start date.
            let datePickerViewController = segue.destinationViewController as! DatePickerViewController;

            selectedDateType = .StartDate
            datePickerViewController.minimumDate = NSDate()
            datePickerViewController.maximumDate = nil
            datePickerViewController.delegate = self
        }
        else if segue.identifier == "SCHEDULEMEETING_TO_DATEPICKER_ENDDATE"
        {
            // navigating to select, end date.
            let datePickerViewController = segue.destinationViewController as! DatePickerViewController;
            
            selectedDateType = .EndDate
            
            let dateFormatter = NSDateFormatter()
            dateFormatter.dateFormat = "dd-MM-yyyy, hh:mm a"
            let startDateSet = dateFormatter.dateFromString(self.labelSelectedStartDate.text!)
            
            let secondsInOneDay: NSTimeInterval = 60 * 60 * 24 * 1
            let dateOneDayAheadOfStartDate: NSDate = startDateSet!.dateByAddingTimeInterval(secondsInOneDay)

            datePickerViewController.minimumDate = startDateSet
            datePickerViewController.maximumDate = dateOneDayAheadOfStartDate
            datePickerViewController.delegate = self
        }
    }
    
    // MARK: DatePickerSelectedDateDelegate
    func datePicker(datePicker: DatePickerViewController, didSelectDate: NSDate) -> Void {
     
        switch selectedDateType {
        
        case .StartDate:
            
            let dateFormatter = NSDateFormatter()
            dateFormatter.dateFormat = "dd-MM-yyyy, hh:mm a"
            let dateString = dateFormatter.stringFromDate(didSelectDate)
            
            self.labelSelectedStartDate.text = dateString
            // clear end date, for start date has been modified
            self.labelSelectedEndDate.text = ""
            
            break
            
        case .EndDate:
            
            let dateFormatter = NSDateFormatter()
            dateFormatter.dateFormat = "dd-MM-yyyy, hh:mm a"
            let dateString = dateFormatter.stringFromDate(didSelectDate)
            
            self.labelSelectedEndDate.text = dateString
            
            break
        }
    }
    
    // MARK: TextField delegate
    func textFieldShouldReturn(textField: UITextField) -> Bool {
        self.view.endEditing(true)
        return false
    }
}