//
//  leetcode_restore_ip_addresses.h
//  Hacker
//
//  Created by Shaobo Sun on 10/13/13.
//  Copyright (c) 2013 Shaobo. All rights reserved.
//

#ifndef Hacker_leetcode_restore_ip_addresses_h
#define Hacker_leetcode_restore_ip_addresses_h

bool isValidIp(string s){
    
    if(s.size()>1 && s[0] == '0'){
        return false;
    }
    
    int i = atoi(s.c_str());
    if( i>=0 && i<=255){
        return true;
    }else{
        return false;
    }
}

void IpAddresses_core(string s, vector<string>& v, string concat_result, int count){
    
    if(count < 3){
        for(int i =1; i<=3;i++){
            // avoid too aggressive
            // input could be 21212121 and we might take i==3 for first three addresses
            if(i>s.size()-1){
                break;
            }
            
            string sub = s.substr(0,i);
            
            string concat_result_temp = concat_result;
            
            if(isValidIp(sub)){
                concat_result_temp = concat_result_temp+sub+".";
                string rest = s.substr(i, s.size()-i);
                int temp_count = count+1;
                IpAddresses_core(rest, v, concat_result_temp, temp_count);
            }
            
        }
    }else if(count == 3){
        // all-in the rest of the string
        if(isValidIp(s)){
            concat_result = concat_result + s;
            v.push_back(concat_result);
            
        }
        // else ignore it
    }
    
    
    
}
vector<string> restoreIpAddresses(string s) {
    // Note: The Solution object is instantiated only once and is reused by each test case.
    vector<string> v;
    if(s.size() == 0){
        return v;
    }
    
    
    string concat_result = "";
    IpAddresses_core(s,v,concat_result,0);
    
    return v;
}

#endif
