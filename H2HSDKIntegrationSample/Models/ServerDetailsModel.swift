//
//  ServerLocationModel.swift
//  H2HSDKIntegrationSample
//
//  Created by charuta.rajopadhye on 22/07/16.
//  Copyright © 2016 Spring Computing Technologies. All rights reserved.
//

import Foundation

class ServerDetailsModel : NSObject {
    
    var stringCountryName: String
    var stringServerLocation: String
    var stringServerURL: String
    
    init (stringCountryName: String, stringServerLocation: String, stringServerURL: String) {
        
        self.stringCountryName = stringCountryName
        self.stringServerLocation = stringServerLocation
        self.stringServerURL = stringServerURL
    }
}
