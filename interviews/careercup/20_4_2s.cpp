#include <iostream>


using namespace std;

int cal2s(int num, int bit){
  
  if(num == 1 || num == 0)
    return 0;

  if(num >= 2 && num <=10)
    return 1;
  
  if(num<bit*2)
    //154 = f(100) + f(54)
    return cal2s(num%bit, bit/10) + cal2s(bit, bit/10);
  else if(num>= bit*2 && num<3*bit)
    //254 = 54 + f(100)*2 + f(54)
    //dont forget the plus 1 here
    return cal2s(num%bit, bit/10) + (num%bit +1)  + cal2s(bit, bit/10) * (num/bit);
  else
    //574 = 100 + f(100)*5+f(74)
    return cal2s(num%bit, bit/10) + bit + cal2s(bit, bit/10)*(num/bit);
  
}


//alert, when num == 100, bit should be 10
//                   101, bit should be 100

int getBit(int num){
  
  int k = 1;
  while(num/k>=10){
    k *= 10;
  }

  //if num == 100, bit is 10,however for num == 200 ,bit should not be 10.
  //so the condition is whether num == k 
  //not num%k == 0
  if(num == k)
    k /= 10;

  cout<<k<<endl;

  return k;

}

int main(){
  
  int num = 247;
  
  cout<<cal2s(num,getBit(num));

  return -1;



}





