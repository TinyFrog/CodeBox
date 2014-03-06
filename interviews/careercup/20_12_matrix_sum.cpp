#include <iostream>
#include <vector>

using namespace std;

#define N 5

int maxvalue_final = 0;
vector<int> r_final;
vector<int> c_final;


//good job ssb!!!

void findMax(int a[][N],int check, int r, int c,vector<int> row_vec, vector<int> col_vec,int maxvalue){
  //check is used to determine to calculate row or col

  if(r>=N||c>=N)
    return;

  int positive_sum = 0;
  int reg_sum = 0;

  if(check){
    for(int i = 0;i<row_vec.size();i++){
      reg_sum += a[row_vec[i]][c];
    }
    if(reg_sum>=0){
      col_vec.push_back(c);
      maxvalue += reg_sum;
    }

  }else{
    for(int i = 0;i<col_vec.size();i++){
      reg_sum += a[r][col_vec[i]];
    }
    if(reg_sum>=0){
      row_vec.push_back(r);
      maxvalue += reg_sum;
    }

  }


  
  vector<int> tmp_r;
  vector<int> tmp_c;

  tmp_r.clear();
  tmp_c.clear();

  // the new row/col added this time has a greater value than the previous one
  // update the two vector 
  if(check){    
    for(int i = 0;i<=r;i++){
      if(a[i][c]>=0){
	positive_sum += a[i][c];
	tmp_r.push_back(i);
      }

    }

    if(positive_sum>=maxvalue){
      maxvalue = positive_sum;
      tmp_c.push_back(c);
      
      row_vec = tmp_r;
      col_vec = tmp_c;

    }

 
  }
  else{
    
    for(int i = 0;i<=c;i++){
      if(a[r][i]>=0){
	positive_sum += a[r][i];
	tmp_c.push_back(i);
      }
    }

    if(positive_sum>=maxvalue){
      maxvalue = positive_sum;

      tmp_r.push_back(r);
      row_vec = tmp_r;
      col_vec = tmp_c;

    }

  }

  if(r==N-1&&c==N-1){
    if(maxvalue > maxvalue_final){
      maxvalue_final = maxvalue;
      r_final = row_vec;
      c_final = col_vec;


    }

  }

  findMax(a,0,r+1,c,row_vec,col_vec,maxvalue);
  findMax(a,1,r,c+1,row_vec,col_vec,maxvalue);

}


int main(){

  srand(time(0));

  int a[N][N];

  for(int i = 0;i<N;i++){
    for(int j = 0;j<N;j++){
      a[i][j] = rand()%10 - rand()%10;

      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }

  cout<<endl;

  vector<int> c;
  vector<int> r;

  findMax(a,0,0,0,r,c,0);

  cout<<maxvalue_final<<endl;
  for(int i = 0;i<r_final.size();i++){
    
    cout<<r_final[i]<<" ";

  }

  cout<<endl;
  
  for(int i = 0;i<c_final.size();i++){
    
    cout<<c_final[i]<<" ";

  } 


}
