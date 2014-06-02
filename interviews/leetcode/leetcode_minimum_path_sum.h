//
//  leetcode_minimum_path_sum.h
//  Hacker
//
//  Created by Shaobo Sun on 9/29/13.
//  Copyright (c) 2013 Shaobo. All rights reserved.
//

#ifndef Hacker_leetcode_minimum_path_sum_h
#define Hacker_leetcode_minimum_path_sum_h

int minPathSum(vector<vector<int> > &grid) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if(grid.size() == 0){
        return 0;
    }
    
    int rows = grid.size();
    int columns = grid[0].size();
    
    if(rows ==1 && columns ==1)
        return grid[0][0];
    
    int** results = new int*[rows];
    for(int i =0; i< rows; i++){
        results[i] = new int[columns];
        
        for(int j = 0; j<columns; j++){
            results[i][j] = 0;
        }
    }
    
    for(int i =0; i<rows; i++){
        for(int j = 0; j< columns; j++){
            if(i != 0 && j != 0){
                results[i][j] = min(results[i-1][j]+grid[i][j], results[i][j-1]+grid[i][j]);
            }else if(i == 0 && j ==0){ // pay attention to the order here, if j == 0 or i == 0 goes first, they will cover i==0&&j==0 and make it unreachable 
                results[i][j] = grid[i][j];
            }else if(j == 0){
                results[i][j] = results[i-1][j]+grid[i][j];
            }else{
                results[i][j] = results[i][j-1]+grid[i][j];
            }
            
        }
    }
    
    return results[rows-1][columns-1];
}

#endif
