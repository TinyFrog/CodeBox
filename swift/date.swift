//
//  date.swift
//  swift-snippets
//
//  Created by Shaobo Sun on 2/28/15.
//
//

extension NSDate
{
    convenience
    init(dateString:String) {
        let dateStringFormatter = NSDateFormatter()
        dateStringFormatter.dateFormat = "yyyy-MM-dd"
        dateStringFormatter.locale = NSLocale(localeIdentifier: "en_US_POSIX")
        let d = dateStringFormatter.dateFromString(dateString)
        self.init(timeInterval:0, sinceDate:d!)
    }
}

DatePicker.maximumDate = NSDate(dateString: "2015-02-14")
