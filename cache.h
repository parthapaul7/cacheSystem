
#ifndef cache
#include <bits/stdc++.h>
using namespace std;

#include "storage/storage.h"
#include "Eviction/Eviction.h"

// dont include the storageMap.h and lifo.h here in the cpp file
#include "storage/storeageMap.h"
#include "Eviction/lifo.h"
#include "Eviction/lru.h"

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
        if (storage->isFull())
        {
            auto key = eviction->evict();
            if (key.second)
            {
                storage->pop(key.first);
            }
        }
        storage->insert(key, value);
        eviction->insert(key);
    };

    int pop(Key key)
    {
        if (storage->get(key).second)
        {
            eviction->evict();
            storage->pop(key);
            return 1;
        }
        return 0;
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

