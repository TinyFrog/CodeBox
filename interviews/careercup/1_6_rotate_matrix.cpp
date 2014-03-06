#include <iostream>

using namespace std;

#define N 5

enum direction{RIGHT,LEFT};

void rotate(int a[][N], int dir){

  int row = N/2;
  int col = N/2 + N%2;

  for(int i =0; i<row;i++){
    for(int j = 0;j<col;j++){
      int tmp = a[i][j];
      int p = i;
      int q = j;
      int k = 0;
      if(dir){//left
	while(k<3){
	  a[p][q] = a[q][N-p-1];
	  //point 2
	  int hero = p;
	  p = q;
	  q = N-hero-1;
	  k++;
	}
	a[N-j-1][i] = tmp;
      }
      else{
	while(k<3){
	  a[p][q] = a[N-q-1][p];
	  int hero = p;
	  p = N-q-1;
	  q = hero;
	  k++;
	}
	a[j][N-i-1] = tmp;
      }
      cout<<"sdf"<<endl;

    }
  }
}

int main(){

  srand(time(0));
  int a[5][5];

  for(int i =0; i<N;i++){
    for(int j = 0;j<N;j++){
      a[i][j] = rand()%10+1;
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }

  cout<<endl;

  rotate(a,static_cast<int>(RIGHT));

  for(int i =0; i<N;i++){
    for(int j = 0;j<N;j++)
      cout<<a[i][j]<<" ";
    cout<<endl;
  }

  getchar();

  return -1;

}
