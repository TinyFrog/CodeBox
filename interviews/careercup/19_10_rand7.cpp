#include <iostream>

using namespace std;


int rand7(){
  while(true){
    int num = 5*(rand() % 5) + rand()%5;
    if(num<21) return num%7;
  }

}


int main(){
  srand(time(0));

  for(int i = 0;i<10;i++)
    cout<<rand7()<<" ";




}
