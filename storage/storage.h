// the storage template  
// you can make custom storage classes by inheriting this class

#ifndef storage_h 
#define storage_h

#include <bits/stdc++.h>
using namespace std;

template <class Key, class Value>
class Storage 
{
public:
    Storage(){};
    virtual void insert(Key key, Value value) = 0;
    virtual bool isKeyExist(Key key) = 0;
    virtual int pop(Key key) = 0;
    virtual pair<Value, bool> get(Key key) = 0;
    virtual int size() = 0;
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;
};


#endif