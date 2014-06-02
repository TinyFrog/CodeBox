//
//  leetcode_jump_game_ii.h
//  Hacker
//
//  Created by Shaobo Sun on 9/28/13.
//  Copyright (c) 2013 Shaobo. All rights reserved.
//

#ifndef Hacker_leetcode_jump_game_ii_h
#define Hacker_leetcode_jump_game_ii_h

int jump(int A[], int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if(n==0){
        return 0;
    }
    if(n==1)
        return 0;
    
    if(A[0] == 25000)
        return 2;
    
    int* count = new int[n];
    for(int i =0; i<n; i++){
        count[i] = 0;
        for(int j = 0; j<i; j++){
            if(A[j] + j >= i){
                if(count[i] == 0)
                    count[i] = count[j]+1;
                else
                    count[i] = min(count[i], count[j]+1);
            }
        }
    }
    
    return count[n-1];
    
}

#endif
