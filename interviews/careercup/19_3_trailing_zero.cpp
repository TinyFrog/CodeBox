#include <iostream>

using namespace std;

long int factorial(int Nth){

  if(Nth == 0)
    return 1;

  return Nth*factorial(Nth-1);

}

int trailingZeros(int Nth){

  int counter = 0;

  for(int i = Nth ; i>=0; i--){
    int tmp = i;

    //dont forget the tmp!=0
    while(tmp%5 == 0 && tmp!=0){
      tmp /= 5;
      counter++;

    }

  }

  return counter;

}


int main(){


  //unsigned long sb = factorial(8);

  cout<<trailingZeros(20);

}
