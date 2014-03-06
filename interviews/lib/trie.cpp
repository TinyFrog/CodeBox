#include <iostream>
#include <list>
#include <string>

using namespace std;


class TrieNode{
public:
  TrieNode(char k){this->key = key;}
  TrieNode(int value){this->value = value;}//the last node
  TrieNode* next;
  TrieNode* children;
  char key;
  int value;
  
};


class Trie{
public:
  void insert(string s, int i);
  bool find(string s);

private:
  TrieNode* root;

};

bool Trie::find(string s){
  
  TrieNode* node = root->children;
  
  for(int i = 0; i<s.size();i++){
    while(true){
      if(node == NULL)
	return false;

      if(node->key = s[i]){
	node = node->children;
	break;
      }
    
      node = node->next;
    }    

  }

  return true;


}

void Trie::insert(string s,int i){

  if(s.size() == 0)
    return ;

  TrieNode* node = root->children;
  TrieNode* parent;
  TrieNode* sibling;
  for(int i = 0;i<s.size();i++){

    if(node == NULL){
      node = new TrieNode(s[i]);
      parent->children = node;
      parent = node;
      node = node->children;
      break;
    }

    while(node != NULL){
      if(node->key == s[i]){
	if(node->children != NULL)
	  node = node->children;
	
	else{
	  parent = node;
	  node = node->children;
	}
        break;
      }
 
      else{
	node = node->next;
	if(node->next == NULL)
	  node->next = new TrieNode(s[i]);
	
      }
    }
   
  }

  node = new TrieNode(i);
  parent->next = node;

}

int main(){

  Trie t;
  t.insert("adsf",5);
  cout<<t.find("asdf")<<endl;

  return -1;
}




