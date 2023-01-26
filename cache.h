
// as we have used map based storage keys should be unique
// if we have duplicate keys it will update the previous value with O(n) time complexity
// other operations happen in O(1) average time complexity

#ifndef cache
#include <bits/stdc++.h>
using namespace std;

#include "storage/storage.h"
#include "Eviction/Eviction.h"

// dont include the storageMap.h and lifo.h here in the cpp file
#include "storage/storeageMap.h"
#include "Eviction/lifo.h"
#include "Eviction/lru.h"
#include "Eviction/fifo.h"

template <class Key, class Value>
class Cache
{
private:
    Eviction<Key> *eviction;
    Storage<Key, Value> *storage;

public:
    Cache(Storage<Key, Value> *storage, Eviction<Key> *eviction){
        this->eviction = eviction;
        this->storage= storage;
    };

    void insert(Key key, Value value)
    {
        if(storage->isKeyExist(key)){
            cout<<"key already exist, updating existing key"<<endl;
            eviction->updateKey(key);
            storage->insert(key, value);
            return;
        }

        if (storage->isFull()){
            cout<<"storage is full"<<endl;
            auto key = eviction->evict();
            if (key.second)
            {
                storage->pop(key.first);
            }
        }

        storage->insert(key, value);
        eviction->insert(key);
    };

    pair<Value, bool> get(Key key)
    {
        eviction->access(key);
        return storage->get(key);
    };

    int size()
    {
        return storage->size();
    };

    bool isEmpty()
    {
        return storage->isEmpty();
    };

    bool isFull()
    {
        return storage->isFull();
    };
};


#endif

