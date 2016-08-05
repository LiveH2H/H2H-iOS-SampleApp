//
//  MainMenuTableViewController.swift
//  H2HSDKIntegrationSample
//
//  Created by charuta.rajopadhye on 21/07/16.
//  Copyright © 2016 Spring Computing Technologies. All rights reserved.
//

import Foundation
import UIKit

class MainMenuTableViewController : UITableViewController {
    
    // MARK: UITableViewDelegate methods
    override func tableView(tableView: UITableView, didSelectRowAtIndexPath indexPath: NSIndexPath)
    {
        // sign out clicked
        if indexPath.row == 5
        {
            // clear user info saved from login web service
            Core.sharedInstance.userInfo = nil
            tableView.deselectRowAtIndexPath(indexPath, animated: true)
            GUIUtility.sharedInstance.dismissLoadingAndDisplayAlertWith("Sign out success", message: "You have successfully signed out!")
        }
        // start meeting clicked
        else if indexPath.row == 2
        {
            // we need to pass apitoken as header recieved from login web service to start a meeting web service
            if Core.sharedInstance.userInfo == nil
            {
                tableView.deselectRowAtIndexPath(indexPath, animated: true)
                GUIUtility.sharedInstance.dismissLoadingAndDisplayAlertWith( "Login Required",
                                                                             message: "You need to login to start a meeting.")
            }
            else
            {
                self.performSegueWithIdentifier("MENU_TO_STARTMEETING", sender: nil)
            }
        }
        // schedule meeting clicked
        else if indexPath.row == 3
        {
            // we need to pass apitoken as header recieved from login web service to schedule a meeting web service
            if Core.sharedInstance.userInfo == nil
            {
                tableView.deselectRowAtIndexPath(indexPath, animated: true)
                GUIUtility.sharedInstance.dismissLoadingAndDisplayAlertWith( "Login Required",
                                                                             message: "You need to login to schedule a meeting.")
            }
            else
            {
                self.performSegueWithIdentifier("MENU_TO_SCHEDULEMEETING", sender: nil)
            }
        }
    }
}
