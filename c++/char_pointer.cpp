char* a = "foo bar";
while(*a != ' '){
    cout<<*a<<endl;
    a++;
}
while(*a != '\0'){
    cout<<*a<<endl;
    a++;
}

char* a = "foo bar";
for(int i = 0; i<strlen(a);a++){
    cout<<a[i]<<endl;
}

// how can we do assignment by char*
// *pointer can be left-value!!!
char a[] = "abcd";
char* b = a;
b++;
*b = 'f';

cout<<a<<endl;


// this is wrong: 'a' needs to be large enough to hold b, otherwise EXC_BAD_ACCESS
char* a = "i eat double cheeseburger today";
char* b = new char[8];

strcat(a,b);
