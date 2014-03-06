#pragma once

#include <string>

using namespace std;

string getBinaryFormat(int num){
  string ret ="";
  
  int k=0;

  while(k<32){
    if(1<<k&num) ret += '1';
    else         ret += '0';
    //num = num/2;
    k++;
  }


  int i = 0;
  int j = ret.size()-1;

  while(i<j){
    char tmp  = ret[i];
    ret[i] = ret[j];
    ret[j] = tmp;
    i++;
    j--;
  }

  return ret;

}
