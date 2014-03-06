//cracking the interview 1.2

#include <iostream>
using namespace std;

void reverse(char* str){



}

int main(){
  const int arr_length = 10;
  char abc[arr_length] = "abcd";
  
  char* str = abc;
  char* end = str;
  if(str){
    while(*end)++end;
    end--;
    while(str<end){
      char tmp = *str;
      *str++ = *end;
      *end-- = tmp;
    }
  }



  //This doesn't work!!!!!!!
  //it works only under certain circumstance: the size of the char is exactly same as the array size
  //for(int i = arr_length - 2; i>=0;i--)
  //  reverse[arr_length -i -2] = str[i];
  cout<<abc<<endl;

  return 1;
}

