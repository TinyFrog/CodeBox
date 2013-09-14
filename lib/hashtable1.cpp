#include <list>
#include <iostream>

using namespace std;

class Fuck{


};

template <class Obj>
class HashEntry{

public:
  HashEntry(int k, Obj* v){ key = k; value = v;}
  ~HashEntry(){cout<<"I WAS KILLED!"<<endl;}
  Obj* getValue(){return value;}
  int  getKey(){ return key; }

private:
  int key;
  Obj* value;

};

template <class Obj>
class HashTable{

public:
  HashTable(int tableSize){this->tableSize = tableSize; table = new list<HashEntry <Obj>*>[tableSize];}
  ~HashTable();
  void put(int key, HashEntry<Obj>* a);
  HashEntry<Obj>* get(int key);

private:
  int hashFunction(int key){ return key % tableSize;}
  int tableSize;
  list<HashEntry<Obj>*>* table;

};

template <class Obj>
HashTable<Obj>::~HashTable(){

  for(int i = 0; i<tableSize; i++)
    table[i].clear();//test point 2, whether it will call the the dtor of A

  delete table;

}

template <class Obj>
void HashTable<Obj>::put(int key, HashEntry<Obj>* a){

  //test point 3, typename
  typename list<HashEntry<Obj>*>::iterator iter;
  
  int slot = hashFunction(key);

  for( iter = table[slot].begin(); iter != table[slot].end(); ++iter){


    if( (*iter)->getKey() == key){
      //test point 1: check key or check pointer??
      cout<<"It exists, cannot put it in hashTable"<<endl;
      return;
    }

  }

  table[slot].push_back(a);

}

template <class Obj>
HashEntry<Obj>* HashTable<Obj>::get(int key){

  typename list<HashEntry<Obj>*>::iterator iter;

  int slot = hashFunction(key);

  for( iter = table[slot].begin(); iter != table[slot].end(); ++iter){

    if( (*iter)->getKey() == key){
      //test point 1
      cout<<"CAONIMA, CAONIMA"<<endl;
      return (*iter); 
    }

  }



}


int main(){


  HashTable<Fuck> hashTable(5);
  
  hashTable.put(7, new HashEntry<Fuck>(7, new Fuck()));

  hashTable.put(7,new HashEntry<Fuck>(7, new Fuck()));

  hashTable.get(7);

}

