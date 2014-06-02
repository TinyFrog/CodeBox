//
//  leetcode_gas_station.h
//  Hacker
//
//  Created by Shaobo Sun on 10/6/13.
//  Copyright (c) 2013 Shaobo. All rights reserved.
//

#ifndef Hacker_leetcode_gas_station_h
#define Hacker_leetcode_gas_station_h

bool circular_loop(int start_index, vector<int> &gas, vector<int> &cost){
    int num_of_stations = gas.size();
    int residue_gas = 0;
    for(int i = start_index; i<num_of_stations; i++){
        
        if(gas[i] + residue_gas - cost[i] >= 0){
            residue_gas += (gas[i] - cost[i]);
        }else{
            return false;
        }
        
    }
    
    for(int i = 0; i<start_index; i++){
        if(gas[i] + residue_gas - cost[i] >= 0){
            residue_gas += (gas[i] - cost[i]);
        }else{
            return false;
        }
    }
    
    return true;
}



int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    // Note: The Solution object is instantiated only once and is reused by each test case.
    if(gas.size() != cost.size()){
        return -1;
    }
    
    for(int i = 0; i<gas.size(); i++){
        if(circular_loop(i, gas,cost)){
            return i;
        }
    }
    
    return -1;
}
#endif
