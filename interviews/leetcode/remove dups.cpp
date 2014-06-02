//
//  remove dups.c
//  Hacker
//
//  Created by Shaobo Sun on 8/6/13.
//  Copyright (c) 2013 Shaobo. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int three_sum(){
    signed int integers[] = {3,4,1,2,4,5,6,7,3,2,3,4,-2,3,4,-5,-7,-8};
    signed int target = 7;
    int length = sizeof(integers)/sizeof(int);
    
    signed int two_sum[153];
    int two_sum_index=0;
    cout<<"YES"<<length<<endl;
    for(int i =0; i<length; i++){
        for(int j= 0;j<length && j != i; j++){
            two_sum[two_sum_index++] = integers[i] + integers[j];
        }
        
    }
    
    signed int winner = -9999;
    for(int i =0; i<length; i++){
        
    }
    return -1;
}

/*
int main(){
    three_sum();
    cout<<"NOO"<<endl;
    
}*/


