#include <iostream>
#include "list.h"

using namespace std;


//2 problems:
//a. we check p->next, therefore we cannot assign p=p->next each time without any condition.
//   e.g. elements:1,2,3,4. a[1] == a[2], remove(1->next),therefore p = 3 and we just check 3->next,skipping a[3]
//b. when there are only 2 elements left and they have same value.->segmentation fault
//   but we should blame the programmer who provides us the List class! It doesn't even function correctly!    


//Oct 8th newly updated, removing duplication would be much easier if we start from the second node, so why not?

void removeDup(List<int>& l){

  ListNode<int>* p = l.getHead();
  ListNode<int>* q;

  while(p->next){
    q = l.getHead();

    while(q!=p->next){// the break 4 lines below make the if(q) here unnecessary

      if(p->next->key == q->key){
        l.remove(p->next);
	break;
      }
      q = q->next;
    }

    if(q == p->next)
      p = p->next;
  }
 
}


int main(){

  srand(time(0));

  List<int> l;
  
  for(int k = 0;k<1000;k++)
    l.insert(rand()%10);

  l.printList();

  cout<<endl;
  
  removeDup(l);

  l.printList();
  
  return -1;
}

