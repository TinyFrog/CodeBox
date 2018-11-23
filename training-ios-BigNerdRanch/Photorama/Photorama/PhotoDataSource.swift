//
//  PhotoDataSource.swift
//  Photorama
//
//  Created by Shaobo Sun on 2/8/16.
//  Copyright © 2016 Shaobo Sun. All rights reserved.
//

import UIKit


// To conform to the UICollectionViewDataSource protocol, a type also needs to conform to the NSObjectProtocol. The easiest and most common way to conform to this protocol is to subclass from NSObject, as you did above.
class PhotoDataSource: NSObject, UICollectionViewDataSource {
    var photos = [Photo]()
    
    func collectionView(collectionView: UICollectionView,
        numberOfItemsInSection section: Int) -> Int {
        return photos.count
    }
    func collectionView(collectionView: UICollectionView,
        cellForItemAtIndexPath indexPath: NSIndexPath) -> UICollectionViewCell {
        let identifier = "UICollectionViewCell"
        let cell =
        collectionView.dequeueReusableCellWithReuseIdentifier(identifier,
        forIndexPath: indexPath) as! PhotoCollectionViewCell
        
        let photo = photos[indexPath.row]
        cell.updateWithImage(photo.image)
        return cell
    }
}
