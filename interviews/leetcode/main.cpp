//
//  main.cpp
//  Hacker
//
//  Created by Y.CORP.YAHOO.COM\ssb on 1/26/13.
//  Copyright (c) 2013 Shaobo. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <vector>
#include <math.h>
#include <map>
#include <sstream>
#include <algorithm>

//#include "1_1.h"
//#include "1_3.h"
//#include "interleaving_string.h"
//#include "8_6_subsets.h"
#include "utils.h"
//#include "9_3_binary_search_rotate.h"
//#include "leetcode_sum_root_to_leaf_numbers.h"
#include "leetcode_path_sum.h"
#include "leetcode_flatten_binary_tree_to_linked_list.h"
#include "leetcode_two_sum.h"
#include "leetcode_palindrome_number.h"
#include "leetcode_jump_game_ii.h"
#include "leetcode_anagrams.h"
#include "leetcode_interleaving_string.h"
#include "leetcode_decode_ways.h"
#include "leetcode_minimum_path_sum.h"
#include "leetcode_restore_ip_addresses.h"
#include "rocketfuel.h"
#include "leetcode_copy_list_with_random_pointer.h"

using namespace std;
/*
const int length = 26;

void insertionSort(int a[]){
    
    for(int i = 1; i<length; i++){
        
        int j = i;
        int placeHolder = a[i];
        
        while(j>0 && a[j-1]>placeHolder){
            a[j] = a[j-1];
            j--;
        }
        
        a[j] = placeHolder;
    }
    
}

int parseChar(char c){
    int ascii = static_cast<int>(c);
    if (ascii >= 65 && ascii <=90) {
        return ascii-65;
    }
    if (ascii >= 97 && ascii <=122) {
        return ascii-97;
    }
    
    return -1;
    
}/*
/*
int main(int argc, const char * argv[])
{
    string line;
    
    int letter[length];

    ifstream myfile("/Users/ssb/Facebook/beautiful_stringstxt.txt");
    
    if (myfile.is_open())
    {
        int lines = 0;
        int currentLine = 1;
        bool firstline = true;
        while ( myfile.good() )
        {

            getline (myfile,line);
            
            if (firstline == true){
                firstline = false;
                lines = std::stoi(line);
                continue;
            }
            
            if( currentLine > lines || currentLine > 50){
                break;
            }
            
            for ( int i = 0 ; i < line.length(); i++)
            {
                if(i>=500){
                    break;
                }
                
                int retAscii = parseChar(line[i]);
                if (retAscii != -1) {
                    letter[retAscii]++;
                }
                
            }
            
            insertionSort(letter);
            
            int sum = 0;
            for(int i =0; i< length;i++){
                sum += (i+1) * letter[i];
            }
            
            // clean up the array
            for(int i =0; i< length;i++){
                letter[i] = 0;
            }
            
            cout<<"Case #"<<currentLine<<":"<<" "<<sum<<endl;
            
            currentLine++;

        }
        myfile.close();
    }

    
    return 0;
}*/



class StringTest{
    
public:
    void setString(string& foo){
        bar = foo;
    }
    
    string getString(){
        return bar;
    }
  
    
private:
    string bar;
    
    
};
/*
int main(){
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n5(5);
    TreeNode n6(6);
    TreeNode n7(7);
    TreeNode n8(8);
    TreeNode n9(9);

    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.right = &n6;
    n4.left = &n7;
    n5.right = &n8;
    n6.left = &n9;
    
    bfs(&n1);
    
}*/



char* replace_spaces_in_place(char* origin){
    char* iter = origin;
    size_t origin_length = strlen(origin);
    
    int length_increased = 0;
    
    while(*iter != '\0'){
        if(*iter == ' '){
            length_increased += 2;
        }
        iter++;
    }
    
    iter--; //end
    char* char_increased = new char[length_increased];
    strcat(origin,char_increased);
    
    size_t total_length = origin_length + length_increased;
    size_t total_length_count = total_length-1;
    for(size_t i = origin_length -1 ; i>=0; i--){
        
        if(origin[i] == ' '){
            origin[total_length_count--] = '0';
            origin[total_length_count--] = '2';
            origin[total_length_count--] = '%';

            
        }else{
            origin[total_length_count--] = origin[i];

        }
        
    }
    
    return origin;
    
    
    
}


int fibonacci(int n) {
    
    if (n == 1) {
        return 1;
    }
    
    if (n == 2) {
        return 2;
    }
    
    return fibonacci(n-1) + fibonacci(n-2);
}


long factorial(int m) {
    long factorial = 1;
    for (int i =m; i>0; i--) {
        factorial *= i;
    }
    
    return factorial;
}

long calulate_combination (int m, int n) {
    // This might not be true
    // But works for this problem, when no '2' is present, only one way to climb
    if (m == 0) {
        return 1;
    }
    
    long numerator = 1;
    for (int k = m; k>0; k--) {
        numerator *= n-k+1;
    }
    
    return numerator / factorial(m);
}

int climbStairs(int n) {
    if (n == 0) {
        return 0;
    }
    
    // i is the number of appearance of '2'
    int i = 0;
    long total = 0;
    while (2*i <= n) {
        total += calulate_combination(i, n-i);
        i++;
    }
    
    return  total;
}



int main() {

    int f = -3;
    cout<<climbStairs(35)<<endl;
}


#include <iostream>#include <fstream>#include <string> using namespace std;int main () {  string line;  ifstream myfile("example.txt");  if (myfile.is_open())  {    while ( myfile.good() )    {      getline (myfile,line);      cout << line << endl;    }    myfile.close();  }  else cout << "Unable to open file";   return 0; }

