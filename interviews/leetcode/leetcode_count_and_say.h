//
//  leetcode_count_and_say.h
//  Hacker
//
//  Created by Shaobo Sun on 10/6/13.
//  Copyright (c) 2013 Shaobo. All rights reserved.
//

#ifndef Hacker_leetcode_count_and_say_h
#define Hacker_leetcode_count_and_say_h


string countAndSay(int n) {
    // Note: The Solution object is instantiated only once and is reused by each test case.
    if(n == 1){
        return "1";
    }
    
    queue<int> current;
    queue<int> next;
    
    current.push(1);
    
    for(int i = 0; i<n-1;i++){
        int counter = 1;
        int prev_digit=-1;
        int current_digit = -1;
        while(!current.empty()){
            current_digit = current.front();
            current.pop();
            if(current_digit != prev_digit){
                if(prev_digit != -1){
                    next.push(counter);
                    next.push(prev_digit);
                }
                
                prev_digit = current_digit;
                counter = 1;
            }else{
                counter++;
            }
            
            // last node
            if(current.empty()){
                next.push(counter);
                next.push(current_digit);
            }
        }
        
        current = next;
        while(!next.empty()){
            next.pop();
        }
    }
    
    string ret_string = "";
    
    
    while(!current.empty()){
        int i = current.front();
        current.pop();
        std::string s;
        std::stringstream out;
        out << i;
        s = out.str();
        ret_string += s;
    }
    
    return ret_string;
}

#endif
