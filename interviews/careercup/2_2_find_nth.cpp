#include <iostream>
#include "list.h"

using namespace std;

ListNode<int>* findNthToLast(List<int>& l, int N){

  ListNode<int>* p = l.getHead();
  int counter = 0;
  while(p){
    p = p->getNext();
    counter++;
  }
  if(N>counter)
    return NULL;

  counter = counter - N;
  p = l.getHead(); 
  while(counter > 0){
    p = p->getNext();
    counter--;
  }

  return p;
}

ListNode<int>* findNthBy2P(List<int>& l, int N){

  ListNode<int>* p1 = l.getHead();
  ListNode<int>* p2 = p1;

  for(int i =0; i<N;i++){
    if(!p2) return NULL;
    p2 = p2->getNext();
  }
  
  while(p2){
    p1 = p1->getNext();
    p2 = p2->getNext();
  }

  return p1;

}


int main(){

  srand(time(0));

  List<int> l;
  
  for(int k = 0;k<5;k++)
    l.insert(rand()%10);

  l.printList();

  cout<<endl;
  
  ListNode<int>* nth = findNthBy2P(l, 2);
  
  cout<<findNthToLast(l,2)->getKey()<<endl;
  cout<<nth->getKey()<<endl;
  
  return -1;
}

