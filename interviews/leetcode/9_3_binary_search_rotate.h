//
//  9_3_binary_search_rotate.h
//  Hacker
//
//  Created by Shaobo Sun on 9/14/13.
//  Copyright (c) 2013 Shaobo. All rights reserved.
//

#ifndef Hacker___3_binary_search_rotate_h
#define Hacker___3_binary_search_rotate_h


int binary_search_rotate(int* arr, int array_length, int target){
    int min = 0;
    int max = array_length - 1;
    
    int mid = -1;
    while(min<=max){
        mid = (min+max)/2;
        if(arr[mid] == target){
            return mid;
        }
        
        if(target > arr[mid]){
            if(target > arr[max] &&  arr[max]>arr[mid]){ // it means from mid to max, it's linear!
                max = mid-1;
            }else
                min = mid+1;
            
        }else{ // arr[mid] < target, should go right
            if(target < arr[min] && arr[min]<arr[mid]){
                min = mid+1;
                
            }else
                max = mid -1;
            
        }
    }
    
    return -1;
}

#endif
