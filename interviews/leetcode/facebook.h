//
//  facebook.h
//  Hacker
//
//  Created by Shaobo Sun on 10/8/13.
//  Copyright (c) 2013 Shaobo. All rights reserved.
//

#ifndef Hacker_facebook_h
#define Hacker_facebook_h



bool is_mid_of_gravity(string a, string b){
    
    string a_forward = a;
    string b_forward = b;
    
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    string comb_1 = a_forward + b_forward;
    string comb_2 = a_forward + b;
    string comb_3 = a + b;
    string comb_4 = a_forward + a;

    if()
    
    

}

void two_staffs(string input){
    
    int max_length_of_staff = input.size()/2;
    
    int start_of_index_a = -1;
    int start_of_index_b = -1;
    int ret_length_of_staff = -1;

        
    for(int current_length = max_length_of_staff; current_length>0; current_length--){
        
        for(int i = 0; i<input.size(); i++){
            
            for(int j = i + max_length_of_staff; j+max_length_of_staff < input.size(); j++){
                string a = input.substr(i,current_length);
                string b = input.substr(j,current_length);
                
                sort(a.begin(), a.end());
                sort(b.begin(), b.end());
                if(a == b){
                    if(is_mid_of_gravity(a,b)){
                        // good to go
                        if(current_length > ret_length_of_staff){
                            start_of_index_a = i;
                            start_of_index_b = j;
                            ret_length_of_staff = current_length;
                        }
                    }
                }
            }
        }
        
    }
    
    
    
    cout<<start_of_index_a<<" "<<start_of_index_b<<" "<<ret_length_of_staff<<endl;
    
    
}

#endif
