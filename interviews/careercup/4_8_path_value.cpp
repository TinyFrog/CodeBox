#include <iostream>
#include "tree.h"
#include "4_3_build_minheight_bst.cpp"

using namespace std;

template <class T>
void Tree<T>::sumMatch(TreeNode<T>* node,int sum, int value,list<T> keepPath){
  
  if(!node)
    return;

  if(node->key + sum <= value){
    keepPath.push_back(node->key);
    
    if(node->key + sum == value){
      pathList.push_back(keepPath);
      // return;
    }

    sumMatch(node->left, sum+node->key,value, keepPath);
    sumMatch(node->right, sum+node->key, value, keepPath);

  }

}


template <class T>
void Tree<T>::findPath(TreeNode<T>* node,int value){
  list<T> l;

  if(node){

    sumMatch(node,0,value,l);
    findPath(node->left,value);
    findPath(node->right,value);

  }

}


template <class T>
void Tree<T>::printPaths(){

  for(int i =0;i<pathList.size();i++){

    typename list<T>::iterator it;
    for(it = pathList[i].begin();it != pathList[i].end();++it){
      cout<<(*it)<<" ";
    }
    cout<<endl;

  }
}


int main(){

  srand(time(0));

  int a[100];

  for(int i =0;i<100;i++){
    a[i] = rand()%6-rand()%6;
  }

  Tree<int> t;

  t.buildMinHeightBST(a,0,100);

  t.findPath(t.getRoot(),5);
  t.printPaths();


}



