//
//  1_3.h
//  Hacker
//
//  Created by Shaobo Sun on 9/8/13.
//  Copyright (c) 2013 Shaobo. All rights reserved.
//

#ifndef __Hacker____3__
#define __Hacker____3__

#include <iostream>
#include <string>
#include "utils.h"

using namespace std;


// TODO: Make it work
void remove_dup_string(string& str){

    if(str.size() == 0 | str.size() == 1){
        return;
    }
    
    int first_dup_index = 0;
    for(int i = 0; i<str.size(); i++){
        
        bool is_dup = false;
        for(int j = 0; j<i; j++){
            if(str[i] == str[j]){
                is_dup = true;
                break;
            }
            
        }
        
        if(!is_dup){
            if(i != first_dup_index){
                cout<<"swap!"<<endl;
                myswap<char>(str[i], str[first_dup_index++]);
            }
        }
    }
    cout<<first_dup_index<<endl;
    cout<<str<<endl;
    str = str.substr(0, first_dup_index-1);
    
}


void remove_dup_string_test_cases(){
    
    
    
    string a = "aaaa";
    string b = "a";
    string c = "ababab";
    string d = "aa";
    
    cout<<"Test case 1"<<endl;
    remove_dup_string(a);
    cout<<a<<endl;
    cout<<"Test case 2"<<endl;
    remove_dup_string(b);
    cout<<b<<endl;
    cout<<"Test case 3"<<endl;
    remove_dup_string(c);
    cout<<c<<endl;
    
    cout<<"Test case 4"<<endl;
    remove_dup_string(d);
    cout<<d<<endl;
    
}

#endif /* defined(__Hacker____3__) */
