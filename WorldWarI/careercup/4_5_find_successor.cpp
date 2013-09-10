#include "tree.h"
#include "4_3_build_minheight_bst.cpp"
#include "4_4_depth_list.cpp"
#include <iostream>

using namespace std;

template <class T>
TreeNode<T>* Tree<T>::findSuccessor(TreeNode<T>* node){

  if(!node)
    return NULL;

  if(node->right){
    node = node->right;
    while(node->left)
      node = node->left;
    return node;
  }

  //
  //this is not correct!
  //consider that node is the node with the largest value in the BST 
  //
  //while(node->parent&&node == node->parent->right)
  //  node = node->parent;
  //return node;


  TreeNode<T>* p = node->parent;

  while(p&&node == p->right){
    node = p;
    p = p->parent;

  }

  return p;




}


int main(){

  int a[10];

  for(int i=0;i<10;i++)
    a[i] = i;
  
  Tree<int> t;
  t.buildMinHeightBST(a,0,9);

  //t.createDepthList(t.getRoot(),0);

  //t.traverseDepthList();

  cout<<t.findSuccessor(t.searchBST(6))->getKey()<<endl;

  return -1;



}
