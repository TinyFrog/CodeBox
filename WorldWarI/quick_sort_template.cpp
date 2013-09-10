#include <iostream>
#include <string>
#include <time.h>

using namespace std;

#define LEN 1000000

#define CUTOFF 2

int randInt(int small, int large){
  if(small == large)
    return small;

  if(small > large){
    int tmp = small;
    small = large;
    large = tmp;
  }
  
  return large - rand()%(large-small+1);

}

template <class T>
void myswap(T& a, T& b){

  T tmp = a;
  a = b;
  b = tmp;

}

template <class T>
void insertion_sort(T a[]){

  for(int i = 1; i<LEN; i++){

    int j = i;
    T key = a[i];

    while(j>0 && a[j-1]>key){
      a[j] = a[j-1];
      j--;
    }
    
    a[j] = key;
  }

}


template <class T>
void quicksort(T a[],int l, int r){

  //if(l>=r)
  // return;

  if(r-l<CUTOFF)
    return;

  int i = l-1;
  int j = r+1;
    
  
  myswap(a[randInt(l,r)],a[l]); 
  //int rand = randInt(l,r);
  //T tmp = a[rand];
  //a[rand] = a[l];
  //a[l] = tmp;
  

  int sentinel = a[l];

  while(true){
    do{i++;}while(a[i]<sentinel);
    do{j--;}while(a[j]>sentinel);
    if(i>=j)break;

    myswap(a[i],a[j]);
  }

  quicksort(a,l,j);
  quicksort(a,j+1,r);
}

int diff_ms(timeval t1, timeval t2)
{
  return (t1.tv_sec - t2.tv_sec) * 1000+ 
           (t1.tv_usec - t2.tv_usec)/1000;
}



int main(){

  int arr[LEN];

  srand(time(0));

  timeval start,end;
  

  for(int k =0;k<LEN;k++)
    arr[k] = k;

  gettimeofday(&start,NULL);
  quicksort(arr,0,LEN-1);
  insertion_sort(arr);

  gettimeofday(&end,NULL);

  int diff = diff_ms(end,start);
  cout<<diff<<endl;
  //for(int k = 0; k<LEN;k++)
  //  cout<<arr[k]<<" ";


  getchar();

  return -1;
}
