//
//  rocketfuel.h
//  Hacker
//
//  Created by Shaobo Sun on 10/7/13.
//  Copyright (c) 2013 Shaobo. All rights reserved.
//

#ifndef Hacker_rocketfuel_h
#define Hacker_rocketfuel_h


#include <deque>


using namespace std;

void iterate_queue(deque<TreeNode*> q){
    deque<TreeNode*>::iterator iter;
    for(iter = q.begin(); iter != q.end(); iter++){
        if((*iter) != NULL){
            
            cout<<(*iter)->val<<" ";
        }else{
            cout<<"# ";
        }
        
    }
    cout<<endl;
    
}

void bfs(TreeNode* root){
    if(root == NULL)
        return;
    deque<TreeNode*> q;
    
    int level = 1;
    q.push_back(root);
    q.push_back(NULL);

    while(!q.empty()){
        if(level % 2 != 0){ // odd level
            TreeNode* current_node = q.front();
            q.pop_front();
            
            if(current_node == NULL){
                if(q.empty()){
                    break;
                }
                q.push_front(NULL);
                level++;
                cout<<endl;
                continue;
            }else {
                cout<<current_node->val<<" ";
            }
            
            if(current_node!=NULL){
            if(current_node->left != NULL){
                q.push_back(current_node->left);
            }
            if(current_node->right != NULL){
                q.push_back(current_node->right);
            }
            }
            

        }else{ // even level
            TreeNode* current_node = q.back();
            q.pop_back();
            
            if(current_node == NULL){
                if(q.empty()){
                    break;
                }
                q.push_back(NULL);
                level++;
                cout<<endl;
                continue;
            }else{
                cout<<current_node->val<<" ";
            }
            
 
            if(current_node!=NULL){

            if(current_node->right != NULL){
                q.push_front(current_node->right);
            }
            
            if(current_node->left != NULL){
                q.push_front(current_node->left);
            }
            }
        }
    }
}


#endif
