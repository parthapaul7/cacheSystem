// the storage template  
// you can make custom storage classes by inheriting this class

#include <bits/stdc++.h>
using namespace std;

template <class Key, class Value>
class Storage 
{
private:
    mutex m_mutex;
public:
    Storage(){};
    virtual void insert(Key key, Value value) {
        lock_guard<mutex> lock(m_mutex);
        l_insert(key, value);
    };
    virtual bool isKeyExist(Key key) = 0;
    virtual int pop(Key key) {
        lock_guard<mutex> lock(m_mutex);
        return l_pop(key);
    };
    virtual pair<Value, bool> get(Key key) = 0;
    virtual int size() = 0;
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;

protected: 
    virtual void l_insert(Key key, Value value) = 0;
    virtual int l_pop(Key key) = 0;
};
