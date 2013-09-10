#include <iostream>
using namespace std;

class A{
public:
  A(){}
  void printAddr(){cout<<a<<endl;}

  int a[100];
};


int main(){
  //cout<<"fuck you ssbd"<<endl;
  A a;
  A b= a;
  
  a.printAddr();
  a.a[3] = 5;
  b.a[3] = 100;
  cout<<a.a[3]<<endl;
  b.printAddr();

  //scout<<"fsdfal"<<endl;
  return 1;


}
