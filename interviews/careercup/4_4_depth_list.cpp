#include "list.h"
#include "tree.h"
#include <iostream>

using namespace std;

template <class T>
void Tree<T>::createDepthList(TreeNode<T>* node,int depth){

  if(!node)
    return;

  if(depth==depthList.size())
    depthList.push_back(new List<TreeNode<T>*>);

  depthList[depth]->insert(node);

  createDepthList(node->left,depth+1);
  createDepthList(node->right,depth+1);

}

template <class T>
void Tree<T>::traverseDepthList(){

  typename vector<List<TreeNode<T>*>*>::iterator it;

  for(it = depthList.begin();it<depthList.end();++it){
    ListNode<TreeNode<T>*>* tmp = (*it)->getHead();

    while(tmp){
      cout<<tmp->getKey()->getKey()<<" ";
      tmp = tmp->getNext();
    }
    cout<<endl;    

  }

}



//int main(){ 
//
//  Tree<int> t;
//
//  t.generate(10);
//
//  t.inOrder(t.getRoot());
//
//  cout<<endl;
//
//  t.createDepthList(t.getRoot(),0);
//
//  t.traverseDepthList();
//
//  return -1;
//
//}
