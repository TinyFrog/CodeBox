#include <iostream>
#include "list.h"

using namespace std;

List<int> SumUp(List<int>& l1, List<int>& l2){

  List<int> sum;
  ListNode<int>* n1;
  ListNode<int>* n2;
  n1 = l1.getHead();
  n2 = l2.getHead();
  int res = 0;

  //res!
  while(n1||n2||res){
    int i,j;

    if(n1){
      i = n1->key;
      n1 = n1->next;
    }
    else 
      i = 0;
    
    if(n2){
      j = n2->key;
      n2 = n2->next;
    }
    else 
      j = 0;

    if(i+j+res>=10){
      sum.insert(i+j+res - 10);
      res = 1;
    }
    else {
      sum.insert(i+j+res);
      res = 0;
    }

  }

  return sum;

}

int main(){

  List<int> sumList,l1,l2;

  srand(time(0));
  
  for(int k = 0;k<10;k++){
    l1.insert(rand()%10);
    l2.insert(rand()%10);
  }

  l1.printList();
  l2.printList();

  sumList = SumUp(l1,l2);
  
  sumList.printList();

  return -1;
  

}
