#include <iostream>
#include "list.h"

using namespace std;

bool deleteMid(ListNode<int>* node){

  if(!node || !node->next)
    return false;

  ListNode<int>* next = node->next;
  node->key = next->key;
  node->next = next->next;

  return true;

}

int main(){

  srand(time(0));

  List<int> l;
  ListNode<int>* sb = NULL;
  
  for(int k = 0;k<3;k++){
    l.insert(rand()%10);
  }

  sb = l.getHead()->next->next;

  l.printList();
  
  deleteMid(sb);

  l.printList();

  return -1;
  


}



