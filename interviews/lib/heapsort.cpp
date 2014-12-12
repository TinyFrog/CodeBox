#include<iostream>

using namespace std;
#define ARR_LEN 1000000

int left (int i) {return 2*i;}
int right (int i){return 2*i+1;}

int heap_size;

void MaxHeapify(int ind, int a[]){
    int l = left(ind);
    int r = right(ind);
    int largest = 0;
    
    if(l<= heap_size && a[l]>a[ind])
        largest = l;
    else
        largest = ind;
    
    if(r<=heap_size && a[r]>a[largest])
        largest = r;
    
    if(largest != ind){
        int tmp = a[largest];
        a[largest] = a[ind];
        a[ind] = tmp;
        MaxHeapify(largest,a);
        
    }
}

void BuildMaxHeap(int a[]){
    heap_size = ARR_LEN;
    for(int k = heap_size/2;k>=1;k--){
        MaxHeapify(k,a);
    }
}

void heapsort(int a[]){
    BuildMaxHeap(a);
    for(int k = ARR_LEN; k>=2;k--){
        int tmp = a[k];
        a[k] = a[1];
        a[1] = tmp;
        heap_size--;
        MaxHeapify(1,a);
    }
}

void main(){
    srand(time(0));
    int a[ARR_LEN+1];
    
    for(int k =1;k<=ARR_LEN;k++){
        a[k] = rand()%100+1;
    } 
    
    heapsort(a);
    
    for(int k =1;k<=ARR_LEN;k++){
        cout<<a[k]<<" " ;
    } 
}
