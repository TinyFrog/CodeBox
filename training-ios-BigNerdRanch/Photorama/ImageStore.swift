//
//  ImageStore.swift
//  Homepwner
//
//  Created by Shaobo Sun on 2/5/16.
//  Copyright © 2016 Shaobo Sun. All rights reserved.
//

import UIKit

class ImageStore {
    
    
    let cache = NSCache()
    
    func setImage(image: UIImage, forKey key: String) {
        cache.setObject(image, forKey: key)
    }
    func imageForKey(key: String) -> UIImage? {
        return cache.objectForKey(key) as? UIImage
    }
    func deleteImageForKey(key: String) {
        cache.removeObjectForKey(key)
    }
}
