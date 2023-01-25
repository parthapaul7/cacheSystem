// using a map based storage to store key-value pairs of any kind

#ifndef STORAGE_MAP_H

#include <bits/stdc++.h>
#include "storage.h"
using namespace std;

template <class Key , class Value>
class StorageMap : public Storage<Key, Value>
{
private:
    int capacity; // maximum number of key-value pairs
    map<Key, Value> storageMap;
    // set<Key> keys; // to make sure that the keys are unique

public:
    StorageMap(int capacity){
        this->capacity = capacity;
        storageMap.clear();
    };

    int insert(Key key, Value value){
        if(storageMap.find(key) != storageMap.end()){
            cout<<"key already exists , updating to existing key"<<endl;
            storageMap[key] = value;
            return -1;
        }
        storageMap[key] = value;
        return 1;
        // keys.insert(key);
    };

    bool isKeyExist(Key key){
        if(storageMap.find(key) == storageMap.end()){
            return false;
        }
        return true;
    }

    int pop(Key key){
        if(storageMap.find(key) == storageMap.end()){
            return -1;
        }
        storageMap.erase(key);
        return 0;
    };


    /// can not return a value converted Value class Not found elements so returning a pair 
    pair<Value,bool> get(Key key){
        Value value;
        if(storageMap.find(key) == storageMap.end()){
            cout<<"key not found"<<endl;
            return {value, false} ;
        }
        value = storageMap[key]; 
        return { value ,true };
    };

    int size(){
        return storageMap.size();
    };  

    bool isEmpty(){
        return storageMap.empty();
    };

    bool isFull(){
        return storageMap.size() == capacity;
    }; 

};

 
#endif 

