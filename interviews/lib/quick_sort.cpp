#include <iostream>
#include <stdlib.h>

using namespace std;

#define LEN 20

void quicksort(int a[], int l, int r)
{

  if(l>=r) // 1
    return;

  int i = l;// 2
  int j = r+1;
  int sentinel = a[l]; 

  while(true){
    do{i++;}while(a[i]<sentinel && i<=r);
    do{j--;}while(a[j]>sentinel);
    if(i>=j)break;
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
  }

    int tmp = a[l];
    a[l] = a[j];
    a[j] = tmp;

  quicksort(a,l,j-1);
  quicksort(a,j+1,r);

}  

int main(){

  int arr[LEN];

  srand(time(0));
  for(int k =0;k<LEN;k++){
    arr[k] = rand()%100+1;
    cout<<arr[k]<<" ";
  }

  cout<<endl;

  quicksort(arr,0,LEN-1);

  for(int k =0;k<LEN;k++){
    cout<<arr[k]<<" " ;
  }

  getchar();


}
