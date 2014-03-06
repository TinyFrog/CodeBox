#include <iostream>
#include "list.h"

using namespace std;

ListNode<int>* findFirstInLoop(List<int>& l){
  //ListNode<int>* first;
  ListNode<int>* normal;
  ListNode<int>* fast;


  normal = l.getHead();
  fast = l.getHead();

  while(fast){
    normal = normal->next;
    fast = fast->next->next;

    if(fast == normal)
      break;

  }

  if(!fast) return NULL;

  //it becomes normal now!
  fast = l.getHead();

  while(fast != normal){

    fast= fast->next;
    normal = normal->next;

  }

  return fast;

}


int main(){

  srand(time(0));

  List<int> l;
  
  for(int k = 0;k<5;k++)
    l.insert(rand()%10);

  l.printList();

  ListNode<int>* last = l.getHead();

  while(last->next) last = last->next;

  last->next = l.getHead()->next->next->next;

  cout<<findFirstInLoop(l)->key<<endl;

  return -1;

  


}
