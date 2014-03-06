#include <iostream>
#include <string>


//damp->lamp->limp->lime->like



using namespace std;

bool contains(string s){

  //looking up in dic
  return true;

}

void transformWord(string orig, string target, set<int> s){

  set<int>::iterator iter;
  while(!s.empty()){
    for(iter = s.begin();iter!=s.end();iter++){
      string tmp = orig;
      tmp[*iter] = target[*iter];
      //target[*iter]

      if(contains(tmp)){
	s.erase(iter);
	orig = tmp;
	break;
      }
	
    }

    if(iter == s.end())
      break;// not found!!!
  }



}

