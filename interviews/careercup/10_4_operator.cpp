#include <iostream>

using namespace std;

class Num{

public:
  Num(){}
  Num(int v):value(v){}
  const Num operator *(const Num& rhs);
  const Num operator -(const Num& rhs);
  const Num operator /(const Num& rhs);
  int getValue() const{return value;}

private:
  int value;

};

ostream& operator<<(ostream& os, const Num& n){

  os<<n.getValue();

  return os;

}

const Num Num::operator-(const Num& rhs){
  
  Num tmp = *this;

  tmp.value = tmp.value + (rhs.value^0xFFFFFFFF) +1;

  return tmp;

}


const Num Num::operator*(const Num& rhs){
  
  Num tmp = *this;

  int v = tmp.value;

  for(int i = 1;i<rhs.value;i++){
    
    tmp.value += v;

  }

  return tmp;

}


const Num Num::operator/(const Num& rhs){

  Num tmp = *this;

  int counter = 0;

  while(tmp.value>= rhs.value){
    
    tmp.value = tmp.value - rhs.value;
    counter++;
  }

  tmp.value = counter;

  return tmp;

}


int main(){

  Num a(3);
  Num b(21);

  cout<<(a-b)<<endl;
  cout<<(a*b)<<endl;
  cout<<(b/a)<<endl;


}
