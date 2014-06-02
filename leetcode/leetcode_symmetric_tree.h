//
//  leetcode_symmetric_tree.h
//  Hacker
//
//  Created by Shaobo Sun on 9/16/13.
//  Copyright (c) 2013 Shaobo. All rights reserved.
//

#ifndef Hacker_leetcode_symmetric_tree_h
#define Hacker_leetcode_symmetric_tree_h

bool isSymmetric(TreeNode *root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if(root == NULL)
        return true;
    
    return isSymmetric_recursive(root->left, root->right);
    
    
}

bool isSymmetric_recursive(TreeNode* left_node,TreeNode* right_node){
    if(left_node == NULL && right_node == NULL)
        return true;
    
    if(left_node != NULL && right_node != NULL){
        if(left_node->val == right_node->val)
            return isSymmetric_recursive(left_node->right, right_node->left) && isSymmetric_recursive(left_node->left, right_node->right);
        
    }
    
    return false;
}

#endif
