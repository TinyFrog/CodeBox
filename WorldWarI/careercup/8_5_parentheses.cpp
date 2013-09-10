#include <iostream>
#include <string> 

using namespace std;

void recur(int lp, int rp, string res){
  
  if(rp == 0){
    cout<<res<<endl;
    return;
  }

  if( lp != 0 )
    recur(lp-1,rp,res+"(");

  if( lp < rp)
    recur(lp,rp-1,res+")");

}


int main(){

  int N = 10
;

  recur(N,N,"");

  return -1;


}
