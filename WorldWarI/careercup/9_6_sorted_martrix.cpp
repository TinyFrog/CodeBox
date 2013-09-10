#include <iostream>

using namespace std;

#define N 4

int a[N][N] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

void locateElement(int value, int i, int j){
  
  if(i<0||i>=N||j<0||j>=N)
    return;

  if(value<a[0][0])
    return;


  if(value == a[i][j]){
    cout<<"it's located in "<<i<<" "<<j<<endl;
    return;
  }

  if(value>a[i][j])
    locateElement(value,i+1,j);

 
  else
    locateElement(value,i,j-1);
      

}


int main(){



  Locateelement(11,0,3);
  return -1;




}
