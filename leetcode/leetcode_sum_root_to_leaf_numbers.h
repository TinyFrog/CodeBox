//
//  leetcode_sum_root_to_leaf_nodes.h
//  Hacker
//
//  Created by Shaobo Sun on 9/14/13.
//  Copyright (c) 2013 Shaobo. All rights reserved.
//

#ifndef Hacker_leetcode_sum_root_to_leaf_nodes_h
#define Hacker_leetcode_sum_root_to_leaf_nodes_h

#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    
    int sumNumbers_core(TreeNode* node, int current_value, vector<int>& leafNum){
        int path_value = current_value + node->val;
        
        if( node->left )
            sumNumbers_core(node->left, path_value*10 ,leafNum);
        if( node->right )
            sumNumbers_core(node->right,path_value*10, leafNum);
        
        if(node->left == NULL && node->right == NULL){
            leafNum.push_back(path_value);
        }
    }
    
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(root == NULL)
            return 0;
        
        if(root->left == NULL && root->right == NULL)
            return root->val;
        
        vector<int> leafNum;
        
        int current_value = 0;
        sumNumbers_core(root, current_value, leafNum);
        
        
        vector<int>::iterator iter;
        int sum = 0;
        for(iter = leafNum.begin(); iter != leafNum.end(); ++iter){
            sum += *iter;
        }
        
        return sum;
        
    }
    
};

#endif
