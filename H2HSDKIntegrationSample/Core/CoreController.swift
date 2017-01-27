//
//  CoreController.swift
//  H2HSDKIntegrationSample
//
//  Created by charuta.rajopadhye on 28/07/16.
//  Copyright © 2016 Spring Computing Technologies. All rights reserved.
//

import Foundation

class Core: NSObject {
    
    // singleton instance of Core
    static let sharedInstance = Core()
    
    // data recieved from Login web service
    var userInfo: UserInfo?
}