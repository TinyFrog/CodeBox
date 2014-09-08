/*
  Read from stdin
*/
string input_line;
while(cin) {
    getline(cin, input_line);
    cout << input_line << endl;
};
return 0;


/*
  Read from file
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main () {
    string line;
    ifstream myfile("example.txt");
    if (myfile.is_open()) {
        while ( myfile.good() ) {
            getline (myfile,line);
            cout << line << endl;
        }
        myfile.close();
    } else {
        cout << "Unable to open file";
    }

    return 0;
}
