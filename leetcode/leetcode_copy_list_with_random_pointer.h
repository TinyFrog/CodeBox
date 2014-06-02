//
//  leetcode_copy_list_with_random_pointer.h
//  Hacker
//
//  Created by Shaobo Sun on 10/20/13.
//  Copyright (c) 2013 Shaobo. All rights reserved.
//

#ifndef Hacker_leetcode_copy_list_with_random_pointer_h
#define Hacker_leetcode_copy_list_with_random_pointer_h

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};


RandomListNode *copyRandomList(RandomListNode *head) {
    // Note: The Solution object is instantiated only once and is reused by each test case.
    
    map<RandomListNode*, RandomListNode*> random_map;
    RandomListNode* iter = head;
    RandomListNode* new_head = NULL;
    RandomListNode* new_prev = NULL;
    while(iter != NULL){
        RandomListNode* new_node = NULL;
        
        if(random_map.find(iter) != random_map.end()){
            new_node = random_map.find(iter)->second;
        }else{
            new_node = new RandomListNode(iter->label);
        }
        
        if(new_prev != NULL){
            new_prev->next = new_node;
        }
        
        if(new_head == NULL){
            new_head = new_node;
        }
        
        if(iter->random == NULL){
            // original random pointer is NULL
            new_node->random = NULL;
        }else{
            if(random_map.find(iter->random) == random_map.end()){
                //
                RandomListNode* new_random_node = new RandomListNode(iter->random->label);
                random_map.insert(pair<RandomListNode*, RandomListNode*>(iter->random, new_random_node));
                new_node->random = new_random_node;
            }else{
                // it has shown before
                new_node->random = random_map.find(iter->random)->second;
                
            }
        }
        
        if(random_map.find(iter) == random_map.end()){
            random_map.insert(pair<RandomListNode*, RandomListNode*>(iter, new_node));
        }
        
        new_prev = new_node;
        iter = iter->next;
    }
    
    return new_head;
}


#endif
