//
//  DatePickerViewController.swift
//  H2HSDKIntegrationSample
//
//  Created by charuta.rajopadhye on 26/07/16.
//  Copyright © 2016 Spring Computing Technologies. All rights reserved.
//

import Foundation
import UIKit

protocol DatePickerSelectedDateDelegate {
    
    func datePicker(datePicker: DatePickerViewController, didSelectDate: NSDate) -> Void
}

class DatePickerViewController: UIViewController {
    
    // MARK: Properties
    var minimumDate: NSDate!
    var maximumDate: NSDate!
    
    // object to view controller to which selection is to be delegated
    var delegate: DatePickerSelectedDateDelegate! = nil
    
    // MARK: IBOutlet
    @IBOutlet weak var viewBase: UIView!
    
    @IBOutlet weak var datePicker: UIDatePicker!
    
    // MARK: Lifecycle methods
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.navigationItem.title = "Set Date"
        self.navigationItem.hidesBackButton = true
        
        if let minDate = self.minimumDate
        {
            self.datePicker.minimumDate = minDate
        }
        
        if let maxDate = self.maximumDate
        {
            self.datePicker.maximumDate = maxDate
        }
    }
    
    // MARK: IBActions
    @IBAction func buttonSetDateClicked(sender: AnyObject) {
        
        if delegate != nil
        {
            delegate.datePicker(self, didSelectDate: self.datePicker.date)
        }
        
        self.navigationController?.popViewControllerAnimated(true)
    }    
}
