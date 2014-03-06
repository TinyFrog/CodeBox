#include "tree.h"
#include "4_3_build_minheight_bst.cpp"
#include <iostream>

using namespace std;


template <class T>
bool Tree<T>::isMatched(TreeNode<T>* n1, TreeNode<T>* n2){
  if(!n1&&!n2)
    return true;
  //pay attention here
  if(!n1||!n2)
    return false;
  if(n1->key == n2->key)
    return isMatched(n1->left,n2->left)&&isMatched(n1->right,n2->right);
  else
    return false;

}

template <class T>
bool Tree<T>::isSubtree(TreeNode<T>* large, TreeNode<T>* small){
  
  if(large){
   if(large->key == small->key)
     if(isMatched(large,small)) 
  	return true;

   return isSubtree(large->left,small) || isSubtree(large->right,small);

  }

  return false;
}


int main(){

  int a[10];

  for(int i =0;i<10;i++){
    a[i] = i;
  }

  Tree<int> t1,t2;

  t1.buildMinHeightBST(a,0,9);
  t2.buildMinHeightBST(a,1,3);

  if(t2.isSubtree(t1.getRoot(),t2.getRoot()))
    cout<<"hell yeah!!"<<endl;


  return -1;

}
