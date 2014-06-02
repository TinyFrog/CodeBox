//
//  leetcode_rotate_list.h
//  Hacker
//
//  Created by Shaobo Sun on 9/28/13.
//  Copyright (c) 2013 Shaobo. All rights reserved.
//

#ifndef Hacker_leetcode_rotate_list_h
#define Hacker_leetcode_rotate_list_h

ListNode *rotateRight(ListNode *head, int k) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    
    if(head == NULL)
        return head;
    if(k == 0)
        return head;
    
    int length = 0;
    ListNode* node = head;
    ListNode* last_node;
    while(node != NULL){
        last_node = node;
        length = length +1;
        node = node->next;
    }
    
    while( length < k){
        k = k - length;
    }
    
    node = head;
    ListNode* temp_head = head;
    while(length > 0){
        if( length == k+1){
            head = node->next;
            last_node->next = temp_head;
            node->next = NULL;
            break;
        }
        node = node->next;
        length--;
    }
    
    return head;
    
}


#endif
