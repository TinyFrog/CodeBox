#include <iostream>
#include <string>

using namespace std;

//swap is very stupid!!!

void remove_dup(string& str){

  if(!str.size() || str.size()<2 ) return;

  int counter = 0;
  int tail = 0;

  for(int i =0;i<str.size();i++){
    int j;
    for(j = 0; j<tail;j++){
      if(str[i]==str[j]){
	counter++;
	break;
      }
    }

    if(j == tail)
      str[tail++] = str[i];

  }

  str = str.substr(0,tail);

}


int main(){
  string ssb = "ababababa";

  remove_dup(ssb);

  cout<<ssb;

  getchar();

  return -1;

}
