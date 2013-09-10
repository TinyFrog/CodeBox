#include <iostream>

using namespace std;

int binary_search(int* arr, int size, int value){

  int index = -1;
  int min, max;
  min = 0;
  max = size -1;

  while(min <= max){
    
    int mid = min+(max-min)/2;
    if(value > arr[mid]){`     
      min = mid + 1;
    }
    else if(value < arr[mid]){
      max = mid - 1;
    }
    else{
      index = mid;
      break;
    }
  }

  return index;

}


int main(){
  
  const int arr_size = 11;
  int arr[arr_size]= {2,4,6,7,8,12,15,19,22,30};
  
  int pos = binary_search(arr,arr_size,31);

  if( pos == -1 )
    cout<<"aiyo, meiyou!"<<endl;
  else
    cout<<"it's located in "<<pos<<" in arr"<<endl;

  return -1;

}
