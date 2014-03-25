#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string getSig(string orig){

  int count[26] = {0};
  string sig = "";

  for(int i = 0; i < orig.size(); i++){
    int tmp = orig[i] - 97;
 
    count[tmp]++;

  }

  for(int i = 0;i<26;i++){
    if(count[i]){
      sig += static_cast<char>(i+97) + static_cast<char>(count[i]+48);
      //      sig += count[i]+48;
    }
  }

  return sig;

}

bool compareFunc(string a, string b){

  if(getSig(a).compare(getSig(b)) >=0)
    return true;
  else
    return false;
}


int main(){

  vector<string> vec;
  vec.push_back("dsaf");
  vec.push_back("abcd");  
  vec.push_back("asdf");
  vec.push_back("dbca");


  sort(vec.begin(),vec.end(),compareFunc);

  for(int i = 0; i <4;i++)
    cout<<vec[i]<<" ";

}
