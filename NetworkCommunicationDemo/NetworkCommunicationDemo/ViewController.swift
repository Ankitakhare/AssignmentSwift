//
//  ViewController.swift
//  NetworkCommunicationDemo
//
//  Created by ankita on 11/16/21.
//  Copyright © 2021 ankita. All rights reserved.
//
import UIKit

struct Company {
    var name: String?
    var catchPhrase: String?
    var bs: String?
}

struct Geo {
    var lat: String?
    var lan: String?
}

struct Address {
    var city: String?
    var geo: Geo?
    var street: String?
    var suite: String?
    var zipcode: String?
}

struct User {
    var id: Int?
    var name: String?
    var phone: String?
    var userName: String?
    var website: String?
    var email: String?
    var address: Address?
    var company: Company?
}


class ViewController: UIViewController {
    
    var userList:[User]?

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        let session = URLSession(configuration: URLSessionConfiguration.default)
        if let requestURL = URL(string: "https://jsonplaceholder.typicode.com/users") {
            let task = session.dataTask(with: requestURL) { (data, response, error) in
                //print(data)
                //print(response)
                //print(error)
                if error != nil || data == nil {
                    print("Ohoo no error")
                    
                    return
                }
                guard let serverResponse = response as? HTTPURLResponse,
                    (200...299).contains(serverResponse.statusCode) else {
                    print("Server side error")
                    return
                }
                /* - Mime Type indicats type of response data
                   - if it's JSON it should be "application/json"
                   - if it's plain text  "text/html"
                 */
                if let mimetype = serverResponse.mimeType, mimetype != "application/json" {
                    print("Invalid MimeType")
                    return
                }
                /* - Error check (no error)
                   - HTTPS status code (its 200 ok)
                   - Response type check (We got text/html its also file)
                   - We should parse response data
                 */
                if let data = data {
                    do {
                        /*
                         * 1. try
                         * 2. try?
                         * 3. try!
                         */
                        let jsonRespone = try JSONSerialization.jsonObject(with: data, options:[])
                        //print(jsonRespone)
                        /*
                           - JSONSerialization returning response in Any type
                           - inorder to manage data we have to convert into swift dictionary
                         */
                        if let responseDictionary = jsonRespone as? [[String: Any]] {
                            print(responseDictionary)
                            self.createUserModel(dictionaryList: responseDictionary)
                        }
                    } catch {
                        print("JSON Error: json parsing error")
                        
                    }
                }
            }
            task.resume()
        }
    }
    
    fileprivate func createUserModel(dictionaryList: [[String: Any]]) {
        self.userList = dictionaryList.map({ (userDictionay) -> User in
            var newUser = User()
            if let id = userDictionay["id"] as? Int {
                newUser.id = id
            }
            if let name = userDictionay["name"] as? String {
                newUser.name = name
            }
            if let phone = userDictionay["phone"] as? String {
                newUser.phone = phone
            }
            if let userName = userDictionay["userName"] as? String {
                newUser.userName = userName
            }
            if let website = userDictionay["website"] as? String {
                newUser.website = website
            }
            if let email = userDictionay["email"] as? String {
                newUser.email = email
            }
            if let addressDictionay = userDictionay["address"] as? [String: Any] {
                var newAddress = Address()
                if let city = addressDictionay["city"] as? String {
                    newAddress.city = city
                }
                if let street = addressDictionay["street"] as? String {
                    newAddress.street = street
                }
                if let suite = addressDictionay["suite"] as? String {
                    newAddress.suite = suite
                }
                if let zipcode = addressDictionay["zipcode"] as? String {
                    newAddress.zipcode = zipcode
                }
                if let geoDictionay = addressDictionay["geo"] as? [String: Any] {
                    var newGeo = Geo()
                    if let lat = geoDictionay["lat"] as? String {
                        newGeo.lat = lat
                    }
                    if let lng = geoDictionay["lng"] as? String {
                        newGeo.lan = lng
                    }
                    newAddress.geo = newGeo
                }
                newUser.address = newAddress
            }
            if let companyDictionay = userDictionay["company"] as? [String: Any] {
                var newCompany = Company()
                if let bs = companyDictionay["bs"] as? String {
                    newCompany.bs = bs
                }
                if let catchPhrase = companyDictionay["catchPhrase"] as? String {
                    newCompany.catchPhrase = catchPhrase
                }
                if let name = companyDictionay["catchPhrase"] as? String {
                    newCompany.name = name
                }
                newUser.company = newCompany
            }
            
            return newUser
        })
        print(self.userList?.count ?? 0)
    }

}

