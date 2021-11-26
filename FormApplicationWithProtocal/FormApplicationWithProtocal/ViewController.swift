//
//  ViewController.swift
//  FormApplicationWithProtocal
//


import UIKit

class ViewController: UIViewController {
    
    @IBOutlet weak var button: BTButton!
    @IBOutlet weak var fullNameLabel: BTLabel!
    @IBOutlet weak var emailLabel: BTLabel!
    @IBOutlet weak var genderLabel: BTLabel!
    @IBOutlet weak var dobLabel: BTLabel!
    @IBOutlet weak var infoView: UIView!
    

    override func viewDidLoad() {
        super.viewDidLoad()
        button.showEnabled()
        self.infoView.isHidden = true
    }
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if let receiverVC = segue.destination as? EmpFormViewController {
            receiverVC.delegate = self  // thats means call back is implemented in this class
        }
    }


}

// MARK: - FormViewControllerDelegate

extension ViewController: FormViewControllerDelegate {
    
    func submitDate(data: Emp) {
        if let firstName = data.fName, let lastName = data.lName {
            self.fullNameLabel.text = "Full Name: \(firstName) \(lastName)"
            self.fullNameLabel.halfTextColorChange(self.fullNameLabel.text ?? "", "\(firstName) \(lastName)")
        }
        if let email = data.email {
            self.emailLabel.text = "Email: \(email)"
            self.emailLabel.halfTextColorChange(self.emailLabel.text ?? "" , "\(email)")
        }
        if let gender = data.gender {
            self.genderLabel.text = "Gender: \(gender)"
            self.genderLabel.halfTextColorChange(self.genderLabel.text ?? "" , "\(gender)")
        }
        if let dob = data.dob {
            self.dobLabel.text = "DOB: \(dob)"
            self.dobLabel.halfTextColorChange(self.dobLabel.text ?? "", "\(dob)")
        }
        self.infoView.isHidden = false
    }
    
}

