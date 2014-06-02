//
//  leetcode_decode_ways.h
//  Hacker
//
//  Created by Shaobo Sun on 10/7/13.
//  Copyright (c) 2013 Shaobo. All rights reserved.
//

#ifndef Hacker_leetcode_decode_ways_h
#define Hacker_leetcode_decode_ways_h






int numDecodings_core(string s, int n, int* results){
    if(n == 0){
        return 0;
    }
    
    if(n == 1){
        if(s[0] == '0')
            return 0;
        else
            return 1;
    }
    
    
    int ret = 0;
    int n_int = s[n-1] - '0';
    int n_1_int = s[n-2] -'0';
    int num = n_1_int*10+n_int;
    // ambiguous
    
    if(n == 2){
        if(n_1_int == 0)
            return 0;
        if( (num >10 && num <20 ) || (num > 20 && num <= 26)){
            return 2;
        }else{
            return 1;
        }
    }
    
    if(results[n] != -1){
        return results[n];
    }
    
    ret = numDecodings_core(s, n-1, results);
    if( (num >10 && num <20 ) || (num > 20 && num <= 26)){
        ret += numDecodings_core(s, n-2, results);
    }
    
    if(num>26 ){
        ret = numDecodings_core(s, n-1, results);
    }
    
    if(num < 10){
        ret = numDecodings_core(s, n-1, results);
    }
    
    // 30
    if(num % 10 == 0){
        if( num == 10 || num == 20)
            ret = numDecodings_core(s, n-2, results);
        else
            return 0;
    }
    
    
    if(results[n] == -1){
        results[n] = ret;
    }
    
    return ret;
}

int numDecodings(string s) {
    // Note: The Solution object is instantiated only once and is reused by each test case.
    
    int size = s.size();
    
    if(size >0){
        if(s[0] == '0')
            return 0;
    }
    int* results = new int[size+1];
    bool consecutive_zero = false;
    
    for(int i=1;i<size;i++){
        if(s[i] == '0'){
            if(s[i-1] != '1' && s[i-1] != '2'){
                return 0;
            }
        }
        consecutive_zero = false;
    }
    for(int i=0;i<size+1;i++){
        results[i] = -1;
    }
    return numDecodings_core(s, size, results);
}

#endif
