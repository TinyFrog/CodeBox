//
//  leetcode_maximum_subarray.h
//  Hacker
//
//  Created by Shaobo Sun on 9/24/13.
//  Copyright (c) 2013 Shaobo. All rights reserved.
//

#ifndef Hacker_leetcode_maximum_subarray_h
#define Hacker_leetcode_maximum_subarray_h

int maxSubArray(int A[], int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if(n==1)
        return A[0];
    
    int current_max = -1000;
    int max = -1000;
    
    for(int i =0; i<n; i++){
        
        if(current_max<A[i] && current_max < 0){
            current_max = A[i];
        }else if(0 < current_max + A[i] )
            current_max = current_max + A[i];
        else
            current_max = -1000;
        
        if(current_max > max){
            max = current_max;
        }
        
    }
    
    return max;
}


#endif
