#include <iostream>
#include <string>

using namespace std;

string single_digit[10] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};

string ten[10] = {"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};

string ten_digit[10] = {"","","Twenty","Thirty","Fourty","Fifty","Sixty","Seventy","Eighty","Ninety"};

string hundred = "Hundred";

string thousand = "Thousand";


string getThous(int thous){

  string res;

  if(thous){

    if(thous/100){
      
      res += single_digit[thous/100]+" "+hundred + " ";
	

      //pay attention here
      if(thous!=100)
	res+="and ";

      thous %= 100;
      
    }

    if(thous/10){
      if(thous/10>1){ //2,3,4,5.....on ten digit
	
	res+= ten_digit[thous/10]+" ";
	if(thous%10)
	  res+= single_digit[thous%10]+" ";

      }
      else{

	res+= ten[thous%10] + " ";

      }

    }
    else{
      //Zero is a special case! Check here
      if(thous)
        res += single_digit[thous];

    }

  }

  return res;


}


string getPhrase(int num){

  if(num==0)
    return "Zero";

  string res = "";

  int g_thous = num / 1000;
  int l_thous = num % 1000;

  if(g_thous){

    //cout<<"dsaf"<<endl;
    res += getThous(g_thous) + "Thousand"+" ";
    if(l_thous!=0)
      res+= ",";

  }

  if(l_thous){

    res += getThous(l_thous);

  }

  return res;


} 

int main(){



  int i = 90007;

  cout<<getPhrase(i)<<endl;

  return -1;



}


