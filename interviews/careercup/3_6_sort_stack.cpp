#include <iostream>
#include <stack>

using namespace std;

stack<int> sort(stack<int> s){
  stack<int> r;
  while(!s.empty()){
    int tmp = s.top();
    s.pop();
    while(!r.empty() && tmp<r.top()){
      s.push(r.top());
      r.pop();
    }
    r.push(tmp);
  }

  return r;

}

int main(){
  srand(time(0));

  stack<int> s;

  for(int k =0;k<10;k++){
    int value = rand()%10+1;
    s.push(value);
    cout<<value<<" ";
  }

  cout<<endl;

  s = sort(s);
  
  for(int k =0;k<10;k++){
    cout<<s.top()<<" ";
    s.pop();
  }
  

}
