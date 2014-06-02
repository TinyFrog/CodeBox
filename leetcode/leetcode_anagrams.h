//
//  leetcode_anagrams.h
//  Hacker
//
//  Created by Shaobo Sun on 9/28/13.
//  Copyright (c) 2013 Shaobo. All rights reserved.
//

#ifndef Hacker_leetcode_anagrams_h
#define Hacker_leetcode_anagrams_h

vector<string> anagrams(vector<string> &strs) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int size = strs.size();
    int** intmap = new int*[26];
    for(int i =0; i<26; i++)
        intmap[i] = new int[size];
    bool first_time = true;
    
    vector<string> ret;
    
    for(int i =0; i<strs.size(); i++){
        for(int j = 0; j < strs[i].size(); i++){
            int k = strs[i][j] - 'a';
            intmap[i][k]++;
        }
        
        for(int k =0; k<i;k++){
            bool anagram = true;
            for(int p = 0; p<26; p++){
                if(intmap[k][p] != intmap[i][p]){
                    anagram = false;
                    break;
                }
            }
            
            if(!anagram)
                continue;
            
            first_time = false;
            if(!first_time){
                ret.push_back(strs[i]);
            }else{
                ret.push_back(strs[k]);
                ret.push_back(strs[i]);
            }
        }
    }
    
    return ret;
}


#endif
