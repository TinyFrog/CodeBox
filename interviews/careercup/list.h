#pragma once

#include <iostream>

using namespace std;

template <class T>
class ListNode{
 public:
  template<class Y> friend class List;

  ListNode(T value):key(value),next(NULL){}
  ListNode<T>* getNext(){return next;}
  T            getKey(){return key;}
 private:
  ListNode<T>* next;
  T key;
};


template <class T>
class List
{
 public:
  List(){head = NULL;size = 0;}
  void         insert(T key);
  void         remove(T key); //remove the first element which has the same value as key
  void         remove(ListNode<T>* t);//remove by the pointer
  int          getSize(){return size;}
  void         printList(){ListNode<T>* p = head; while(p){cout<<p->key<<" ";p=p->next;} cout<<endl;}
  
  ListNode<T>* getHead(){return head;}
  
 private:
  ListNode<T>* head;
  int size;
};

template <class T>
void List<T>::insert(T key){
  ListNode<T>* p = head;

  if(!p){
    head = new ListNode<T>(key);
    head->next = NULL;
  }
  else{
    while(p->next)
      p = p->next;    
    p->next = new ListNode<T>(key);
  }

  size++;
}


template <class T>
void List<T>::remove(T key){
  ListNode<T>* p = head;

  if(!p) return;
  if(p->key == key){
    head = NULL;
    delete p;
    size--;
  }
  
  while(p->next){
    if(p->next->key == key){
      ListNode<T>* tmp = p->next;
      p->next = p->next->next;
      delete tmp;
      size--;
      break; //break!!! now p->next == NULL but there is no change to assign this NULL value to p and therefore no segmentation fault happens at the start of the while loop
    }
    p = p->next;
  }
}

template <class T>
void List<T>::remove(ListNode<T>* target){

  ListNode<T>* p = head;
  if(p == target){
    head = p->next;
    delete p;
    return;
  }
  
  while(p && p->next){//
    if(p->next == target){
      p->next = p->next->next;
      delete target;
      target = NULL;
      size--;
      return;
    }
    p = p->next;
  }

}
