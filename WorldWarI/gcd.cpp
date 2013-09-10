#include <iostream>
#include <stdlib.h>

using namespace std;

int gcd(int x, int y){
  return (!y)?x:gcd(y,x%y);
}

int gcd_minus(int x, int y){
  if(x == 0)
    return y;
  if(x > y)
    return gcd_minus(y,x);
  else
    return gcd_minus(y-x,x);

}

int main(int argc,char* argv[]){

  int i = 5;
  int j = 7;

  
  cout<<gcd_minus(i,j);

  return -1;

}
