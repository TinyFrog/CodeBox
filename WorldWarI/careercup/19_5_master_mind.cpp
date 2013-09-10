#include <map>
#include <string>
#include <iostream>

using namespace std;

map<char,int> m;

char color[4] = {'R','G','Y','B'}; 

string answer;
string guess;

int hit = 0;
int pseudo_hit = 0;

int answer_count[4] = {0};
int guess_count[4] = {0};


void generate(){

  for(int i =0;i<4;i++){
    int r = rand()%4;
    answer+= color[r];
    answer_count[r]++;

  }

}

void match(){

  for(int i = 0;i<4;i++){
    if(answer[i] == guess[i]){
      hit++;
      answer_count[i]--;
    }
    else{
      guess_count[m[guess[i]]]++;
    }

  }
  
  for(int j = 0;j<4;j++){
    while(guess_count[j]>0&&answer_count[j]>0){
      guess_count[j]--;
      answer_count[j]--;
      pseudo_hit++;
    }

  }

}

int main(){

  m.insert(pair<char,int>('R',0));
  m.insert(pair<char,int>('G',1));
  m.insert(pair<char,int>('Y',2));
  m.insert(pair<char,int>('B',3));

  srand(time(0));

  generate();

  cout<<answer<<endl;

  guess = "YGGB";

  cout<<guess<<endl;
  
  match();

  cout<<"hit is "<<hit<<" "<<"pseudo hit is "<<pseudo_hit<<endl;


}
