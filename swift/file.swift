//
//  file.swift
//  swift-snippets
//
//  Created by Shaobo Sun on 2/28/15.
//
//

func storeImage(id: String, image getImage : UIImage) {
    var paths = NSSearchPathForDirectoriesInDomains(.DocumentDirectory, .UserDomainMask, true)[0] as String
    var dirPath = paths.stringByAppendingPathComponent("images/\(id)" )
    var imagePath = paths.stringByAppendingPathComponent("images/\(id)/logo.jpg" )
    var checkImage = NSFileManager.defaultManager()
    
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_BACKGROUND, 0)) {
        checkImage.createDirectoryAtPath(dirPath, withIntermediateDirectories: true, attributes: nil, error: nil)
        UIImageJPEGRepresentation(getImage, 100).writeToFile(imagePath, atomically: true)
    }
}