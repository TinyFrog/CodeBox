//
//  leetcode_remove_duplicates_from_sorted_array.h
//  Hacker
//
//  Created by Shaobo Sun on 9/15/13.
//  Copyright (c) 2013 Shaobo. All rights reserved.
//

#ifndef Hacker_leetcode_remove_duplicates_from_sorted_array_h
#define Hacker_leetcode_remove_duplicates_from_sorted_array_h
/*
Remove Duplicates from Sorted Array
 */

int removeDuplicates(int A[], int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if(n == 1)
        return n;
    
    int walker = 1;
    for(int i =1; i<n; i++){
        bool dup = false;
        for(int j = 0; j<i;j++){
            if(A[i] == A[j]){
                dup = true;
            }
        }
        
        if(!dup){
            A[walker++] = A[i];
        }
    }
    
    if(n != 0)
        return walker;
}

#endif
