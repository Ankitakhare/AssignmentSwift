//
//  FormView.swift
//  CustomViewDemo
//
//  Created by ankita on 08/11/21.
//  Copyright © 2021 ankita. All rights reserved.
//

import UIKit

protocol FormViewDelegate:  class {
    func  submitData(data: [String:String])
}
class FormView: UIView {

   
    @IBOutlet weak var contentView: UIView!
    weak var delegate: FormViewDelegate?
    @IBOutlet weak var firstNameLabel: UILabel!
    @IBOutlet weak var lastNameLabel: UILabel!
    @IBOutlet weak var emailLabel: UILabel!
    @IBOutlet weak var dobNameLabel: UILabel!
     
    override init(frame: CGRect) {
        super.init(frame: frame)
    }
    
    required init?(coder: NSCoder) {
        super.init(coder: coder)
    }

    override func awakeFromNib() {
        super.awakeFromNib()
       commonInit()
    }
    
    override func prepareForInterfaceBuilder() {
        super.prepareForInterfaceBuilder()
    }
    
    @IBAction func submitDataAction(_ sender :UIButton){
        let info =  ["firstname": self.firstNameLabel.text ?? "-",
                     "lastname": self.lastNameLabel.text ?? "-",
                     "email":self.emailLabel.text ?? "-","dob": self.dobNameLabel.text ?? "-"]
        
        self.delegate?.submitData(data: info)
        
    }
    // MARK: Private
   private func commonInit(){
        Bundle.main.loadNibNamed("FormView", owner: self, options: nil)
        self.addSubview(contentView)
        contentView.frame = self.bounds
        contentView.autoresizingMask = [.flexibleHeight,.flexibleWidth]
        contentView.translatesAutoresizingMaskIntoConstraints = true
        
    }
}

