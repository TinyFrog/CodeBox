#include "tree.h"
#include <iostream>

using namespace std;

template <class T>
TreeNode<T>* Tree<T>::buildMinHeightBST(int a[],int p, int q){
  
  if(p>q)
    return NULL;
  
  int mid = p + (q-p)/2;
  TreeNode<T>* t = new TreeNode<T>(a[mid]);
 
  if(!root)
    root = t;
 
  TreeNode<T>* l_ret;
  TreeNode<T>* r_ret;
  l_ret = buildMinHeightBST(a,p,mid-1);
  t->left = l_ret;
  if(l_ret)
    l_ret->parent = t;
  
  r_ret = buildMinHeightBST(a,mid+1,q);
  t->right = r_ret;
  
  if(r_ret)
    r_ret->parent = t;
  

  return t;
}


//int main(){
//
// srand(time(0));
// int a[10];
//
//  for(int i=0;i<10;i++)
//    a[i] = i;
//
//  Tree<int> t;
//  t.buildMinHeightBST(a,0,9);

//  t.inOrder(t.getRoot());
//  cout<<endl;
//  t.preOrder(t.getRoot());

//  return -1;

//}

