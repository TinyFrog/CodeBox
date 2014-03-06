#include <iostream>

using namespace std;

#define N 10

int a[N] = {0};

void getMaxSumMethod2(){

  int maxsum = 0;
  int sum = 0;

  for(int i = 0;i<N;i++){
    
    sum += a[i];
    if(sum>maxsum)
      maxsum = sum;
    else if(sum<0)
      sum = 0;
      
  }


  cout<<maxsum<<endl;

}


void getMaxSum(){

  int max  =-100;
  int l = 1;
  for(l =1;l<=N;l++){
    
    for(int k = 0;k<N-l+1;k++){
      
      int sum = 0;
      for(int s = k;s<k+l;s++){
	sum += a[s];

      }

      if(sum>max)
	max = sum;

    }

  }

  cout<<max<<endl;


}


int main(){

  srand(time(0));

  for(int i = 0;i<N;i++){
    a[i] = rand()%10 - rand()%10;
    cout<<a[i]<<" ";
  }

  cout<<endl;

  getMaxSum();
  getMaxSumMethod2();

}
