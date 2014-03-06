#include <iostream>

using namespace std;

#define LEN 1000000

void merge(int a[],int l,int mid,int r){

  int len1 = mid - l + 1;
  int len2 = r - mid;

  int* left_arr = new int[len1 + 1];
  int* right_arr = new int[len2 + 1];

  int i = l;

  for(int k=0;k<len1;k++)
    left_arr[k] = a[i++];

  for(int k=0;k<len2;k++)
    right_arr[k] = a[i++];

  left_arr[len1] = ~(1<<31);
  right_arr[len2] = ~(1<<31);

  int p,q;
  p=q=0;

  for(int k = l;k<=r;k++){
    if(left_arr[p]>right_arr[q])
      a[k] = right_arr[q++];
    else 
      a[k] = left_arr[p++];
  }

  delete[] left_arr;
  delete[] right_arr;
}


void mergesort(int a[],int l, int r){

  if(l<r){
    int mid = l+(r-l)/2;
    mergesort(a,l,mid);
    mergesort(a,mid+1,r);
    merge(a,l,mid,r);
  }

}

int main(){

  //cout<<~(1<<31)<<endl;
  //cout<<(0x7fffffff)<<endl;
  // cout<<
  int arr[LEN];

  srand(time(0));
  for(int k =0;k<LEN;k++){
    arr[k] = rand()%100+1;
    cout<<arr[k]<<" ";
  }

  cout<<endl;

  mergesort(arr,0,LEN-1);

  for(int k =0;k<LEN;k++){
    cout<<arr[k]<<" " ;
  }

  return -1;
}

