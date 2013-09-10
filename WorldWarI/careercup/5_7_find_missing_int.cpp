#include <iostream>

using namespace std;



int fetchJth(int num,int j){

  return 1 & num>>j;

}

int partition(int a[],int jth, int p, int q){

  if(p>=q)
    return -1;

  while(true){
    while( fetchJth(a[q],jth) == 1)
      q--;
    while( fetchJth(a[p],jth) == 0)
      p++;
    if(p>=q)
      break;

    int tmp = a[p];
    a[p] = a[q];
    a[q] = tmp;

  }

  return p;

}


int count(int a[], int jth,int value, int p, int q){

  int counter = 0;

  for(int i =p;i<=q;i++){

    if(fetchJth(a[i],jth)==value)
      counter++;

  }

  return counter;

}


int findTheMissing(int a[], int n){
  //array[0..n-1]
  //contatins integer from 0..n
  //one missing


  int ret = 0;
  int p = 0; 
  int q = n-1;

  for(int i =0;(1<<i)<=n;i++){
    if(count(a,i,0,p,q) <= count(a,i,1,p,q)){     
      //missing is 0
      ret |= 0<<i;
      q = partition(a,i,p,q)-1;

    }

    else {
      ret |= 1<<i;
      p = partition(a,i,p,q);

    }

  }

  return ret;
}


int main(){
  const int N = 10;
  
  int a[N] = {0,1,2,3,4,5,7,8,9,10};
  //for( int i = 0; i < N; i++){
  //  a[i] = i;
  //}

  cout<<findTheMissing(a,N);



}
