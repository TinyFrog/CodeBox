#include <iostream>
#include "graph.h"
#include <queue>

using namespace std;

bool Graph::findRoute(int N1,int N2){

  if(N1>=nodeNum || N2>=nodeNum)
    return false;

  queue<int> myqueue;

  myqueue.push(N1);
  nodeArr[N1].markIt(); // Dont forget it !!

  while(!myqueue.empty()){
    int ind = myqueue.front();
    myqueue.pop();

    ListNode<GraphNode*>* tmp = l[ind].getHead();
    while(tmp){
      if(tmp->getKey()->getNodeID() == N2)
	return true;

      if(!tmp->getKey()->checkMark()){
	tmp->getKey()->markIt();
	myqueue.push(tmp->getKey()->getNodeID());
      }

      tmp = tmp->getNext();
    }

  }

  return false;

}

int main(){

  srand(time(0));
  //declare with parameter?
  //it's ok!
  Graph g(5);
  g.generate();
  g.traverse();
  
  if(g.findRoute(1,1))
    cout<<"hell yeah!!!!"<<endl;

  return -1;


}
