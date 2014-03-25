#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> vec;

int counter = 0;


void getPaths(int right, int down, string s){
  
  if(right == 1 && down == 1){
    vec.push_back(s);
    counter++;
  }

  if(right == 0 || down == 0)
    return;
  
  string rightStr = s + "right ";
  string downStr = s + "down ";

  getPaths(right-1,down,rightStr);
  getPaths(right, down-1,downStr);
  
}


int main(){

  string s = "";
  getPaths(2,2,s);

  vector<string>::iterator iter;
  cout<<"There is "<<counter<<" possible paths"<<endl;
  for(iter = vec.begin();iter!=vec.end();iter++){

    cout<<(*iter)<<endl;
  }

  return -1;

}
