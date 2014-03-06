#include <iostream>
#include "binary.h"

using namespace std;

int swapOddEven(int num){

  int even = 0x55555555 & num;
  int odd = 0xaaaaaaaa & num;

  int ret = 0;
  ret |= odd>>1 | even<<1;

  return ret;

}

int main(){

  int i = 12394723;

  cout<<getBinaryFormat(i)<<endl;
  cout<<getBinaryFormat(swapOddEven(i))<<endl;

  return -1;


}


