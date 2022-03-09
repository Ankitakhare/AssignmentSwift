//
//  ViewController.swift
//  MVVM-DesignPattern
//

//

import UIKit

class PhoneViewController: UIViewController,UITextFieldDelegate {

    @IBOutlet weak var lblMessage:UILabel!
    @IBOutlet weak var phonenumber:UITextField!
   

    var authenticationVM : AuthenticationVM!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.navigationItem.title = "Login Page"
        self.phonenumber.delegate = self
        
        // Do any additional setup after loading the view.
        self.lblMessage.isHidden = true
    }

    //MARK:- loginUser
    @IBAction func loginUser(_ sender: Any) {
        self.lblMessage.isHidden = true
        guard let phonenumber = self.phonenumber.text else {return}
        //guard let password = self.txtPassword.text else {return}
        if phonenumber.isEmpty{
            self.lblMessage.isHidden = false
            self.lblMessage.text = "Phone number should not be empty"
            
        }else{
            
            self.lblMessage.isHidden = true
            validationCheck()
           
        }
        //authenticationVm.authenticateUserWith(_phonenumber: phonenumber)
    }
        
    
    func validationCheck(){
        guard let phonenumber = self.phonenumber.text else {return}
        if !isValidPhoneNumber(phone: phonenumber){
            let alert = UIAlertController(title: "Error Message", message: "Phone number is invalid please enter correct number",         preferredStyle: UIAlertController.Style.alert)

            alert.addAction(UIAlertAction(title: "Cancel", style: UIAlertAction.Style.default, handler: { _ in
                        //Cancel Action
                    }))
                    alert.addAction(UIAlertAction(title: "Ok",
                                                  style: UIAlertAction.Style.default,
                                                  handler: {(_: UIAlertAction!) in
                                                    
                    }))
                    self.present(alert, animated: true, completion: nil)
            
        }else{
            AuthManager.shared.startAuth(phoneNumber: phonenumber) {[weak self ] success in
                guard success else{   return }
                let storyBoard : UIStoryboard = UIStoryboard(name: "Main", bundle:nil)
                let codecontroller = storyBoard.instantiateViewController(withIdentifier: "CodeViewControllerVC") as! CodeViewController
                codecontroller.modalPresentationStyle = . fullScreen
                self?.present(codecontroller,animated:  false)
                    }
            }
            
          

        }
        
    
            
     
    func isValidPhoneNumber(phone:String) -> Bool {
        
                let phoneRegex = "^[0-9+]{0,1}+[0-9]{5,16}$"
                let phoneTest = NSPredicate(format: "SELF MATCHES %@", phoneRegex)
                return phoneTest.evaluate(with: phone)
            }

            
    
    

//MARK: - Text Field Delegate Methods

    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
        phonenumber.resignFirstResponder()
        //passwordTextField.resignFirstResponder()
        return true
    }
    
    func textFieldDidBeginEditing(_ textField: UITextField) {
        lblMessage.isHidden = true
        phonenumber.layer.borderWidth = 0
        //passwordTextField.layer.borderWidth = 0
    }
    
    
    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
        self.view.endEditing(true)
    }
}


