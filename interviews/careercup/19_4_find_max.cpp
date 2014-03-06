#include <iostream>

using namespace std;

int findMax(int i, int j){

  int s = i - j;
  int m = (s>>31) & 1;

  return i - s*m;


}


int main(){



  cout<<findMax(100,23)<<endl;


}
