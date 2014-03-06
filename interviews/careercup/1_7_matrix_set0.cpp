#include <iostream>

using namespace std;

#define M 5
#define N 7

void SetRowColZero(int a[][N],int i, int j){

  for(int k = 0;k<M;k++)
    a[k][j] = 0;
  for(int k =0;k<N;k++)
    a[i][k] = 0;

}


void SetZero(int a[][N]){
  
  bool ColCheck[M][N];
  for(int i = 0; i<M; i++){
    for(int j = 0; j<N;j++)
      ColCheck[i][j] = false;
  }

  for(int i = 0; i<M;i++){
    for(int j = 0; j<N;j++){
      if(a[i][j] == 0 && !ColCheck[i][j]){
	//to set the ColCheck, if and only if the a[i][j] != 0
	for(int k=i;k<M;k++){
	  if(a[k][j])
	    ColCheck[k][j] = true;
        }

	//let's destroy!
	SetRowColZero(a,i,j);
	break;
      }
    }
  }
}

int main(){

  srand(time(0));
  int a[M][N];
  for(int i = 0; i<M;i++){
    for(int j = 0; j<N;j++){
      a[i][j] = rand()%10;
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }

  cout<<endl;

  SetZero(a);
   
  for(int i =0; i<M; i++){
    for(int j = 0;j<N;j++)
      cout<<a[i][j]<<" ";
    cout<<endl;
  }
  
  getchar();

  return -1;


}
