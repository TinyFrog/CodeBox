#include <iostream>
#include <string>
#include "binary.h"

using namespace std;


int getNextSmallest(int num){
  int i,j,k;
  i=j=k=0;
  
  while( (1<<j & num)==0 )//find the first 1's
    j++;
  if(!j){
    while(1<<i & num) // find the first 0's
      i++;

    if( (1<<i) < num ){// there is still 1's at the left of i
      k = i;
      while( (1<<k & num) ==0) // find that 1's
	k++;
      
      num &= (~0 - (1<<(k+1)) + 1);
      num |= (((1<<(i+1))-1)<<(k-i-1));
      
      cout<<num<<hex<<endl;

    } 
    else{
      cout<<"caonima"<<endl;
      return -1;
    }
  }

  else{

    num ^= (1<<j)|(1<<(j-1));
      

  }

  return num;

}


int getNextLargest(int num){
  
  int i,j;
  while((1<<j&num) == 0)
    j++;
  
  i=j;
  while(1<<i&num)
    i++;

  num ^= (1<<i)|(1<<i-1);
  num &= (~0 - (1<<i-1) +1);
  num |= ((1<<i-j-1)-1);

  return num;


}


int main(){
  
  int num = -115;

  cout<<getBinaryFormat(num)<<endl;

  cout<<getBinaryFormat(getNextLargest(num))<<endl;
  cout<<getBinaryFormat(getNextSmallest(num))<<endl;
  return -1;



}
