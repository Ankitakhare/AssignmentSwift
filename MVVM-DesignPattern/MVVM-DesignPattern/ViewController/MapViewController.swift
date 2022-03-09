//
//  MapViewController.swift
//  MVVM-DesignPattern
//
//  Created by Ankita Khare on 07/03/22.


import UIKit
import MapKit
import CoreLocation




class MapViewController: UIViewController, MKMapViewDelegate{
    //MARK:- Variable Declarations

    @IBOutlet weak var mMapView: MKMapView!
    let locationManager = CLLocationManager()
    
    
    override func viewDidLoad() {
    super.viewDidLoad()
        self.navigationItem.title = "Login Page"
    locationManager.delegate = self
    locationManager.desiredAccuracy = kCLLocationAccuracyBest
    //mMapView.showsUserLocation = true
    
    checkLocationAuthorizationStatus()
    }
    
    
    
    func checkLocationAuthorizationStatus() {
    let status = CLLocationManager.authorizationStatus()
        if status == CLAuthorizationStatus.notDetermined{
    print("NotDetermined")
    locationManager.requestWhenInUseAuthorization()
    CLLocationManager.locationServicesEnabled()
    locationManager.requestLocation()
    locationManager.stopUpdatingLocation()
    }else {
    print("Problem with authorization")
    }
    }
    
    
    
    
    override func didReceiveMemoryWarning() {
    super.didReceiveMemoryWarning()
    }
    
    @IBAction func done(sender: AnyObject) {
        self.dismiss(animated: true)
    }
}

extension MapViewController : CLLocationManagerDelegate {

   

    func locationManager(_ manager: CLLocationManager, didChangeAuthorization status: CLAuthorizationStatus) {
        if status == .authorizedWhenInUse {
            locationManager.requestLocation()
        }
    }

func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {

        if locations.first != nil {
          print("location: (location)")
            
            
    }
    }
    
    
    
    
    func locationManager(_ manager: CLLocationManager, didFailWithError error: Error) {
       
         print("error:: \(error.localizedDescription)")
    }
}



