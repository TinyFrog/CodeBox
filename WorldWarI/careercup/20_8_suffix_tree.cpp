#include <iostream>
#include <string>
#include <map>
#include <vector>


class SuffixTreeNode{

public:
  SuffixTreeNode(){}
  void insertString(string s, int index){
    indexes.push_back(index);

    if(!s.empty()){

      value = s[0];
      SuffixTreeNode* child = NULL;

      if(children.find(value) != children.end() ){// contains the key
	                                          // the map in C++ doesn't have the containKey() function therefore
	                                          // i then use the find to figure out whether the specific value is found or not

	child  = children.find(value);

      }

      else{
	
	child = new SuffixTreeNode();
	children.insert(pair<char,SuffixTreeNode*)(value,child));
	

      }

      string remainder = s.substr(1,s.size()-1);
      child.insertString(remainder, index);//index is not modified during this procedure


    }

  }



  vector<int> getIndexes(string s){
    if(s.empty())
      return indexes;
    else{
      char first = s[0];
      if(children.find(first) != children.end() ){

	string remainder = s.substr(1,s.size()-1);
	return children.find(first)->second->getIndexes(remainder);

      }

    }

  }  

private:
  map<char, SuffixTreeNode*> children;
  vector<int> indexes;
  char value;

}


class SuffixTree{

public:
  SuffixTree(){}
  SuffixTree(string s);

private:
  SuffixTreeNode* root;


}
