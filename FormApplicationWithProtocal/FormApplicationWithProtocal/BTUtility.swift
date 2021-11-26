//
//  BTUtility.swift
//  FormApplicationWithProtocal
//

import UIKit

// MARK: - UITextField

extension UITextField {
    
    func setNormalState() {
        setBorderColor(UIColor.lightGray)
    }
    
    func setValidState() {
        setBorderColor(UIColor.green)
    }
    
    func setErrorState() {
        setBorderColor(UIColor.red)
    }
    
    private func setBorderColor(_ color: UIColor) {
        borderStyle = .none
        layer.borderColor = color.cgColor
        layer.borderWidth = 0.5
        layer.cornerRadius = 4
    }
    
}


// MARK: - String

extension String {
    
    func isValidLength(_ length: Int) -> Bool {
        
        return !self.isEmpty && self.count <= length
    }
    
    func isValidEmail() -> Bool {
        let emailRegEx = "[A-Z0-9a-z._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,64}"
        let emailPred = NSPredicate(format:"SELF MATCHES %@", emailRegEx)
        
        return emailPred.evaluate(with: self)
    }
    
}


// MARK: - Date

extension Date {
    
    func getFormattedDate() -> String {
        //"1996-04-20 20:00:00 +0000"
        // 20 Apr 1996
        let formatter = DateFormatter()
        formatter.dateFormat = "dd MMM yyyy"
        
        return formatter.string(from: self)
    }
}
