//Cracking the Interview 1.1

#include <iostream>
#include <string>
using namespace std;


int isUnique(string str){
  int checker = 0;
  for(int k =0;k<str.size();k++){
    int p = str[k] - 'a';
    if( (1<<p) & checker ) return 0;
    checker |= (1<<p);
  }
  
  return 1;
}


int main(){
  string str = "daslfjal";
  if(isUnique(str))
    cout<<"It's unique!"<<endl;
  else
    cout<<"Sucker!"<<endl;

  return -1;
}
