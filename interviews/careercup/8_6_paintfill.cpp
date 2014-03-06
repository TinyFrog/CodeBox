#include <iostream>

#define N 4

using namespace std;

void paintfill(int** a,int i, int j, int target, int replace){

  if(i<0 || i >=N || j<0 ||j>=N )
    return;

  if(a[i][j] == target){
    a[i][j] = replace;

    paintfill(a,i-1,j,target,replace);
    paintfill(a,i+1,j,target,replace);
    paintfill(a,i,j-1,target,replace);
    paintfill(a,i,j+1,target,replace);


  }

}


int main(){

  srand(time(0));

  int** a = new int*[N];

  for(int i = 0;i<N;i++)
    a[i] = new int[N];

  for(int i = 0;i<N;i++){
    for(int j = 0;j<N;j++){

      a[i][j] = rand()%2;
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;

  paintfill(a,2,2,0,3);

  for(int i = 0;i<N;i++){
    for(int j = 0;j<N;j++){
    
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }

}
