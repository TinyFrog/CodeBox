#include <iostream>
#include <string>

using namespace std;

bool isSubstring(string s, string l){

  if(!s.size() || !l.size()) return false;

  if(s.size()>l.size()){
    string tmp = s;
    s = l;
    l = tmp;
  }

  int j =0;
  for(int i = 0;i<l.size();i++){
    if(l[i] == s[j])
      j++;
    else 
      j=0;

    if(j == s.size())
      return true;
  }
  
  return false;
}

int main(){
  string a = "asabcd";
  string b = "asa";

  if(isSubstring(a,b))
    cout<<"Hell Yeah!"<<endl;

  getchar();
  return -1;


}

