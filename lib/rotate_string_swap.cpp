#include <iostream>
#include <string>

using namespace std;

void swap(string& str, int len, int i, int j){

  for(int k = 0; k<len; k++){
    char tmp = str[i+k];
    str[i+k] = str[j-len+1+k];
    str[j-len+1+k] = tmp;
  }

}

void permute(string& str, int len, int i, int j){

  if(len > j- i +1) {
    cout<<"cannot rotate"<<endl;
    return;
  }
  
  if(i == j) return;

  if(len > j- i +1 - len){

    swap(str,j - i + 1 - len, i, j);
    permute(str, len -(j-i+1-len), i + (j-i+1-len), j );//key part

  }
  else{
    swap(str,len,i,j);
    if(len < j-i+1-len)
      permute(str,len,i,j-len);
  }

}


int main(){

  string a = "abcdefg";

  permute(a,4 ,0,a.size()-1);

  cout<<a<<endl;

  return -1;
}
