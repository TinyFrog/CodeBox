#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class SetOfStacks{
public:
  SetOfStacks(){stack_max_size = 5;}

  void push(int value);
  int pop();
  int popAt(int index);
  void print();
  
private:
  vector<stack<int>*> setOfStacks;
  int stack_max_size;

};

void SetOfStacks::push(int value){
  
  if(setOfStacks.empty()||setOfStacks.back()->size() == stack_max_size)
     setOfStacks.push_back(new stack<int>());
    
  setOfStacks.back()->push(value);
  
} 

int SetOfStacks::pop(){

  if(setOfStacks.empty()){
    cout<<"Empty! pop your sister!"<<endl;
    return -1;

  }
  int ret = setOfStacks.back()->top();
  setOfStacks.back()->pop();

  if(setOfStacks.back()->empty())
    setOfStacks.pop_back();

  return ret;

}

int SetOfStacks::popAt(int index){

  if(index>=setOfStacks.size()||index <0)
    return -1;

  int ret = setOfStacks[index]->top();
  setOfStacks[index]->pop();
  
  for(int j = index; j<setOfStacks.size() - 1;j++){
    stack<int> tmp;
    while(!setOfStacks[j+1]->empty()){
      tmp.push(setOfStacks[j+1]->top());
      setOfStacks[j+1]->pop();

    }
    
    setOfStacks[j]->push(tmp.top());
    tmp.pop();

    while(!tmp.empty()){
      setOfStacks[j+1]->push(tmp.top());
      tmp.pop();
    }
  }

  return ret;

}


void SetOfStacks::print(){
  
  vector<stack<int>*>::iterator it;
  for(it = setOfStacks.begin();it<setOfStacks.end();++it)
    cout<<(*it)->top()<<"|";

  cout<<endl;
  
  
}


int main(){

  srand(time(0));
  
  SetOfStacks sos;

  for(int k =0; k<16;k++){
    int value = rand()%10 + 1;
    sos.push(value);
    cout<<value<<" ";

  }


  cout<<endl;

  sos.print();

  sos.pop();
  sos.print();

  sos.popAt(0);
  sos.print();

  return -1;

}
