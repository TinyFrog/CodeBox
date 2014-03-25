#include <iostream>
#include <stack>

using namespace std;

class myQueue{
public:
  myQueue(){}
  void Enqueue(int value);
  int Dequeue();

private:
  stack<int> s1,s2;

};

void myQueue::Enqueue(int value){

  while(!s2.empty()){
    s1.push(s2.top());
    s2.pop();
  }
  
  s1.push(value);

}

int myQueue::Dequeue(){
  while(!s1.empty()){
    s2.push(s1.top());
    s1.pop();
  }

  int ret = s2.top();
  s2.pop();

  return ret;  

}


int main(){

  srand(time(0));

  myQueue mq;

  for(int k =0;k<10;k++){
    int value = rand()%10+1;
    mq.Enqueue(value);
    cout<<value<<" ";
  }
  cout<<endl;
  
  cout<<mq.Dequeue()<<endl;

  mq.Enqueue(38);
  for(int k =0;k<10;k++){
    cout<<mq.Dequeue()<<" ";
  }
  return -1;

}
