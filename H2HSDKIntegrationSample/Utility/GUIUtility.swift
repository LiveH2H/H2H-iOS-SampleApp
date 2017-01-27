//
//  GUIUtility.swift
//  H2HSDKIntegrationSample
//
//  Created by charuta.rajopadhye on 25/07/16.
//  Copyright © 2016 Spring Computing Technologies. All rights reserved.
//

import Foundation
import UIKit

let kTagLoadingViewControllerViewOnWindow = 500501
let kTagDatePickerControllerViewOnWindow = 500502

class GUIUtility : NSObject {
    
    static let sharedInstance = GUIUtility()
    
    
    // MARK: Loading view methods
    func displayLoadingView()  {
        
        dispatch_async(dispatch_get_main_queue()) {
            
            let storyboard = UIStoryboard(name: "Main", bundle: nil)
            let loadingViewController = storyboard.instantiateViewControllerWithIdentifier("StoryboardID_LoadingViewController")
            
            loadingViewController.view.tag = kTagLoadingViewControllerViewOnWindow
            UIApplication.sharedApplication().keyWindow?.addSubview(loadingViewController.view)
        }

    }
    
    func hideLoadingView() {

        dispatch_async(dispatch_get_main_queue()) {
            
            let arraySubViews = UIApplication.sharedApplication().keyWindow?.subviews
            
            if arraySubViews != nil && arraySubViews?.count != 0
            {
                for subView in arraySubViews!
                {
                    if subView.tag == kTagLoadingViewControllerViewOnWindow
                    {
                        subView.removeFromSuperview()
                    }
                }
            }
        }
    }
    
    func dismissLoadingAndDisplayAlertWith(title: String, message: String) -> Void {
        
        dispatch_async(dispatch_get_main_queue()) {
            
            // hide loading view controller
            self.hideLoadingView()
            
            // display alret view controller
            let alertController = UIAlertController ( title: title,
                                                      message: message,
                                                      preferredStyle: .Alert)
            
            let defaultAction = UIAlertAction (title: "Ok", style: .Cancel, handler: nil)
            alertController.addAction (defaultAction)
            
            if var topController = UIApplication.sharedApplication().keyWindow?.rootViewController {
                while let presentedViewController = topController.presentedViewController {
                    topController = presentedViewController
                }
                
                // topController should now be your topmost view controller
                topController.presentViewController (alertController, animated: true, completion: nil)
            }
        }
    }
}