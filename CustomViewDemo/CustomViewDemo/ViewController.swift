//
//  ViewController.swift
//  CustomViewDemo
//
//  Created by ankita on 08/11/21.
//  Copyright © 2021 ankita. All rights reserved.


import UIKit

class ViewController: UIViewController {
    @IBOutlet weak var formView: FormView!
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        self.formView.delegate = self
    
    }


}
extension ViewController: FormViewDelegate{
    func submitData(data: [String : String]) {
        print(data)
    }
    
}
