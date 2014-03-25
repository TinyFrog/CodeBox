#include <iostream>
#include <list>
#include <utility>
#include <map>

using namespace std;

typedef pair<double,double> line;
typedef pair<double,double> point;

typedef map< point, list<point> > hash;
hash m;



int main(){

  line p1(1.5, 2.3);
  point p2(4.1, 3.9);
  point p3(2.232,9.3123);

  list<point> l;
  l.push_back(p2);
  l.push_back(p3);
  
  m.insert( pair<line, list<point> >(p1,l));

  hash::iterator it;

  it = m.find(p1);

  list<point> tmp = (*it).second;
  list<point>::iterator l_it;
  for(l_it = tmp.begin();l_it != tmp.end();++l_it){
    
    cout<<(*l_it).first<<" "<<(*l_it).second<<endl;


  }



}
