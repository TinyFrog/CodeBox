#include <iostream>
#include <stack>

using namespace std;

class MyStack{
public:
  void push(int value);
  int pop();
  int min();
private:
  stack<int> s;
  stack<int> minS;

};


int MyStack::min(){

  if(minS.empty())
    return 0x7fffffff;
  else
    return minS.top();

}

void MyStack::push(int value){

  //point
  if(value<=min())
    minS.push(value);
  
  s.push(value);

}

int MyStack::pop(){
  if(s.top() == min())
    minS.pop();

  s.pop();
}

int main(){

  srand(time(0));

  MyStack ms;

  cout<<ms.min()<<endl;

  for(int k =0;k<5;k++){
    int value = rand()%10 + 1;
    ms.push(value);
    cout<<value<<" ";
    //ms.printStack();
  }

  cout<<endl;
  
  cout<<ms.min()<<endl;

  return -1;




}

