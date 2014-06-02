//
//  print_linked_list_with_child.cpp
//  Hacker
//
//  Created by Shaobo Sun on 8/1/13.
//  Copyright (c) 2013 SSB. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Node{
    
public:
    Node(int value){this->value=value;}
    void add_child(Node* node) {this->child = node;}
    void add_next(Node* node) {this->next = node;}
    Node* child;
    Node* next;
    int value;
    
};

