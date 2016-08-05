//
//  SelectionListViewController.swift
//  H2HSDKIntegrationSample
//
//  Created by charuta.rajopadhye on 22/07/16.
//  Copyright © 2016 Spring Computing Technologies. All rights reserved.
//

import Foundation
import UIKit

protocol SelectedStringDelegate {
    
    func selectionList(selectionList: SelectionListViewController,  didSelectString: NSString, fromDataSource: NSArray, atIndexPath: NSIndexPath)
}

class SelectionListViewController : UIViewController, UITableViewDelegate, UITableViewDataSource {
    
    // MARK - properties
    
    // array that is used as data source to populate the table view
    var arrayTableViewDataSource: NSArray = []
    
    // object to view controller to which selection is to be delegated
    var delegate: SelectedStringDelegate! = nil
    
    // MARK: Lifecycle methods
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.navigationItem.title = "Pick your choice"
        self.navigationItem.hidesBackButton = true
    }

    // MARK: - Tableview Delegate & Datasource
    func tableView(tableView:UITableView, numberOfRowsInSection section:Int) -> Int
    {
        if delegate != nil && arrayTableViewDataSource.count != 0
        {
            return self.arrayTableViewDataSource.count
        }
        else
        {
            return 0
        }
    }
    
    func numberOfSectionsInTableView(tableView: UITableView) -> Int
    {
        return 1
    }
    
    func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell
    {
        let cell: UITableViewCell = UITableViewCell(style: UITableViewCellStyle.Subtitle, reuseIdentifier: "CELL_SELECTIONLIST")
        
        let labelTitle = arrayTableViewDataSource[indexPath.row] as! String
        cell.textLabel!.text = labelTitle
        
        return cell
    }
    
    func tableView(tableView: UITableView, didSelectRowAtIndexPath indexPath: NSIndexPath)
    {
        if delegate != nil
        {
            // call the delegate
            self.delegate.selectionList(self,
                                        didSelectString: self.arrayTableViewDataSource[indexPath.row] as! NSString,
                                        fromDataSource: arrayTableViewDataSource,
                                        atIndexPath: indexPath)
            
            // pop view controller
            self.navigationController!.popViewControllerAnimated(true)
        }
    }
}
