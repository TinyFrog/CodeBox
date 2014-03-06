#include <iostream>
#include <string>

using namespace std;

void recur(string first, string sec){

  if(sec.size() == 1){
    string final = first + sec;
    cout<<final<<endl;
  }

  for(int i = 0;i<sec.size();i++){

    char tmp = sec[0];
    sec[0] = sec[i];
    sec[i] = tmp;

    //first += sec[0];
    
    recur(first+sec[0],sec.substr(1,sec.size()-1));

  }
  
}


void permute(string orig){


  recur("",orig);


}


int main(){

  string a = "abc";

  permute(a);

  return -1;

}
