#include <iostream>
#include "binary.h"

using namespace std;

int checkBits(int a, int b){

  int x_or = a^b;

  int i = 0;
  int counter = 0; 
  while( 1<<i < x_or){
    if(1<<i & x_or)
      counter++;
    
    i++;
  }
  
  return counter;
    
}

int main(){

  int a = 31;
  int b = 14;

  cout<<checkBits(a,b)<<endl;



}
