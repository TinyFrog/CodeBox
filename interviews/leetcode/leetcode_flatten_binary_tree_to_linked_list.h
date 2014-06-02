//
//  leetcode_flatten_binary_tree_to_linked_list.h
//  Hacker
//
//  Created by Shaobo Sun on 9/15/13.
//  Copyright (c) 2013 Shaobo. All rights reserved.
//

#ifndef Hacker_leetcode_flatten_binary_tree_to_linked_list_h
#define Hacker_leetcode_flatten_binary_tree_to_linked_list_h

/*
 
 Given a binary tree, flatten it to a linked list in-place.
 
 For example,
 Given
 
   1
  / \
  2   5
 / \   \
 3   4   6
 
 The flattened tree should look like:
 1
  \
   2
    \
     3
      \
       4
        \
         5
          \
           6
 
 */


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    TreeNode* flatten_core(TreeNode* node){
        if(node->left == NULL && node->right == NULL)
            return node;
        
        TreeNode* last_node = NULL;
        TreeNode* child_node = NULL;
        TreeNode* temp = NULL;
        if(node->left)
            child_node = flatten_core(node->left);
        else{ // node->right is there
            flatten_core(node->right);
            return node;
        }
        
        // take left node off
        node->left = NULL;
        temp = node->right;
        
        // get to the bottom-right node, then append 
        last_node = child_node;
        while(last_node->right != NULL){
            last_node = last_node->right;
        }
        
        node->right = child_node;
        
        if(temp != NULL){
            last_node->right = temp;
            flatten_core(last_node->right);
        }
        
        return node;
        
    }
    
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return;
        flatten_core(root);
    }
    
    
};




#endif
