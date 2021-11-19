//
//  Capital.swift
//  WorkingWithMapKit
//
//  Created by ankita on 17/11/21.
//  Copyright © 2021 ankita. All rights reserved.
//

import Foundation
import MapKit

class Capital: NSObject, MKAnnotation {
    
    var title: String?
    var info: String?
    var coordinate: CLLocationCoordinate2D
    
    init(title: String, coordinate: CLLocationCoordinate2D, info: String) {
        self.title = title
        self.coordinate = coordinate
        self.info = info
    }
    
}
