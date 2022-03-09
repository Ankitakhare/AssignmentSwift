
import UIKit

class CodeViewController: UIViewController, UITextFieldDelegate {
    
    @IBOutlet weak var codeField:UITextField!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        
        codeField.keyboardType = .numberPad
        codeField.delegate = self
        
    }
    

    @IBAction func verifyOTP(_ sender: Any) {
        guard let codetext = self.codeField.text else {return}
        if codetext.isEmpty{
            
            let alert = UIAlertController(title: "Error Message", message: "Enter OTP OTP Should not be empty" ,preferredStyle:UIAlertController.Style.alert)

            alert.addAction(UIAlertAction(title: "Cancel", style: UIAlertAction.Style.default, handler: { _ in
                        //Cancel Action
                    }))
                    alert.addAction(UIAlertAction(title: "Ok",
                                                  style: UIAlertAction.Style.default,
                                                  handler: {(_: UIAlertAction!) in
                                                    
                    }))
                    self.present(alert, animated: true, completion: nil)
            
        }else{
            if let text = codeField.text, !text.isEmpty{
            let code = text
            AuthManager.shared.varifyCode(smsCode: code) {[weak self] success in
                guard success else{return}
                let storyBoard : UIStoryboard = UIStoryboard(name: "Main", bundle:nil)
                let mapcontroller = storyBoard.instantiateViewController(withIdentifier: "MapVC") as! MapViewController
                self?.present(mapcontroller,animated:  false)
            }
            }
        }
    }

  
//MARK: - Text Field Delegate Methods

    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
        codeField.resignFirstResponder()
       
        return true
    }
    
    func textFieldDidBeginEditing(_ textField: UITextField) {
        //lblMessage.isHidden = true
        codeField.layer.borderWidth = 0
        //passwordTextField.layer.borderWidth = 0
    }
   
    
    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
        self.view.endEditing(true)
    }
}
