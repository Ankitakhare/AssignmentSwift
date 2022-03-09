//
//  LocationManager.swift
//  MVVM-DesignPattern
//
//  Created by Ankita Khare on 09/03/22.



//import CoreLocation
import Foundation

/*class LocationManager : NSObject,CLLocationManagerDelegate{
    static let shared = LocationManager()
    
    let manager = CLLocationManager()
     
    var completion: ((CLLocation)->Void)?
    
    public func getUserLocation(completion: @escaping ((CLLocation) ->Void)){
        manager.requestWhenInUseAuthorization()
        manager.delegate = self
        manager.startUpdatingLocation()
    }
    
    public func resolveLocationName(with location: CLLocation ,completion: @escaping ((String?)-> Void)){
        
        let geocoder = CLGeocoder()
        geocoder.reverseGeocodeLocation(location, preferredLocale: .current) { placemarks, error in
            guard let place = placemarks?.first,error == nil else{
                completion(nil)
                return
            }
            print(place)
            var name  = ""
            if let locality = place.locality{
                name += locality
            }
            if let adminRegion = place.administrativeArea{
                name  +=  ",\(adminRegion)"
            }
                
              completion(name)
            
        }
    }
    
    
    
    
    func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        guard let location = locations.first else{
            return
        }
        completion?(location)
        manager.stopUpdatingLocation()
    }
}

*/
