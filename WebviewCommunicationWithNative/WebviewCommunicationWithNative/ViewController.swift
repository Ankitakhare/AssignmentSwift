//
//  ViewController.swift
//  WebviewCommunicationWithNative
//
//  Created by ankita on 11/29/21.
//  Copyright © 2021 ankita. All rights reserved.
//

import UIKit
import WebKit

class ViewController: UIViewController {
    
    @IBOutlet weak var webResponseLabel: UILabel!
    @IBOutlet weak var textField: UITextField!
    
    lazy var webView: WKWebView = {
        let webConfig: WKWebViewConfiguration = WKWebViewConfiguration()
        
        // Setup WKUserContentController instance for injecting user script
        var userController: WKUserContentController = WKUserContentController()
        
        /*
        - Add a script message handler for receiving
        - "buttonClicked" event notifications posted from the JS document using
        - window.webkit.messageHandlers.buttonClicked.postMessage script message
         */
        userController.add(self, name: "nativeProcess")
        
        // Configure the WKWebViewConfiguration instance with the WKUserContentController
        webConfig.userContentController = userController
        
        return WKWebView(frame: CGRect(x: 0, y: 200, width: self.view.frame.width, height: self.view.frame.height - 200), configuration: webConfig)
    }()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.view.addSubview(webView)
        loadHTMLFile()
    }
    
    func loadHTMLFile() {
        if let path = Bundle.main.path(forResource: "index", ofType: "html") {
            let url = URL(fileURLWithPath: path)
            let request = URLRequest(url: url)
            webView.load(request)
        }
    }
    
    @IBAction func sendDataToWeb(_ sender: UIButton) {
        if let message = textField.text {
            let toJSCode = "receiveDataFromSwift(\"\(message)\")"
            webView.evaluateJavaScript(toJSCode) {[weak self] (resp, error) in
                self?.textField.text = ""
            }
        }
    }


}

extension ViewController: WKScriptMessageHandler {
    
    func userContentController(_ userContentController: WKUserContentController, didReceive message: WKScriptMessage) {
        print("User message from Java script")
        /*
           - WKScriptMessage message format can be
           - simple string  or
           - key value pairs ([String: Any])
         */
        if (message.body is String) {
            self.webResponseLabel.text = message.body as? String
        }
    }
    
}

