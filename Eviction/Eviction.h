#ifndef Eviction_Policies
#define Eviction_Policies

#include <bits/stdc++.h>
using namespace std;

template <class Key>
class Eviction
{
public:
    Eviction(){};
    virtual void insert(Key key) = 0;
    virtual pair<Key, bool> evict() = 0;
    virtual void access(Key key) = 0;
    virtual void updateKey(Key key) = 0;
};


#endif