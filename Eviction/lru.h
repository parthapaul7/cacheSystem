//implementing LRU with stack
#ifndef lru_h 
#define lru_h 

#include <bits/stdc++.h>
using namespace std;

template <class Key>
class LRU: public Eviction<Key>
{ 
private:
    queue<Key> keys;
    set<Key> ids; // to make sure that the keys are unique 

public:
    LRU(){
        ids.clear();
    };

    void insert(Key key){
        if(ids.find(key) == ids.end()){
            keys.push(key);
            ids.insert(key);
        }
    };

    void access(Key key){
        // find the key in the stack and move it to the top
        queue<Key> temp;
        while(!keys.empty()){
            if(keys.front() == key){
                keys.pop();
                break;
            }
            temp.push(keys.front());
            keys.pop();
        }
    };

    pair<Key, bool> evict(){

        cout<<"evicting from LRU"<<endl;
        Key key;
        if(keys.empty()){
            return {key, false};
        }
        key = keys.front();
        keys.pop();
        ids.erase(key);
        return {key, true};
    };

};

#endif