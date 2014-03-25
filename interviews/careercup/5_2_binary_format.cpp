#include <iostream>
#include <string>
#include <list>
#include "binary.h"

using namespace std;

int getInt(int& i,int index,string a){

  float multi = 0.1;

  list<int> l;

  for(i = index; a[i]!='.'&&i<a.size(); i++){
    char c = a[i];
    int j = (c-48);
    if(j>10||j<0){
      cout<<"ERROR"<<endl;
      return -1;
    }
      
    l.push_back(j);
    multi *= 10;
  }

  int ret = 0;
  while(!l.empty()){
    ret += l.front()*multi;
    multi /= 10;
    l.pop_front();
  }

  return ret;
}

void printBinary(string a){
  
  string res = "";

  int i = 0;

  int part_a = getInt(i,0,a);
  //cout<<part_a<<endl;
  res += getBinaryFormat(part_a);

  i++;
  int part_b = getInt(i,i,a);
  //cout<<part_b<<endl;

  if(part_b)
    res += '.'+ getBinaryFormat(part_b);
    
  cout<<res<<endl;
}


int main(){
  string a = "13.32";

  if(a[1]!='.')
    cout<<"sadfdsaf"<<endl;
  
  printBinary(a);


  return -1;

}
