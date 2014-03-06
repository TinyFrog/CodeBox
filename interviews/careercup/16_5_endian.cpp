#include <iostream>

using namespace std;

int main(){

  int i = 1024*1024*1024+1;
  char* c =(char*)&i;
  cout<<*c;




}
