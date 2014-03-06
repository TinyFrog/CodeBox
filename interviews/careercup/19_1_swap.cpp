#include <iostream>

using namespace std;

void swap(int& a, int& b){
  
  a = a - b;
  b = b + a;
  a = b - a;
}

int main(){

  int a = -5;
  int b = 17;

  swap(a,b);

  cout<<a<<" "<<b<<endl;

 


}
