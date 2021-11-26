//
//  EmpFormViewController.swift
//  FormApplicationWithProtocal
//


import UIKit

protocol FormViewControllerDelegate: class {
    
    func submitDate(data: Emp)
    
}

class EmpFormViewController: UIViewController {
    
    @IBOutlet weak var firstNameLable: BTLabel!
    @IBOutlet weak var lastNameLable: BTLabel!
    @IBOutlet weak var emailLable: BTLabel!
    @IBOutlet weak var genderLable: BTLabel!
    @IBOutlet weak var maleGenderLable: BTLabel!
    @IBOutlet weak var femaleGenderLable: BTLabel!
    @IBOutlet weak var dobLable: BTLabel!
    
    @IBOutlet weak var submitButton: BTButton!
    @IBOutlet weak var closeButton: BTButton!
    @IBOutlet weak var maleButton: UIButton!
    @IBOutlet weak var femaleButton: UIButton!
    
    @IBOutlet weak var firstNameField: UITextField!
    @IBOutlet weak var lastNameField: UITextField!
    @IBOutlet weak var emailIDField: UITextField!
    @IBOutlet weak var dobFiled: UITextField!
    
    private var datePicker: UIDatePicker?
    
    weak var delegate: FormViewControllerDelegate?
    
    
    // MARK: - Life cycle methods

    override func viewDidLoad() {
        super.viewDidLoad()
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        setupUI()
    }
    
    // MARK: - Private Method
    
    private func setupUI() {
        firstNameLable.configureLabel()
        lastNameLable.configureLabel()
        emailLable.configureLabel()
        genderLable.configureLabel()
        maleGenderLable.configureLabel()
        femaleGenderLable.configureLabel()
        dobLable.configureLabel()
        maleButton.setImage(UIImage(named:"radiobutton_unchecked"), for: .normal)
        femaleButton.setImage(UIImage(named:"radiobutton_unchecked"), for: .normal)
        maleButton.setImage(UIImage(named:"radiobutton_checked"), for: .selected)
        femaleButton.setImage(UIImage(named:"radiobutton_checked"), for: .selected)
        maleButton.isSelected = true
        femaleButton.isSelected = false
        maleButton.isEnabled = true
        femaleButton.isEnabled = true
        closeButton.isEnabled = true
        
        firstNameField.setNormalState()
        firstNameField.returnKeyType = .next
        lastNameField.setNormalState()
        lastNameField.returnKeyType = .next
        emailIDField.setNormalState()
        emailIDField.returnKeyType = .done
        
        dobFiled.setNormalState()
    }
    
    private func showDatePicker() {
        if let picker = datePicker {
            dobFiled.inputView = picker
        } else {
            datePicker = UIDatePicker(frame: CGRect(x: 0, y: self.view.frame.size.height - 200, width: self.view.frame.size.width, height: 200))
            datePicker?.backgroundColor = UIColor.blue.withAlphaComponent(0.1)
            datePicker?.datePickerMode = .date
            datePicker?.maximumDate = setMaxDate()
            dobFiled.inputView = datePicker
            datePicker?.addTarget(self, action: #selector(datePickerValueChange), for: .valueChanged)
            let toolBar = UIToolbar()
            toolBar.backgroundColor = UIColor.systemPink
            toolBar.sizeToFit()
            let doneButton = UIBarButtonItem(title: "Done", style: .done, target:self, action: #selector(doneClicked))
            let closeButton = UIBarButtonItem(title: "Close", style: .done, target:self, action: #selector(closeClicked))
            let flexibleSpace = UIBarButtonItem(barButtonSystemItem: .flexibleSpace, target: nil, action: nil)
            toolBar.setItems([closeButton,flexibleSpace,doneButton], animated: true)
            dobFiled.inputAccessoryView = toolBar
        }
    }
    
    private func setMaxDate() -> Date {
         let currentCalendar = Calendar.current
         var component = currentCalendar.dateComponents([.year, .month, .day], from: Date())
         let minAgeYear = 18
         if let currentYear = component.year {
             component.year = (currentYear - minAgeYear)
         }
     
         return currentCalendar.date(from: component) ?? Date()
     }
    
    private func enableSubmitButton(enable: Bool) {
        if enable {
            submitButton.showEnabled()
        } else {
            submitButton.showDisabled()
        }
    }
    
    private func validateInputField() {
        if firstNameField.text?.isValidLength(10) ?? false &&
            lastNameField.text?.isValidLength(10) ?? false &&
            emailIDField.text?.isValidEmail() ?? false &&
            !(dobFiled.text?.isEmpty ?? false) {
            enableSubmitButton(enable: true)
        } else {
            enableSubmitButton(enable: false)
        }
    }
    
    // MARK: - Actions
    
    @IBAction func submitAction() {
        let empData = Emp(firstName: self.firstNameField.text ?? "",
                          lastName: self.lastNameField.text ?? "",
                          email: self.emailIDField.text ?? "",
                          gender: self.maleButton.isSelected ? "Male" : "Female",
                          dob: self.dobFiled.text ?? "")
        let alertcontroller = UIAlertController(title: "Alert!!", message: "Do you want to Submit data?", preferredStyle: .alert)
        let okAction = UIAlertAction(title: "Ok", style: .default) {[weak self] (_) in
            self?.delegate?.submitDate(data: empData) //callback to ViewController
            self?.dismiss(animated: true, completion: nil)
        }
        let cancelAction = UIAlertAction(title: "Cancel", style: .default, handler: nil)
        alertcontroller.addAction(okAction)
        alertcontroller.addAction(cancelAction)
        self.present(alertcontroller, animated: true, completion: nil)
    }
    
    @IBAction func closeButtonAction(_ sender: BTButton) {
        self.dismiss(animated: true, completion: nil)
    }
    
    @IBAction func genderChangeAction(_ sender: UIButton) {
        maleButton.isSelected = !maleButton.isSelected
        femaleButton.isSelected = !femaleButton.isSelected
    }
    
    @objc func datePickerValueChange() {
        dobFiled.text = datePicker?.date.getFormattedDate()
    }
    
    @objc func doneClicked() {
        dobFiled.text = datePicker?.date.getFormattedDate()
        self.dobFiled.endEditing(true)
    }
    
    @objc func closeClicked() {
        self.dobFiled.endEditing(true)
    }
    
}


// MARK: - UITextFieldDelegate

extension EmpFormViewController: UITextFieldDelegate {
    
    func textFieldShouldBeginEditing(_ textField: UITextField) -> Bool {
        self.enableSubmitButton(enable: false)
        if textField == dobFiled {
            textField.resignFirstResponder()
            showDatePicker()
            
            return true
        }
        
        return true
    }
    
    func textFieldDidBeginEditing(_ textField: UITextField) {
        textField.setNormalState()
    }
    
    func textFieldShouldEndEditing(_ textField: UITextField) -> Bool {
        
        return true
    }
    
    func textFieldDidEndEditing(_ textField: UITextField) {
        if textField == firstNameField || textField == lastNameField {
            if let isValid = textField.text?.isValidLength(10), isValid {
                textField.setValidState()
            } else {
                textField.setErrorState()
            }
        }
        if textField == emailIDField {
            if let isValid = textField.text?.isValidEmail(), isValid {
                textField.setValidState()
            } else {
                textField.setErrorState()
            }
        }
        self.validateInputField()
    }
    
    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
        if textField == firstNameField {
            lastNameField.becomeFirstResponder()
        } else if textField == lastNameField {
            emailIDField.becomeFirstResponder()
        } else if textField == emailIDField {
            textField.resignFirstResponder()
        }
        
        return true
    }
    
}
