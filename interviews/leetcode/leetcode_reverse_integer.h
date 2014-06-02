//
//  leetcode_reverse_integer.h
//  Hacker
//
//  Created by Shaobo Sun on 9/14/13.
//  Copyright (c) 2013 Shaobo. All rights reserved.
//

#ifndef Hacker_leetcode_reverse_integer_h
#define Hacker_leetcode_reverse_integer_h

int reverse(int x) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int new_int = 0;
    
    while(x!=0){
        int remainder = x%10;
        new_int = new_int*10 + remainder;
        x = x/10;
    }
    
    return new_int;
}


#endif
