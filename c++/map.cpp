// 'find' - using key return vale
mymap.find('a')->second;

// more examples
map<int, int> mymap;
mymap.insert(pair<int,int>(0,31));
mymap.insert(pair<int,int>(1,25));

map<int, int>::iterator it=mymap.find(1);
cout<<it->second<<endl;

// if it does't exist
if ( m.find("f") == m.end() ) {
    // not found
} else {
    // found 
}
