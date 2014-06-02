//
//  util.h
//  Hacker
//
//  Created by Shaobo Sun on 9/8/13.
//  Copyright (c) 2013 Shaobo. All rights reserved.
//

#ifndef Hacker_util_h
#define Hacker_util_h

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void readfile(string filename){
    ifstream myfile(filename);
    string line = "";
    cout<<"Opening "<<filename<<endl;
    if(myfile.is_open()){
        
        while(myfile.good()){
            getline(myfile, line);
            cout<<line<<endl;
        }
        
    }else{
        cout<<"What the fuck is this file?"<<endl;
    }
    
    myfile.close();
    
}

template < class T >
void myswap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

int binary_search(int a[], int array_length, int target){
    int i,j,mid;
    i =0;
    j = array_length-1;

    while(i<=j){ // i == j is needed
        mid = (i+j)/2;
        if(a[mid] == target){
            return mid;
        }
        else if(a[mid]<target){
            i = mid+1;
        }else{
            j = mid-1;
        }
    }
    
    return -1;
    
}








#endif
