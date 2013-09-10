#include <iostream>
#include <string>

using namespace std;

int findNextNonEmpty(string s[],int size,int curr){
  int next = -1;
  
  for(int i = curr;i<size;i++){
    if(!s[i].empty())
      return i;
  }

  return next;


}

int locateIndex(string s[],int size,string target){

  //int index = -1;

  int min = 0;
  int max = size -1;
  int mid = -1;

  int next = -1;
  while(min<=max){


    mid = min + (max - min)/2;
    if(s[mid].empty()){
      next = findNextNonEmpty(s,size,mid);
      if(next == -1)
	return -1; //no non-empty subsequent string in that array 
      if(s[next] == target)
	return next;
    }
    else 
      next = mid;

    if(target.compare(s[next])>0) min = mid+1;
    else if(target.compare(s[next]) <0) max = mid-1;
    else 
      return mid;
  }

  return -1;
}



int main(){
  
  string s[] = {"at","","","","","","","","","","","","ball","","","","","","cat"};



  cout<<locateIndex(s,sizeof(s)/sizeof(string),"as")<<endl;


  
}
