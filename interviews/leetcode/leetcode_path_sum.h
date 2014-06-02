//
//  leetcode_path_sum.h
//  Hacker
//
//  Created by Shaobo Sun on 9/14/13.
//  Copyright (c) 2013 Shaobo. All rights reserved.
//

#ifndef Hacker_leetcode_path_sum_h
#define Hacker_leetcode_path_sum_h


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool hasPathSum_core(TreeNode* node, int sum, int cumulativeSum ){
    
    if(node == NULL)
        return false;
    
    
    cumulativeSum = cumulativeSum + node->val;
    
    if(node->left == NULL && node->right == NULL){
        if(sum == cumulativeSum)
            return true;
        else
            return false;
        
    }
    else{
        return hasPathSum_core(node->left, sum, cumulativeSum) || hasPathSum_core(node->right,sum, cumulativeSum);
    }
    
}

bool hasPathSum(TreeNode *root, int sum) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    
    if(root == NULL)
        return false;
    return hasPathSum_core(root,sum, 0);
    
}



#endif
