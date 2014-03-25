#include <iostream>


using namespace std;

// ---------
// | 0  0  0
// | 0  0  0
// | 0  0  0
//
//
int a[3][3] = {0};

//who = 1 or 2
void move(int i, int j, int who){

  if(a[i][j] == 0 )
    a[i][j] = who;
  else
    cout<<"you cannot make a move here"<<endl;

}

void clear(){
  
  for(int i = 0; i<3;i++)
    for(int j = 0;j<3;j++)
      a[i][j] = 0;

}

void print(){

  cout<<"----------------"<<endl;
  cout<<a[0][0]<<" "<<a[0][1]<<" "<<a[0][2]<<endl;
  cout<<a[1][0]<<" "<<a[1][1]<<" "<<a[1][2]<<endl;
  cout<<a[2][0]<<" "<<a[2][1]<<" "<<a[2][2]<<endl;
  cout<<"----------------"<<endl;

}

int check(int i, int j,int who,int count){
  
  if(i<0||i>=3||j<0||j>=3)
    return 0;
  
  if(a[i][j] == who)
    return 1;

  

}

bool isWon(int i, int j, int who){
  
  //int count = 0;
  //bool 
  //for(int k = 0;k<3;k++)
  //  for(int j = 0;j<3;j++)
  //    a[k]
  


}


int main(){

  cout<<a[2][2]<<endl;
  
  return -1;

}
