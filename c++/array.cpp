// initialize an array
int a[5] = {1,2,3,4,5};

// set all elements to 0
int myArray[10] = {0};

// In C++, an empty initialization list will also initialize every element to 0:
int myArray[10] = {};

// passing array as a parameter
// http://stackoverflow.com/questions/763861/passing-an-array-as-an-argument-in-c

// Get the length of an array 
int S[] = {-1, 0, 1, 2, -1, -4,3,4,5,6,8};
insertion_sort(S);

insertion_sort(int S[]){
    // The length below would be INCORRECT
    // Because the size of S[] is unknown in compile time
    int length = sizeof(S)/size(int);
}

// 2-d array
// http://stackoverflow.com/questions/8767166/passing-2d-array-to-function
int **a = new int*[x];
for (int i = 0; i < x; ++i) {
    a[i] = new int[y];
    for (int j = 0; j<y; j++) {
        a[i][j] = -1;   
    }
}

// passing 2-d array to function
void a(int **a)

// Example a matrix: 26 * 10 
int** intmap = new int*[26];
for(int i =0; i<26; i++)
    intmap[i] = new int[10];
