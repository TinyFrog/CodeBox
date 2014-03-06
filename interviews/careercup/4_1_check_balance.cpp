#include <iostream>
#include "tree.h"
#include <algorithm>

using namespace std;

int Tree:getMaxDepth(TreeNode<int>* node){
  
  if(!node)
    return 0;
  else 
    return max(getMaxDepth(node->left)+1,getMaxDepth(node->right)+1);

}


bool Tree::checkBalance(TreeNode<int>* node){

  if(node){
    int diff = getMaxDepth(node->left)-getMaxDepth(node->right);
    if(diff>1||diff<-1)
      return false;
    else 
      return checkBalance(node->left)&&checkBalance(node->right);
  }
  else 
    return true;
}


int main(){

  srand(time(0));

  Tree<int> t;
  
  t.generate(6);
  t.inOrder(t.getRoot());
  cout<<endl;
  t.preOrder(t.getRoot());
  cout<<endl;
  //cout<<t.getRoot()->key;
  
  if(t.checkBalance(t.getRoot()))
    cout<<"hell yeah"<<endl;
  else 
    cout<<"malegeshi"<<endl;

  


  return -1;

}
