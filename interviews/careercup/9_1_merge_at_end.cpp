#include <iostream>

using namespace std;

#define m 10
#define n 5


void merge(int a[],int b[]){

  int start = m+n-1;
  int b_end = n - 1;
  int a_end = m - 1;

  while(start>=0){

    //if(a_end == -1 || b[b_end] >= a[a_end]){//wrong here
    if(a_end == -1){
      a[start--] = b[b_end--];
      continue;
    }

    else if(b_end == -1){
    //else if(b_end == -1 || a[a_end] > b[b_end]){
      a[start--] = a[a_end--];
      continue;
    }
    
    if(b[b_end] >= a[a_end])
      a[start--] = b[b_end--];
    else 
      a[start--] = a[a_end--];
  }

}

int main(){

  int a[m+n] = {1,2,5,7,9,12,22,24,26,30,-1,-1,-1,-1,-1};
  int b[n]  = {4,6,8,15,27};

  merge(a,b);


  for(int i = 0; i<m+n;i++){
    cout<<a[i]<<" ";
  }





}

