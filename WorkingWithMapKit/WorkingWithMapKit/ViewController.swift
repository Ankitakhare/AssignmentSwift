//
//  ViewController.swift
//  WorkingWithMapKit
//
//
//  Created by ankita on 17/11/21.
//  Copyright © 2021 ankita. All rights reserved.
//


import UIKit
import MapKit
import CoreLocation

class ViewController: UIViewController, MKMapViewDelegate, CLLocationManagerDelegate {
    
    @IBOutlet weak var mapView: MKMapView!
    
    lazy var countyCapitals:[Capital] = {
        
        return [Capital(title: "Delhi", coordinate: CLLocationCoordinate2D(latitude: 28.6172, longitude: 77.2082), info: "Parliament Of India"),
                Capital(title: "London", coordinate: CLLocationCoordinate2D(latitude: 51.5387, longitude: 0.0166), info: "Home to the 2012 Summer Olympics "),
                Capital(title: "Paris", coordinate: CLLocationCoordinate2D(latitude: 48.8566, longitude: 2.3522), info: "Often called the City of Light"),
                Capital(title: "Rome", coordinate: CLLocationCoordinate2D(latitude: 41.9028, longitude: 12.4964), info: "Has a whole country inside it."),
                Capital(title: "Washington DC", coordinate: CLLocationCoordinate2D(latitude: 38.9072, longitude: -77.0369), info: "Named after George himself.")
        ]
    }()
    var locationManager:CLLocationManager?
    

    override func viewDidLoad() {
        super.viewDidLoad()
//        for item in self.countyCapitals {
//            mapView.addAnnotation(item)
//        }
        mapView.addAnnotations(self.countyCapitals)
        mapView.delegate = self
        
        self.locationManager = CLLocationManager()
        self.locationManager?.delegate = self
        self.locationManager?.requestWhenInUseAuthorization()
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        let status  = CLLocationManager.authorizationStatus()
        if status == .notDetermined {
            self.locationManager?.requestWhenInUseAuthorization()
        } else if status == .denied || status == .restricted {
            self.showLocationSetUpAlert()
        }  else if CLLocationManager.locationServicesEnabled() {
             self.locationManager?.startUpdatingLocation()
        }
    }
    
    func showLocationSetUpAlert() {
        let alert = UIAlertController(title: "Error", message: "Change location setting", preferredStyle: .alert)
        let okAction = UIAlertAction(title: "settings", style: .default) { (okAction) in
            if let url = URL(string: UIApplication.openSettingsURLString) {
                UIApplication.shared.open(url, options: self.convertToUIApplicationOpenExternalURLOptionsKeyDictionary([:]), completionHandler: nil)
            }
        }
        let cancelAction = UIAlertAction(title: "cancel", style: .default) { (cancelAction) in}
        alert.addAction(okAction)
        alert.addAction(cancelAction)
        present(alert, animated: true, completion: nil)
    }
    
    fileprivate func convertToUIApplicationOpenExternalURLOptionsKeyDictionary(_ input: [String: Any]) -> [UIApplication.OpenExternalURLOptionsKey: Any] {

        return Dictionary(uniqueKeysWithValues: input.map { key, value in (UIApplication.OpenExternalURLOptionsKey(rawValue: key), value)})
    }
    
    // MARK: - MKMapViewDelegate
    
    func mapViewWillStartLoadingMap(_ mapView: MKMapView) {
        print("mapViewWillStartLoadingMap")
    }
    
    func mapViewDidFinishLoadingMap(_ mapView: MKMapView) {
        //let camera = MKMapCamera(lookingAtCenter: CLLocationCoordinate2D(latitude: 28.6172, longitude: 77.2082), fromDistance: 500.0, pitch: 0.0, heading: 2.0)
        //mapView.setCamera(camera, animated: true)
    }
    
    func mapView(_ mapView: MKMapView, viewFor annotation: MKAnnotation) -> MKAnnotationView? {
        guard annotation is Capital else { return nil }
        
        let identifier = "Capital"
        
        var annotationView = mapView.dequeueReusableAnnotationView(withIdentifier: identifier)
        
        if annotationView == nil {
            annotationView = MKPinAnnotationView(annotation: annotation, reuseIdentifier: identifier)
            annotationView?.canShowCallout = true
            
            let btn = UIButton(type: .detailDisclosure)
            annotationView?.rightCalloutAccessoryView = btn
        } else {
            annotationView?.annotation = annotation
        }
        
        return annotationView
    }
    
    func mapView(_ mapView: MKMapView, annotationView view: MKAnnotationView, calloutAccessoryControlTapped control: UIControl) {
        guard let capital = view.annotation as? Capital else { return }
        
        let placeName = capital.title
        let placeInfo = capital.info
        
        let alertController = UIAlertController(title: placeName, message: placeInfo, preferredStyle: .alert)
        alertController.addAction(UIAlertAction(title: "Ok", style: .default, handler: nil))
        self.present(alertController, animated: true, completion: nil)
    }
    
    // MARK: - CLLocationManagerDelegate
    
    func locationManager(_ manager: CLLocationManager, didChangeAuthorization status: CLAuthorizationStatus) {
        if status == .denied {
           // let alertController = UIAlertController(title: "Error!!", message: "Location Denied", preferredStyle: .alert)
           // alertController.addAction(UIAlertAction(title: "Ok", style: .default, handler: nil))
           // self.present(alertController, animated: true, completion: nil)
        } else if status == .authorizedAlways {
            // We not requesting for this
            
        } else if status == .authorizedWhenInUse {
            manager.desiredAccuracy = kCLLocationAccuracyKilometer
            locationManager?.distanceFilter = 500
            manager.startUpdatingLocation()
        }
    }
    
    func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        let location = locations.first
        print("Lat:\(location?.coordinate.latitude ?? 0.0) Log:\(location?.coordinate.longitude ?? 0.0)")
        
        let annotation = Capital(title: "Current Location", coordinate: CLLocationCoordinate2D(latitude: location?.coordinate.latitude ?? 0.0, longitude: location?.coordinate.longitude ?? 0.0), info: "")
        mapView.addAnnotation(annotation)
        
        let camera = MKMapCamera(lookingAtCenter: CLLocationCoordinate2D(latitude:location?.coordinate.latitude ?? 0.0 , longitude: location?.coordinate.longitude ?? 0.0), fromDistance: 0.0, pitch: 0.0, heading: 2.0)
        mapView.setCamera(camera, animated: true)
        
        manager.stopUpdatingLocation()
    }
    



}

