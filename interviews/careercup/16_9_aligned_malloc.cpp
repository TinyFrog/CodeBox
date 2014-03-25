#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){

  
  int a[3];
  int *b = a;
  a[-100] = 10;
  int *d = &a[-100];

  cout<<b<<" "<<d<<endl;


}
