//
//  ViewController.swift
//  BigNerdiOSApp1
//
//  Created by Shaobo Sun on 2/3/16.
//  Copyright © 2016 Shaobo Sun. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    @IBOutlet var currentQuestionLabelCenterXConstraint: NSLayoutConstraint!

    @IBOutlet var questionLabelCenterXConstraint: NSLayoutConstraint!
    @IBOutlet var currentQuestionLabel: UILabel!
    
    
    func updateOffScreenLabel() {
        let screenWidth = view.frame.width
        nextQuestionLabelCenterXConstraint.constant = -screenWidth
    }
    
    func animateLabelTransitions() {
        UIView.animateWithDuration(1.5,
            delay: 0,
            options: [],
            animations: {
                self.currentQuestionLabel.alpha = 0
                self.questionLabel.alpha = 1
        }, completion: {
            _ in
            swap(&self.questionLabel, &self.currentQuestionLabel)
        })
    }
    
    override func viewWillAppear(animated: Bool) {
        super.viewWillAppear(animated)
        questionLabel.alpha = 0
        answerLabel.alpha = 0
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
//        questionLabel.text = questions[currentQuestionIndex]
        currentQuestionLabel.text = questions[currentQuestionIndex]
        questionLabel.alpha = 0
        updateOffScreenLabel()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @IBOutlet var questionLabel: UILabel!
    @IBOutlet var answerLabel: UILabel!

    
    @IBAction func showNextQuestion(sender: AnyObject) {

        ++currentQuestionIndex
        if currentQuestionIndex == questions.count {
    currentQuestionIndex = 0
        }
        let question: String = questions[currentQuestionIndex]
        questionLabel.text = question
        answerLabel.text = "???"
        animateLabelTransitions()
    }
    
    
    @IBAction func showAnswer(sender: AnyObject) {
        let answer: String = answers[currentQuestionIndex]
        answerLabel.text = answer
    }
    
    let questions: [String] = ["From what is cognac made?",
        "What is 7+7?",
        "What is the capital of Vermont?"]
    let answers: [String] = ["Grapes",
        "14",
        "Montpelier"]
    var currentQuestionIndex: Int = 0

}

