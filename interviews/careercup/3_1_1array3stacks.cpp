#include <iostream>

using namespace std;


class MyStack{
public:
         MyStack(int N):top((N-1)/2),next((N-1)/2),maxSize(N){ array = new int[N]; for(int k = 0;k<N;k++) array[k] = 0;}
         ~MyStack(){delete[] array;}
  void   push(int value);
  int    pop();
  void   printStack(){for(int k =0;k<maxSize;k++) cout<<array[k]<<" "; cout<<endl;}
private:
  int    maxSize;
  int    top;
  int    next;
  int*   array;
};

void MyStack::push(int value){

  int tmp;
  //key point
  if(top == next && !array[top]){
    array[top] = value;
    return;
  }
 
  tmp = top;
  top = next<top?next-1:next+1;
  next = tmp;

  if(top>=0&&top<maxSize)
    array[top] = value;
  else
    cout<<"Full!"<<endl;
  
}

int MyStack::pop(){

  int value = array[top];
  array[top] = 0;

  if(top == next){
    cout<<"empty!"<<endl;
    return value;
  }

  int tmp = next;
  if(next<top) next = top -1;
  else         next = top +1;
  top = tmp;
  
  return value;

}



int main(){

  MyStack ms(8);

  for(int k =0;k<5;k++){
    ms.push(rand()%10+1);
    ms.printStack();
  }
      
  for(int k =0;k<7;k++){
    ms.pop();
    ms.printStack();
  }

  for(int k =0;k<5;k++){
    ms.push(rand()%10+1);
    ms.printStack();
  }

  return -1;
}
