//
//  leetcode_unique_binary_search_trees.h
//  Hacker
//
//  Created by Shaobo Sun on 9/25/13.
//  Copyright (c) 2013 Shaobo. All rights reserved.
//

#ifndef Hacker_leetcode_unique_binary_search_trees_h
#define Hacker_leetcode_unique_binary_search_trees_h

int numTrees(int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if(n==0)
        return 0;
    
    return numTrees_core(0,n-1);
}

int numTrees_core(int i, int j){
    if(i>j)
        return 1;
    
    if(i == j)
        return 1;
    
    int num = 0;
    // [0,1]
    for(int p =i; p<=j ;p++){
        
        num += numTrees_core(i,p-1) * numTrees_core(p+1,j);
        
    }
    return num;
}


#endif
