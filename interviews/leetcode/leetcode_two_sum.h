//
//  leetcode_two_sum.h
//  Hacker
//
//  Created by Shaobo Sun on 9/26/13.
//  Copyright (c) 2013 Shaobo. All rights reserved.
//

#ifndef Hacker_leetcode_two_sum_h
#define Hacker_leetcode_two_sum_h

vector<int> twoSum(vector<int> &numbers, int target) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    map<int, int> mymap;
    
    vector<int> numbers_copy(numbers);
    for(int i =0; i<numbers_copy.size(); i++){
        numbers_copy[i] = target - numbers_copy[i];
        mymap.insert(pair<int,int>(numbers_copy[i], i));
    }
    
    vector<int> ret;
    for(int i =0; i<numbers.size(); i++) {
        if(mymap.find(numbers[i]) == mymap.end()) {
            
            if(mymap.find(i)->second > i){
                ret.push_back(i);
                ret.push_back(mymap.find(i)->second);
                
            }else{
                ret.push_back(i);
                ret.push_back(mymap.find(i)->second);
            }
            break;
        }
    }
    
    return ret;
}


#endif
