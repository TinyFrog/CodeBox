//
//  button.swift
//  swift-snippets
//
//  Created by Shaobo Sun on 3/1/15.
//
//

// programmatically add action to a button
deleteButton.addTarget(self, action: "pressed:", forControlEvents: UIControlEvents.TouchUpInside)

func pressed(sender: UIButton!) {
    println("I'm so pressed!!!!!")
}