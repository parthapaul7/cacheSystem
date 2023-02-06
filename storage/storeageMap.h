// using a unordered_map having time average complexity of O(1)
// storage to store key-value pairs of any kind eg - int , string 

#include <bits/stdc++.h>
using namespace std;

template <class Key , class Value>
class StorageMap : public Storage<Key, Value>
{
private:
    int capacity; // maximum number of key-value pairs
    unordered_map<Key, Value> storageMap;

public:
    StorageMap(int capacity){
        this->capacity = capacity;
        storageMap.clear();
    };

    void l_insert(Key key, Value value){
        storageMap[key] = value;
        return;
        // keys.insert(key);
    };

    bool isKeyExist(Key key){
        if(storageMap.find(key) == storageMap.end()){
            return false;
        }
        return true;
    }

    int l_pop(Key key){
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
            cout<<"key not found";
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

 

