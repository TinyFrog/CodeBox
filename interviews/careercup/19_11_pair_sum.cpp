#include <iostream>

using namespace std;

#define N 10

#define value 7

void qsort(int a[], int l, int r){

  if(l>=r)
    return;

  int p = l-1;
  int q = r+1;

  int sentinel = a[l];

  while(true){

    do{p++;}while(a[p]<sentinel);
    do{q--;}while(a[q]>sentinel);
    if(p>=q) break;

    int tmp = a[p];
    a[p] = a[q];
    a[q] = tmp;

  }

  qsort(a,l,q);
  qsort(a,q+1,r);                   


}


void findPairs(int a[], int LEN,int sum){

  int i = 0;
  int j = LEN-1;

  while(i<j){
    
    if(a[i]+a[j]==sum){
      cout<<a[i]<<" "<<a[j]<<endl;
      i++;
      j--;
    }
    else if(a[i]+a[j]<sum){
      i++;
    }
    else{

      j--;
    }
  }

}



int main(){
  
  int a[N];

  for(int i = 0;i<N;i++){
    a[i] = rand()%8;
    cout<<a[i]<<" ";
  }

  cout<<endl;

  qsort(a,0,N-1);

  findPairs(a,N,5);

  for(int i = 0;i<N;i++){
    cout<<a[i]<<" ";
  }  


}
