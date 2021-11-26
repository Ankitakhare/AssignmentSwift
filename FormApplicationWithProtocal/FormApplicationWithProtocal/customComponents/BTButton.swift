//
//  BTButton.swift
//  FormApplicationWithProtocal
//
//  Created by Balu Naik on 4/20/20.
//  Copyright © 2020 BaluTutorial. All rights reserved.
//

import UIKit

@IBDesignable class BTButton: UIButton {
    
    @IBInspectable
    var cornerRadius: CGFloat = 4.0 {
        didSet {
            self.makeRoundedEdges()
        }
    }
    
    @IBInspectable
    var borderColor: UIColor = UIColor.black {
        didSet {
            self.makeBorder()
        }
    }
    
    public override init(frame: CGRect) {
        super.init(frame: frame)
        configureButton()
    }
    
    required init?(coder: NSCoder) {
        super.init(coder: coder)
    }
    
    public override func awakeFromNib() {
        super.awakeFromNib()
        configureButton()
    }
    
    public override func prepareForInterfaceBuilder() {
        super.prepareForInterfaceBuilder()
        configureButton()
    }
    
    // MARK: - Private methods
    
    func configureButton() {
        self.backgroundColor = UIColor(red: 100/255, green: 120/255, blue: 140/255, alpha: 1)
        self.showDisabled()
        self.makeBorder()
    }
    
    private func makeRoundedEdges() {
        self.layer.cornerRadius = self.cornerRadius
        setNeedsDisplay()
    }
    
    // MARK: - Public Methods
    
    func showDisabled() {
        self.backgroundColor = UIColor.lightGray
        self.isEnabled = false
        self.titleLabel?.textColor = UIColor.white
    }
    
    func showEnabled() {
        self.backgroundColor = UIColor(red: 81, green: 192, blue: 169, alpha: 1)
        self.isEnabled = true
        self.setTitleColor(UIColor.black, for: .normal)
    }
    
    func makeBorder() {
        self.layer.borderWidth = 1.0
        self.layer.borderColor = self.borderColor.cgColor
        self.makeRoundedEdges()
    }
    
    func setButtonTitle( title: String) {
        self.setTitle(title, for: .normal)
    }
    
}
