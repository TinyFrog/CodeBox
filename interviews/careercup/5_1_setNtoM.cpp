#include <iostream>

using namespace std;

void Set(int N, int M, int i, int j){

  int max = (0xFFFFFFFF)<<(j+1);
  int min = (0xFFFFFFFF)>>(32-i);
  
  int mix = min|max;
  cout<<(N&mix|(M<<i))<<hex<<endl;

}


int main(){

  Set(2048,21,2,6);

}
