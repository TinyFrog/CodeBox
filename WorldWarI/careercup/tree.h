#pragma once

#include <vector>
#include <iostream>
#include "list.h"
#include <list>

using namespace std;

template <class T>
class TreeNode{
 public:
  template <class Y> friend class Tree;
  TreeNode(){;}
  TreeNode(T value):left(NULL),right(NULL),key(value){}
  T getKey() const {return key;}

 private:
  TreeNode* left;
  TreeNode* right;
  TreeNode* parent;
  T key;
};


template <class T>
class Tree{
 public:
  Tree(){root = NULL;}
  void                     generate(int Num);
  TreeNode<T>*             createNode(TreeNode<T>*& node, int value);
  void                     inOrder(TreeNode<T>* node);
  void                     preOrder(TreeNode<T>* node);
  TreeNode<T>*             getRoot(){return root;}

  int                      getMaxDepth(TreeNode<int>* node); //4_1
  bool                     checkBalance(TreeNode<int>* node); //4_1

  TreeNode<T>*             buildMinHeightBST(int a[], int p, int q); //4_3

  void                     createDepthList(TreeNode<T>* node,int depth); //4_4
  void                     traverseDepthList(); //4_4

  TreeNode<T>*             findSuccessor(TreeNode<T>* node);//4_5
  TreeNode<T>*             searchBST(T value);//4_5

  TreeNode<T>*             findLCA(TreeNode<T>*, TreeNode<T>*);//4_6
  bool                     isCovered(TreeNode<T>*, TreeNode<T>*,TreeNode<T>*);//4_6
  TreeNode<T>*             findLCARecur(TreeNode<T>*, TreeNode<T>*,TreeNode<T>*);//4_6'
  bool                     isCoveredRecur(TreeNode<T>*, TreeNode<T>*);//4_6'

  bool                     isMatched(TreeNode<T>*, TreeNode<T>*); //4_7
  bool                     isSubtree(TreeNode<T>*, TreeNode<T>*); //4_7

  void                     findPath(TreeNode<T>* node, int value);
  void                     sumMatch(TreeNode<T>* node, int sum, int value, list<T> keepPath);
  void                     printPaths();

 private:
  TreeNode<T>*                root;
  vector<List<TreeNode<T>*>*> depthList; //4_4
  vector<list<T> >             pathList;  //4_8
};

template <class T>
TreeNode<T>* Tree<T>::createNode(TreeNode<T>*& node, int value){

  if(node)   
    return createNode(rand()%2?node->left:node->right,value);
  
  else{
    node = new TreeNode<T>(value);
    return node;

  }

}

template <class T>
void Tree<T>::generate(int Num){
  int k = 0;

  while(Num){
    createNode(root,k++);
    Num--;
  }

}

template <class T>
void Tree<T>::inOrder(TreeNode<T>* node){

  if(node){
    inOrder(node->left);
    cout<<node->key<<" ";
    inOrder(node->right);
  }

}

template <class T>
void Tree<T>::preOrder(TreeNode<T>* node){

  if(node){
    cout<<node->key<<" ";
    preOrder(node->left);
    preOrder(node->right);
  }

}


template <class T>
TreeNode<T>* Tree<T>::searchBST(T value){

  TreeNode<T>* node = root;
  while(node){
    if(node->getKey() == value)
      return node;


    node = node->getKey()>value?node->left:node->right;

  }

  return node;

}
