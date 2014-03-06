#include <iostream>
#include <string>

using namespace std;

string ReplaceSpace(string& s){

  string newone = "";

  for(int k =0; k<s.size();k++){
    if(s[k] == ' ')
      newone += "%20";
    else 
      newone += s[k];
  }

  return newone;
}

int main(){

  string sb = "sdaf dsfa s3";
  cout<<ReplaceSpace(sb)<<endl;
  getchar();
  return -1;

}
