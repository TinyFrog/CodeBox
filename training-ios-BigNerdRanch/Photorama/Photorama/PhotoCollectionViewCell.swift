//
//  PhotoCollectionViewCell.swift
//  Photorama
//
//  Created by Shaobo Sun on 2/8/16.
//  Copyright © 2016 Shaobo Sun. All rights reserved.
//

import UIKit
class PhotoCollectionViewCell: UICollectionViewCell {
    @IBOutlet var imageView: UIImageView!
    @IBOutlet var spinner: UIActivityIndicatorView!
    
    
    func updateWithImage(image: UIImage?) {
        if let imageToDisplay = image {
        spinner.stopAnimating()
        imageView.image = imageToDisplay
    }
        else {
        spinner.startAnimating()
        imageView.image = nil
        }
    }
    
    
    override func awakeFromNib() {
        super.awakeFromNib()
        updateWithImage(nil)
    }
    override func prepareForReuse() {
        super.prepareForReuse()
        updateWithImage(nil)
    }
}