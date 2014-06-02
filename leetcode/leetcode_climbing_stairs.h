//
//  leetcode_climbing_stairs.h
//  Hacker
//
//  Created by Shaobo Sun on 9/24/13.
//  Copyright (c) 2013 Shaobo. All rights reserved.
//

#ifndef Hacker_leetcode_climbing_stairs_h
#define Hacker_leetcode_climbing_stairs_h

int climbStairs(int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    
    if(n==1)
        return 1;
    int* A = new int[n+1];
    
    for(int i =0; i<n+1; i++){
        A[i] = 0;
    }
    
    for(int i =1; i<n+1; i++){
        A[i] = climbStairs_core(i,A);
    }
    
    return A[n];
}

int climbStairs_core(int i, int A[]){
    
    if(A[i] != 0){
        return A[i];
    }
    
    if(i==1)
        return 1;
    if(i ==2)
        return 2;
    return climbStairs_core(i-1, A) + climbStairs_core(i-2, A);
}

#endif
