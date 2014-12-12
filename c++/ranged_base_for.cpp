    http://www.cprogramming.com/c++11/c++11-ranged-for-loop.html
    
    // Strings, arrays, and all STL containers can be iterated over with the new range-based for loop already.
    
    map<int, string> m;
    m[3] = "i am 26 now";
    m[8] = "i will be 27 tomorrow";
    
    for (auto baby_m : m) {
        cout<<baby_m.first<<endl;
    }
    
    int arr[] = {1,2,3,4,5};
    for (auto i : arr) {
        cout<<i<<endl;
    }
    
    string str = "i will be 27 tomorrow";
    for (auto s : str) {
        cout<<s<<endl;
    }
    
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    for (auto& i : vec) {
        i++;
    }
