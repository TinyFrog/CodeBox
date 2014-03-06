#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

//sorting
bool isAnagramBySort(string s1, string s2){
  
  if(s1.size() != s2.size()) return false;

  sort(s1.begin(),s1.end());
  sort(s2.begin(),s2.end());
  
  if(s1 == s2) return true;

  return false;
}

//counting
string getSignature(string s){

  if(s.size() == 0) return NULL;

  const int LEN = 26;
  string sig = "";
  int count[LEN];
  
  for(int k = 0; k < LEN;k++)
    count[k] = 0;

  for(int i = 0; i < s.size();i++)
    count[s[i]-'a']++;

  for(int k = 0; k < LEN;k++){
    if(count[k]){
      stringstream ss;
      ss<<count[k];
      sig += static_cast<char>(k+97) + ss.str();
    }

  }

  return sig;
}

bool isAnagramByCount(string s1, string s2){

  string sig_s1 = getSignature(s1);
  cout<<sig_s1<<endl;
  string sig_s2 = getSignature(s2);
  cout<<sig_s2<<endl;

  return sig_s1 == sig_s2;
}



int main(){

  string s1 ="alfdj";
  string s2 ="djfla";

  if(isAnagramByCount(s1, s2))
    cout<<"Yes!"<<endl;
  else
    cout<<"No!"<<endl;

  getchar();
  
  return -1;
}

  
