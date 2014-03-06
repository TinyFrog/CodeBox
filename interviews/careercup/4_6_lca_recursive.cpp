#include <iostream>
#include "tree.h"
#include "4_3_build_minheight_bst.cpp"

using namespace std;

template <class T>
bool Tree<T>::isCoveredRecur(TreeNode<T>* n, TreeNode<T>* ganker){

  if(!ganker) return false;
  if(n == ganker) return true;
  return isCoveredRecur(n,ganker->left)||isCoveredRecur(n,ganker->right);

}


template <class T>
TreeNode<T>* Tree<T>::findLCARecur(TreeNode<T>* n1, TreeNode<T>* n2,TreeNode<T>* r){

  if(isCoveredRecur(n1,r->left)&&isCoveredRecur(n2,r->left))
    return findLCARecur(n1,n2,r->left);

  if(isCoveredRecur(n1,r->right)&&isCoveredRecur(n2,r->right))
    return findLCARecur(n1,n2,r->right);  

  return r;

}



int main(){

  int a[10];

  for(int i=0;i<10;i++)
    a[i] = i;
  
  Tree<int> t;
  t.buildMinHeightBST(a,0,9);

  cout<<t.findLCARecur(t.searchBST(5),t.searchBST(7),t.getRoot() )->getKey()<<endl;

  return -1;


}
