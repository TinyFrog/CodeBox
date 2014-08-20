// create a vector by passing another
vector<int> new_(original);
vector<int> foo {25,75,100};

// two dimensions vector
vector<vector<int> > vec_1;
vector<int> vec_2;
vec_2.push_back(3);
vec_1.push_back(vec_2);

cout<<vec_1[0][0];

// push_back while iterating vector will BREAK your iterator
// http://stackoverflow.com/questions/3443434/appending-to-a-vector-while-iterating-over-it
// http://stackoverflow.com/questions/5638323/modifying-a-data-structure-while-iterating-over-it


for(vector<Foo>::iterator i = vec.begin(); i != vec.end();++i){   
    if(vec->condition)
        AppendToVec(vec); // this is wrong
}

