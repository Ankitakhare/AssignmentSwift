//
//  BTLabel.swift
//  FormApplicationWithProtocal
//
//  Created by Balu Naik on 4/20/20.
//  Copyright © 2020 BaluTutorial. All rights reserved.
//

import UIKit

class BTLabel: UILabel {

    public override init(frame: CGRect) {
        super.init(frame: frame)
        configureLabel()
    }
    
    required init?(coder: NSCoder) {
        super.init(coder: coder)
    }
    
    public override func awakeFromNib() {
        super.awakeFromNib()
        configureLabel()
    }
    
    public override func prepareForInterfaceBuilder() {
        super.prepareForInterfaceBuilder()
        configureLabel()
    }
    
    // MARK: - Private
    
    func configureLabel() {
        self.textAlignment = .center
        self.backgroundColor = UIColor(white: 0.2, alpha: 0.2)
        let font = UIFont(name: "Chalkboard-Bold", size: 14.0)
        self.font = font
        makeBorder()
    }
    
    private func makeRoundedEdges() {
        self.layer.cornerRadius = 4.0
        setNeedsDisplay()
    }
    
    func makeBorder() {
        self.layer.borderWidth = 1.0
        self.layer.borderColor = UIColor.red.cgColor
        self.makeRoundedEdges()
    }
    
    func halfTextColorChange(_ fullText: String , _ changeText: String) {
        let strNumber: NSString = fullText as NSString
        let range = (strNumber).range(of: changeText)
        let attribute = NSMutableAttributedString.init(string: fullText)
        attribute.addAttribute(NSAttributedString.Key.font, value: UIFont(name: "Courier", size: 14)! , range: range)
        attribute.addAttribute(NSAttributedString.Key.foregroundColor, value: UIColor.red , range: range)
        self.attributedText = attribute
    }

}
