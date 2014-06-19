// String to char*
// http://stackoverflow.com/questions/7352099/stdstring-to-char
std::string str = "string";
const char *cstr = str.c_str();

// String to char
string:char& operator[] (size_t pos);
string:const char& operator[] (size_t pos) const;

// atoi, itoa
int atoi (const char * str);
char *  itoa ( int value, char * str, int base );

string a="789";

for(int i =0; i<3;i++) {      
    cout<<atoi(&a[i])<<endl;
}

/*
output:
789
89
9
*/


// simplest conversion from a char to int:
char a = '4';
int b = a - '0';
