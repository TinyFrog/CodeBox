//
//  1_4.h
//  Hacker
//
//  Created by Shaobo Sun on 10/13/13.
//  Copyright (c) 2013 Shaobo. All rights reserved.
//

#ifndef Hacker___4_h
#define Hacker___4_h

#include <map>

bool is_anagram(string s1, string s2){
    map<char, int> count_map;
    for(int i = 0; i< s1.size(); i++){
        if(count_map[s1[i]]){
            count_map[s1[i]] = 1;
        }else{
            count_map[s1[i]]++;
        }
        
    }
    
    for(int i = 0; i< s2.size(); i++){
        if(count_map[s1[i]]){
            count_map[s1[i]]--;
        }else{
            return false;
        }
    }

}



#endif
