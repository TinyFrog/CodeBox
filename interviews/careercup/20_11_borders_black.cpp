#include <iostream>


using namespace std;

#define N 13

enum color{WHITE,BLACK};

int max_len = 0;
int row_pos = 0;
int col_pos = 0;

//execellent job!!!!SSB!

bool isBlackBorder(int a[][N],int row,int col, int& len){

  int incr = 0;

  if(a[row][col] == 0)
    return false;
  
  while(row+incr+1<N && col+incr+1<N){
    
    if(a[row][col+incr+1] && a[row+incr+1][col])
      incr++;
    else
      break;

  }

  for(int i = incr;i>0;i--){
    
    int j;
    for(j = 1;j<=i;j++){

      if(a[row+i][col+j] == 0|| a[row+j][col+i] == 0)
	break;
      if(j==i){
	len = i;
	return true;
      }

    }

  }

  return false;

}

void iterateMatrix(int a[][N],int i,int j){

  if(i>=N||j>=N)
    return;

  int len = 0;
  if(isBlackBorder(a,i,j,len)){

    if(len>max_len){
      max_len = len;
      row_pos = i;
      col_pos = j;
    }

  }

  iterateMatrix(a,i+1,j);
  iterateMatrix(a,i,j+1);

}

void paintSth(int a[][N],int i, int j,int len){

  int var;
  
  for(var =0;var<=len;var++){
    a[i+var][j] = 2;
    a[i][j+var] = 2;
    a[i+len-var][j+len] = 2;
    a[i+len][j+len-var] = 2;


  }


}



int main(){

  srand(time(0));

  int a[N][N];

  for(int i = 0;i<N;i++){
    for(int j = 0;j<N;j++){
      a[i][j] = rand()%2;

      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }

  cout<<endl;

  iterateMatrix(a,0,0);

  cout<<max_len<<" "<<row_pos<<" "<<col_pos<<endl<<endl;

  paintSth(a,row_pos,col_pos,max_len);

  for(int i = 0;i<N;i++){
    for(int j = 0;j<N;j++){

      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }

}
