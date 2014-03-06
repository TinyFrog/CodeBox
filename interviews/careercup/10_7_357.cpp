#include <iostream>
#include <list>

using namespace std;

list<int> l;


bool checkDup(int value){

  list<int>::iterator it;
  for(it = l.begin();it!=l.end();++it){
    if( (*it)==value )
      return true;
  }
  
  return false;

}



int findKth(int k){

  //array may be working
  list<int>::iterator iter[3];
  //i'm not for sure about this
  //doenst work:(
  //list<int>::iterator* who;
  
  int indicator = 0;

  iter[0] = iter[1] = iter[2] = l.begin();

  int min = 0xFFFFFFFF;
  for(int i = 0;i<k;i++){

    if( (*iter[0])*3 < (*iter[1]) *5){
      min = (*iter[0])*3;
      indicator = 0;
    }
    else{ 
      min = (*iter[1])*5;
      indicator = 1;

    }
    if( (*iter[2])*7 < min ){
      min = (*iter[2])*7;
      indicator = 2;
    }

    
    if(!checkDup(min)){
      l.push_back(min);
    }
    else
      i--;

    ++iter[indicator];

    

  }
  

  return min;


}



int main(){


  l.push_back(1);

  cout<<findKth(120)<<endl;

}
