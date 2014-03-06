#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;


class data{
public:
  data(){}
  data(int n,int h,int w):num(n),ht(h),wt(w){}
  int num;
  int ht;
  int wt;

};

int findLCS(vector<data*>& wvec, vector<data*>& hvec, int i, int j, list<data*> l){

  if(i == wvec.size() || j == hvec.size()){
    list<data*>::iterator iter;
    for(iter = l.begin(); iter!=l.end();++iter)
      //cout<<"("<<(*iter)->ht<<","<<(*iter)->wt<<") ";
      cout<<(*iter)->num<<" ";
    cout<<endl;

    return 0;

  }

  if(wvec[i]->num == hvec[j]->num){
    l.push_back(wvec[i]);

    return findLCS(wvec,hvec,i+1,j+1,l) + 1;

  }
  else
    return max( findLCS(wvec,hvec,i+1,j,l), findLCS(wvec,hvec,i,j+1,l) ); 
 
}

bool compareHt(data* d1, data* d2){

  return d1->ht>d2->ht;

}

bool compareWt(data *d1, data* d2){
  return d1->wt>d2->wt;
}

int main(){

  vector<data*> vec;
  vec.push_back(new data(1,55,86));
  vec.push_back(new data(2,70,120));
  vec.push_back(new data(3,66,90));
  vec.push_back(new data(4,55,152));
  vec.push_back(new data(5,60,95));
  vec.push_back(new data(6,59,110));

  sort(vec.begin(), vec.end(),compareWt);
  vector<data*> wv =  vec;
    
  vector<data*>::iterator iter;
  for(iter = wv.begin(); iter!=wv.end();++iter)
    //cout<<"("<<(*iter)->ht<<","<<(*iter)->wt<<") ";
    cout<<(*iter)->num<<" ";
  cout<<endl;


  sort(vec.begin(), vec.end(),compareHt);
  vector<data*> hv = vec;

  for(iter = hv.begin(); iter!=hv.end();++iter)
    //cout<<"("<<(*iter)->ht<<","<<(*iter)->wt<<") ";
    cout<<(*iter)->num<<" ";
  cout<<endl;

  list<data*> l;

  cout<<findLCS(wv,hv,0,0,l)<<endl;

  
 


}






