#include<iostream>
#include<stdlib.h>

using namespace std;

#define LEN 10

void insertion_sort(int a[]){

  for(int i = 1; i<LEN; i++){

    int j = i;
    int key = a[i];

    while(j>0 && a[j-1]>key){
      a[j] = a[j-1];
      j--;
    }
    
    a[j] = key;
  }

}


int main(){

  int arr[LEN];

  for(int k =0;k<LEN;k++){
    arr[k] = rand()%100+1;
    cout<<arr[k]<<" ";
  }

  cout<<endl;

  insertion_sort(arr);

  for(int k =0;k<LEN;k++){
    cout<<arr[k]<<" " ;
  }

  getchar();

}
