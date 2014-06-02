//
//  leetcode_palindrome_number.h
//  Hacker
//
//  Created by Shaobo Sun on 9/25/13.
//  Copyright (c) 2013 Shaobo. All rights reserved.
//

#ifndef Hacker_leetcode_palindrome_number_h
#define Hacker_leetcode_palindrome_number_h

bool isPalindrome(int x) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if(x<0)
        return false;
    
    if(x<10 && x>-10)
        return true;
    
    int not_x = x;
    int digit = 0;
    while(not_x != 0){
        not_x = not_x /10;
        digit++;
    }
    
    not_x = x;
    // 37273
    while(not_x >= 10 || not_x <= -10){
        int multiplier = 1;
        for(int i = 0; i<digit-1; i++){
            multiplier *= 10;
        }
        if( not_x /multiplier  != not_x % 10){
            return false;
        }
        
        not_x = not_x % multiplier;
        
        not_x = not_x / 10;
        
        digit = digit -2;
    }
    
    return true;
    
}

#endif
