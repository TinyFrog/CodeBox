//
//  leetcode_surrounded_regions.h
//  Hacker
//
//  Created by Shaobo Sun on 9/16/13.
//  Copyright (c) 2013 Shaobo. All rights reserved.
//

#ifndef Hacker_leetcode_surrounded_regions_h
#define Hacker_leetcode_surrounded_regions_h

void solve(vector<vector<char>> &board) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    
    const int width = board.size();
    if(width == 0)
        return;
    const int length = board[0].size();
    
    bool visited[width][length];
    for(int i =0; i<width; i++){
        for(int j = 0; j<length; j++){
            
            
            if(surrounded(board, visited, i, j)){
                
                
            }
            visited[i][j] = true;
        }
    }
    
    
}

bool surrounded(vector<vector<char>> &board, bool visited[][], int i, int j, int width, int length){
    
    if(i == 0 || i == width -1 || j == 0 || j==length-1)
        return false;
    
    surrounded(board, bool visited[][], int i, int j, int width, int length){
        if(!visited[i][j] ){
            visited[i][j] = true
        }
    }
}


#endif
