#include <iostream>

using namespace std;

int fibonacci(int N){
  
  if(N == 0)
    return 0;
  if(N == 1)
    return 1;

  return fibonacci(N-1) + fibonacci(N-2);



}

int main(){


  for(int i = 0; i<30;i++){

    cout<<fibonacci(i)<<" ";


  }


  return -1;




}
