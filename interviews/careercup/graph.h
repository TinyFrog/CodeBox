#pragma once

#include <iostream>
#include "list.h"

using namespace std;

class GraphNode{
 public:
  friend class Graph;

  GraphNode():nodeID(-1),mark(0){}
  GraphNode(int ID):nodeID(ID){}

  int        operator=(const int rhs)       {nodeID = rhs; return nodeID;}
  GraphNode& operator=(const GraphNode& rhs){nodeID = rhs.getNodeID(); return *this;}
  int        getNodeID() const              {return nodeID;}
  void       markIt()                       {mark = 1;}
  int        checkMark()                    {return mark;}

 private:
  int nodeID;
  int mark;
};

class Graph{
 public:
  Graph(int Num);
  ~Graph(){ delete[] l;}
  void generate();
  void traverse() const;
  bool findRoute(int, int);
  int  getSize(){return nodeNum;}
 private:
  //using the index in nodeArr to locate it's chain relation in the list
  List<GraphNode*>* l;
  GraphNode* nodeArr;
  //nodeAddrArr is used especially for the generate() function
  //after that function is executed, it's certainly messed up
  GraphNode** nodeAddrArr;
  int nodeNum;
};

Graph::Graph(int Num){
  nodeNum = Num;
  nodeArr = new GraphNode[nodeNum];
  nodeAddrArr = new GraphNode*[nodeNum];
  for(int i =0;i<nodeNum;i++){
    nodeArr[i] = i;
    nodeAddrArr[i] = &nodeArr[i];
  }

  l = new List<GraphNode*>[nodeNum];

}


void Graph::generate(){
  
  int ind = nodeNum -1;

  while(ind>=0){

    //for each node, we add random number of directed lines to others
    for(int i =0;i<rand()%(nodeNum +1);i++){

      //each directed line is randomized. 
      int random = rand()%(nodeNum-i);
      if(nodeAddrArr[random]->getNodeID()!=ind){
	l[ind].insert(nodeAddrArr[random]);
      
	GraphNode* tmp = nodeAddrArr[random];
	nodeAddrArr[random] = nodeAddrArr[nodeNum-1-i];
	nodeAddrArr[nodeNum-1-i] = tmp;
      }
    }

    ind--;
  }

}


void Graph::traverse() const{

  for(int i =0;i<nodeNum;i++){
    
    cout<<"Node "<<i<<" links to: ";

    ListNode<GraphNode*>* tmp = l[i].getHead();
    while(tmp){
      cout<<tmp->getKey()->getNodeID()<<" ";
      tmp = tmp->getNext();
    }


    cout<<endl;

  }

}
