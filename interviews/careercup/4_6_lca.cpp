#include "tree.h"
#include "4_3_build_minheight_bst.cpp"
#include "4_4_depth_list.cpp"
#include <iostream>

using namespace std;

template <class T>
bool Tree<T>::isCovered(TreeNode<T>* n1, TreeNode<T>* n2, TreeNode<T>* iter){
  
  if(!iter)
    return false;

  if(iter == n1 || iter == n2)
    return true;
  
  return isCovered(n1,n2,iter->left)||isCovered(n1,n2,iter->right);
}


template <class T>
TreeNode<T>* Tree<T>::findLCA(TreeNode<T>* n1, TreeNode<T>* n2){
  TreeNode<T>* node = root;
  
  while(isCovered(n1,n2,node)){
    //node == n1 || node == n2
    if(  (isCovered(n1,n2,node->left)&&isCovered(n1,n2,node->right)) || node == n1 || node == n2 )
      return node;

    if(isCovered(n1,n2,node->left))
      node = node->left;
    else
      node = node->right;
  
  }

  return node;

}

int main(){

  int a[10];

  for(int i=0;i<10;i++)
    a[i] = i;
  
  Tree<int> t;
  t.buildMinHeightBST(a,0,9);

  cout<<t.findLCA(t.searchBST(5),t.searchBST(7))->getKey()<<endl;




  return -1;


}


