//
//  leetcode_interleaving_string.h
//  Hacker
//
//  Created by Shaobo Sun on 9/29/13.
//  Copyright (c) 2013 Shaobo. All rights reserved.
//

#ifndef Hacker_leetcode_interleaving_string_h
#define Hacker_leetcode_interleaving_string_h

    bool isInterleave_core(string s1, string s2, string s3, int i, int j, int p, int** results){
        if(p<0)
            return true;
        
        bool b1 = false;
        bool b2 = false;
        
        if(i>=0&& j>=0){
        if(results[i][j] != 0){
            if(results[i][j] == 1)
                return true;
            if(results[i][j] == -1)
                return false;
        }
        }
        
        if(i>=0 && s3[p] == s1[i]){
            b1 = isInterleave_core(s1,s2,s3,i-1,j,p-1, results);
        }
        
        if( j>= 0 && s3[p] == s2[j]){
            b2 = isInterleave_core(s1,s2,s3,i,j-1,p-1, results);
        }
        
        if(i>=0&& j>=0){
        if(results[i][j] == 0){
            results[i][j] = ( b1 || b2 ? 1:-1 );
        }
        }
        
        return b1 || b2;
        
    }

bool isInterleave(string s1, string s2, string s3) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    
    if(s3.size() == 0)
        return false;
    
    if(s1.size() + s2.size() != s3.size()){
        return false;
    }
    if(s1.size() == 0)
        return (s2 == s3);
    
    if(s2.size() == 0)
        return s1 == s3;
    
    int i = s1.size();
    int j = s2.size();
    int p = s3.size();
    
    int** results = new int*[i];
    for(int k = 0; k<i; k++){
        results[k] = new int[j];
        for(int what = 0; what<j; what++){
            results[k][what] = 0;
        }
    }
    
    return isInterleave_core(s1,s2,s3,i-1,j-1,p-1,results);
    
}



#endif
