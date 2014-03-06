#include <iostream>
#include <stack>

using namespace std;

void slide(stack<int>& source, stack<int>& dest, stack<int>& tmp, int num){

  if(num == 1){
    if(dest.empty()||source.top()<dest.top()){
      dest.push(source.top());
      source.pop();
      
    }
    return;
  }

  slide(source, tmp, dest,num-1);
  slide(source, dest,tmp,1);
  slide(tmp,dest,source,num-1);
}


int main(){
  //srand(time(0));

  stack<int> s[3];
  

  for(int k=0;k<10;k++){

    s[0].push(10-k);

  }

  slide(s[0],s[2],s[1],10);

  for(int k=0;k<10;k++){
    cout<<s[2].top()<<" ";
    s[2].pop();
  }

}
