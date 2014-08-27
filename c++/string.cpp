// char cannot be initialized with empty ''
// this is wrong:
char c = '';

// the line below is wrong. c++ is quote-sensitive
string s = '';

// this is valid:
string s = "";

// to convert integer to string
int i = 115;
string s = "";
s += to_string(i);
// s is "115"

