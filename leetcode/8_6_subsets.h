//
//  subsets.cpp
//  Hacker
//
//  Created by Shaobo Sun on 9/2/13.
//  Copyright (c) 2013 Shaobo. All rights reserved.
//


#include <iostream>
#include <vector>

using namespace std;

bool vector_contain(vector<int>* vec, int i){
    
    vector<int>::iterator iter;
    //cout<<vec->size()<<endl;
    for(iter = vec->begin(); iter != vec->end(); iter++){
        
        //cout<<vec->size()<<endl;
        if ((*iter) == i){
            return true;
        }
    }
    
    return false;
    
}


void print_subsets(){
    
    vector<vector<int>*> vec;
    
    int a[] = {1,2,3,4,5,8};
    
    int array_length = sizeof(a)/sizeof(int);
    
    for(int i = 0; i<array_length; i++){
        vector<int>* temp_vec = new vector<int>();
        temp_vec->push_back(a[i]);
        vec.push_back(temp_vec);
    }
    
    for(int i =0; i<vec.size(); ++i){
        cout<<vec.size()<<endl;
        for(int j = 0; j<array_length; j++){
            if(!vector_contain(vec[i], a[j])){
                vector<int>* temp_vec = new vector<int>(*(vec[i]));
                temp_vec->push_back(a[j]);
                vec.push_back(temp_vec);
                
            }
        }
    }
    
    vector<vector<int>*>::iterator iter;
    for(iter = vec.begin(); iter != vec.end(); iter++){
        vector<int>::iterator inner_iter;
        cout<<"[ ";
        for(inner_iter = (*iter)->begin(); inner_iter != (*iter)->end(); inner_iter++){
            cout<<*inner_iter<<" ";
        }
        cout<<" ],"<<endl;
    }
}

// this is wrong, would produce dup
void print_subusets_recursive_dup(vector<int> a){
    
    vector<int>::iterator iter;
    vector<int>::iterator iter2;

    if(a.size() == 0){
        return;
    }
    
    cout<<"[ ";

    for(iter = a.begin(); iter != a.end(); ++iter){
         cout<<*iter<<" ";
    }
    cout<<" ],"<<endl;

    
    for(iter = a.begin(); iter != a.end(); ++iter){
        vector<int>* temp = new vector<int>();
        for(iter2 = a.begin(); iter2 != a.end(); ++iter2){
            if(iter2 != iter){
                temp->push_back(*iter2);
            }
            
        }
        print_subusets_recursive_dup(*temp);
    }
}



void print_subsets_recursive(vector<int> a, vector<bool> b){
    
    if(a.size() == b.size()){
        cout<<"[ ";

        for(int i = 0; i<a.size();i++){
            if(b[i])
                cout<<a[i]<<" ";
        }
        cout<<" ],"<<endl;
        
        return;
        
    }
    
    bool is_it = false;
    b.push_back(is_it);
    print_subsets_recursive(a,b);
    b.pop_back();
    is_it = true;
    b.push_back(is_it);
    print_subsets_recursive(a,b);
    
}
