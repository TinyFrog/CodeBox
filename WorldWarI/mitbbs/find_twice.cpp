#include <iostream>

using namespace std;

#define N 5

//this question starts with a thought that if an array consists of integer which each appears twice except one that shows only once
//then that could be solved by xor all together, and the result is the one

//follow up:
//on the contrary, only one value shows twice:


int findDuplicate(int a[]){

  int xorsum = 0;

  for(int i = 0;i<N;i++)
    xorsum ^= a[i];

  for(int i = 0;i<N;i++){
    if(xorsum^(xorsum^a[i]) == a[i])
      return a[i];
  }

  return -1;
}

int main(){

  int a[5] = {3,2,5,2,4};

  cout<<findDuplicate(a)<<endl;

}
