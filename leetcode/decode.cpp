//
//  decode.cpp
//  Hacker
//
//  Created by Shaobo Sun on 9/2/13.
//  Copyright (c) 2013 Shaobo. All rights reserved.
//

/*

 A message containing letters from A-Z is being encoded to numbers using the following mapping:
 
 'A' -> 1
 'B' -> 2
 ...
 'Z' -> 26
 Given an encoded message containing digits, determine the total number of ways to decode it.
 
 For example,
 Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
 
 The number of ways decoding "12" is 2.


*/

#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool isAmbiguous(string str){

    unsigned long length = str.size();
    if(length > 2 || length < 1){
        return false;
    }

    if (str[0] == '1'){
        return true;
    }else if( str[0] == '2'){
        char candidates[7] = {'0','1','2','3','4','5','6'};
        for(int i = 0; i< 7; i++){
            if(str[1] == candidates[i]);
                return true;
            
        }
        
    }
    
    return false;
}

int dp_ways(string str){
    int ways = 1;
    int length = str.size();
    if(length == 0){
        return 0;
    }
    if(length == 1){
        return 0;
    }
    if(length == 2 ){
        return 1;
    }
    for(int i = 0; i< length-1; i++){
        //cout<<"length is "<<length<<endl;
        //cout<<i<<endl;
        //cout<<length-(i+2)<<endl;
        if(i+2>length-1){
            ways += dp_ways(str.substr(0,i)) + dp_ways(str.substr(i,2));
        }else{
            ways += dp_ways(str.substr(0,i)) + dp_ways(str.substr(i,2)) + dp_ways(str.substr(i+2, length-(i+2)));
        }
    }
    return ways;
    
}


int waysToDecode(string str){

    unsigned long length = str.size();
    vector<int> indep_count;
    
    if(length == 0)
        return 0;
    
    if(length == 1)
        return 1;
    
    if(length == 2)
        return 2;
    
    int cont = 0;
    
    for (int i = 0; i<length -1 ; i++){
        
        string substr = str.substr(i,2);
        if(isAmbiguous(substr)){
            cout<<"YES "<<substr<<" Ambi!"<<endl;
            cont += 1;
        }else{
            if(cont > 0){
                string cont_str = str.substr(i-cont,2+(cont-1));
                cout<<"Going to pass "<<cont_str<<endl;
                indep_count.push_back(dp_ways(cont_str));
                cont = 0;
            }
        }
    }
    
    if(cont > 0){
        string cont_str = str.substr(length-cont-1 ,2+(cont-1));
        cout<<"Going to pass "<<cont_str<<endl;
        cout<<dp_ways(cont_str)<<endl;
        indep_count.push_back(dp_ways(cont_str));
    }
    
    int ways = 1;
    vector<int>::iterator iter;
    for(iter = indep_count.begin(); iter != indep_count.end(); iter++){
        cout<<"YEA"<<(*iter)<<endl;
        ways *= (*iter);
    }
    
    cout<<"The output is: "<<ways<<endl;
    
    return ways;
}


/*
int main(){
        
    cout<<waysToDecode("1212")<<endl;
    
}*/