#include <iostream>
#include <vector>

using namespace std;

int a[4] = {25,10,5,1};
//int count[4] = {0,0,0,0};

void cents(int N, vector<int> count,int curr){

  if(N==0){
    for(int i = 0;i<4;i++)
      cout<<count[i]<<" ";

    cout<<endl;
    return;

  }
  if(a[curr]<=N){
    while(N % a[curr]>0 || N == a[curr]){
      count[curr]++;
      cents(N - a[curr],count,curr+1); // it's wrong here, first parameter
      N -= a[curr];
    }
  }
  else{
    cents(N,count,curr+1);
    
  }
  //if(N>0)//sth left
    
}



int main(){

  vector<int> myvec;
  myvec.push_back(0);
  myvec.push_back(0);
  myvec.push_back(0);
  myvec.push_back(0);

  cents(51,myvec,0);

}
