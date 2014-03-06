#include <iostream>

using namespace std;

#define N 8

bool checkValid(int a[],int row, int col){

  for(int i = 0;i<row;i++){
    int diff = col - a[i];
    if( diff == 0 || diff == i-row || diff == row - i)
      return false;
    
  }

  return true;
  
}

void arrange(int a[]){
  int rowNum = 0;
  int start_pos = 0;
  
  while(rowNum<8){

    for(int col = start_pos;col<N;col++){                                                                                                                                                                                                                                                                                                                                                                                                                                   
   
      if(checkValid(a,rowNum,col)){
	a[rowNum] = col;
	start_pos = 0;
	break;
      }

    }

    if(a[rowNum] == -1){
      rowNum--;
      start_pos = a[rowNum] +1;
      a[rowNum] = -1;
      continue;

    }
    
    rowNum++;
  }

}


int main(){
  
  int a[N];

  for(int i = 0;i<N;i++){
    a[i] = -1;
  }

  arrange(a);

  for(int i =0;i<N;i++){

    cout<<a[i]<<endl;

  }

}
