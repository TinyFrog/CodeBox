//
//  1_1.h
//  Hacker
//
//  Created by Shaobo Sun on 9/7/13.
//  Copyright (c) 2013 Shaobo. All rights reserved.
//

#ifndef __Hacker____1__
#define __Hacker____1__

#include <iostream>

#include <string>

using namespace std;


void myswap(char& a, char& b){
    char temp;
    temp = a;
    a = b;
    b = temp;
}

void quick_sort_string(string& str, int l, int r){
    if(l>=r) return;
    
    int sentinel = str[r];
    int p = l;
    int q = r-1;
    
    while(p<q){
        while(str[p]<sentinel)
            p++;
        while(str[q]>sentinel && q>=0)
            q--;
        if(p<q)
            myswap(str[p], str[q]);
        else
            break;
    }
    
    myswap(str[p], str[r]);
    cout<<str<<endl;
    quick_sort_string(str, l,p-1);
    quick_sort_string(str,p+1, r);
    
}


//if we assume the characters are only from a-z
bool are_characters_unique(string str){
     long length = str.size();
    int bit_map = 0;
    for(int i = 0; i<length; i++){
        int ascii_value = str[i] - 'a';
        if(( 1 << ascii_value ) & bit_map) return false;
        bit_map = bit_map | ( 1>> ascii_value );
    }
    
    return true;

    
}

#endif /* defined(__Hacker____1__) */
