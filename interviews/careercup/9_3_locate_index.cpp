#include <iostream>

using namespace std;

int binary_search(int a[],int size ,int value){

  int min = 0;
  int max = size - 1;
  int mid = -1;

  while(min<=max){

    mid = min + (max-min)/2;
    if(a[mid] > value){
      if(a[min]>value)
	min = mid+1;
      else 
	max = mid -1;
    }

    else if(a[mid] < value){
      if(a[max]<value)
	max = mid -1;
      else 
	min = mid+1;
    }

    else{

      return mid;
      break;
    }


  }

  return -1;


}


int main(){

  int a[] = {15,16,19,20,25,1,3,4,5,7,10,14};


  cout<<binary_search(a,sizeof(a)/sizeof(int),13)<<endl;

  
}
