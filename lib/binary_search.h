#include <iostream>

using namespace std;

int binary_search(int* arr, int size, int value){

  int index = -1;
  int min, max;
  min = 0;
  max = size -1;
  
  //  <= is needed
  // considering arr = {1,5}, value = 5
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
