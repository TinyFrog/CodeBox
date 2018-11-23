//
//  ItemStore.swift
//  Homepwner
//
//  Created by Shaobo Sun on 2/4/16.
//  Copyright © 2016 Shaobo Sun. All rights reserved.
//

import UIKit
class ItemStore {
    var allItems = [Item]()
    
    
    let itemArchiveURL: NSURL = {
        let documentsDirectories =
        NSFileManager.defaultManager().URLsForDirectory(.DocumentDirectory,
        inDomains: .UserDomainMask)
        let documentDirectory = documentsDirectories.first!
        return documentDirectory.URLByAppendingPathComponent("items.archive")
    }()
    
    func createItem() -> Item {
        let newItem = Item(random: true)
        allItems.append(newItem)
        return newItem
    }
    
    func removeItem(item: Item) {
        if let index = allItems.indexOf(item) {
            allItems.removeAtIndex(index)
        }
    }
    
    init() {
        for _ in 0..<0 {
            createItem()
        }
    }
    
    func saveChanges() -> Bool {
        print("Saving items to: \(itemArchiveURL.path!)")
        return NSKeyedArchiver.archiveRootObject(allItems, toFile: itemArchiveURL.path!)
    }
    
    
    func moveItemAtIndex(fromIndex: Int, toIndex: Int) {
        if fromIndex == toIndex {
        
            // Get reference to object being moved so you can reinsert it
            let movedItem = allItems[fromIndex]
            // Remove item from array
            allItems.removeAtIndex(fromIndex)
            // Insert item in array at new location
            allItems.insert(movedItem, atIndex: toIndex)
        }
    }


}