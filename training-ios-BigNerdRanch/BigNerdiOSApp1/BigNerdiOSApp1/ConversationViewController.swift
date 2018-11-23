//
//  ConversationViewController.swift
//  BigNerdiOSApp1
//
//  Created by Shaobo Sun on 2/3/16.
//  Copyright © 2016 Shaobo Sun. All rights reserved.
//



import UIKit

class ConversationViewController : UIViewController, UITextFieldDelegate {
    
    
    @IBOutlet var celsiusLabel: UILabel!
    @IBOutlet var textField: UITextField!
    
    let numberFormatter: NSNumberFormatter = {
        let nf = NSNumberFormatter()
        nf.numberStyle = .DecimalStyle
        nf.minimumFractionDigits = 0
        nf.maximumFractionDigits = 1
        return nf
    }()
    
    
    var celsiusValue: Double? {
            if let value = fahrenheitValue {
            return (value - 32) * (5/9)
        }
            else {
            return nil }
    }
    
    @IBAction func fahrenheitFieldEditingChanged(textField: UITextField) {
        print("this changed too")
        if let text = textField.text, number = numberFormatter.numberFromString(text) {
            fahrenheitValue = number.doubleValue
        } else {
            fahrenheitValue = nil
        }
    }
    
    var fahrenheitValue: Double? {
        didSet {
            updateCelsiusLabel()
        }
    }
    
    
    func updateCelsiusLabel() {
        if let value = celsiusValue {
            celsiusLabel.text = numberFormatter.stringFromNumber(value)
        } else {
            celsiusLabel.text = "???"
        }
    }
    
    @IBAction func dismissKeyboard(sender: AnyObject) {
        let currentLocale = NSLocale.currentLocale()
        let isMetric = currentLocale.objectForKey(NSLocaleUsesMetricSystem)?.boolValue
        let currencySymbol = currentLocale.objectForKey(NSLocaleCurrencyCode)
        print(currencySymbol)
        textField.resignFirstResponder()
    }
    
    func textField(textField: UITextField, shouldChangeCharactersInRange range: NSRange, replacementString string: String) -> Bool {
        print("Current text: \(textField.text)")
        print("Replacement text: \(string)")
            
        let currentLocale = NSLocale.currentLocale()
        let decimalSeparator = currentLocale.objectForKey(NSLocaleDecimalSeparator) as! String
            
        let existingTextHasDecimalSeperator = textField.text?.rangeOfString(decimalSeparator)
            
        let replacementTextHasDecimalSeparator = string.rangeOfString(decimalSeparator)
            
        if existingTextHasDecimalSeperator != nil && replacementTextHasDecimalSeparator != nil {
            return false
        } else {
            return true
        
        }
    }

}