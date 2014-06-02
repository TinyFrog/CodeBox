/*
 
 Divide two integers without using multiplication, division and mod operator.
 
 */

#ifndef Hacker_leetcode_devide_two_integers_h
#define Hacker_leetcode_devide_two_integers_h



int divide(int dividend, int divisor) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    bool neg1, neg2;
    neg1 = neg2 = false;
    
    /*
     
     Run Status: Time Limit Exceeded
     
     Last executed input
     2147483647, 2
     Run Status: Time Limit Exceeded
     
     Last executed input
     2147483647, 3
     
     */
    
    
    int original_divident = divident;
    int power = 0
    while(divident/2 > divisor){
        divident /= 2;
        power++;
    }
    
    int counter_1 = 1<< power;
    
    int diff = original_divident - (divident * counter_1);
    
    int counter_2 = 0;
    while(diff> 0) {
        diff -= divisor;
        counter_2++;	
    } 
	
    return counter_1 + counter_2;
    
}

#endif
