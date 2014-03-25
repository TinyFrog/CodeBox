#include <iostream>
#include <vector>
#include <list>
#include "elapsedtime.h"

using namespace std;

list< vector<int> > l;

void getSubsets(int a[],int i, int N, vector<int> vec){

  if(i==N){
    if(!vec.empty()){
      l.push_back(vec);

      //vec.pop_back();
    }
    
    return;

  }


  getSubsets(a,i+1,N,vec);

  vec.push_back(a[i]);

  getSubsets(a,i+1,N,vec);


}

void getSubsets(int a[],const int N){

  bool b[N];
  for(int i =0;i<N;i++)
    b[i] = false;

  int counter = 0;

  while(true){
   
    //for(int i = 0; i <N;i++){
    //  if(b[i]){
    //	cout<<a[i]<<" ";
    //  }
    //}

    counter++;

    //cout<<endl;
 
    int k = N-1;
    while(k>=0){
      if(!b[k]){
	b[k] = true;
	break;
      }
      else{
	b[k] = false;
	k--;

      }

    }

    if(k<0)
      break;

  }

  cout<<"count = "<<counter<<endl;

}


int main(){

  const int N = 30;

  vector<int> myvec;

  int a[N];

  for(int i = 0; i<N;i++)
    a[i] = i;

  int counter =0;

  timeStart();

  getSubsets(a,N);

  list< vector<int> >::iterator iter;
  for(iter = l.begin(); iter!=l.end();++iter){
    vector<int>::iterator viter;
    //for(viter = (*iter).begin(); viter!=(*iter).end();++viter){
    //  cout<<(*viter)<<" ";
    // }
    counter++;

    //cout<<endl;

  }

  cout<<"sum is "<<counter<<endl;
  cout<<"time is "<<timeElapsed()<<endl;
}
