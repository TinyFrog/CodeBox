#include<iostream>

using namespace std;

#define TREELEN 6

class Node{
public:

  Node(char v):value(v){}
  Node* left;
  Node* right;
  char  value;
};

char PreOrder[TREELEN] = {'a','b','d','c','e','f'};
char InOrder[TREELEN] = {'d','b','a','e','c','f'};

int index = 0;

int InOrderPos(int i){

  for(int k = 0; k< TREELEN; k++)
    if(InOrder[k] == PreOrder[i])
      return k;
  
  return -1;

}

void BuildTree(int i, int j, int curr , Node* prev){
  
  int k = -1;
  if(InOrderPos(curr) == -1){
    cout<<"Something wrong"<<endl;
    return;
  }
  else
    k = InOrderPos(curr);
  
  if( k != i ){
    Node* t = new Node(PreOrder[++index]);
    prev -> left = t;
    BuildTree(i, k-1,index, t);
  }
  else 
    prev ->left = NULL;

  if( k != j ){
    Node* t = new Node(PreOrder[++index]);
    prev -> right = t;
    BuildTree(k+1, j, index,t);
  }
  else
    prev -> right = NULL;


}

void TraverseBinTree(Node* root){

  if(root){

    
    TraverseBinTree(root->left);

    TraverseBinTree(root->right);
cout<<root->value<<endl;

  }


}


int main(){

  
  Node* pRoot = new Node(PreOrder[0]);
  
  BuildTree(0, TREELEN - 1, 0, pRoot);

  TraverseBinTree(pRoot);

  return -1;
}
