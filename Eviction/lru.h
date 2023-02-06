//implementing LRU with stack

#include <bits/stdc++.h>
using namespace std;

template <class Key>
class LRU: public Eviction<Key>
{ 
private:
    list<Key> keys;
    unordered_map<Key , list<int>::iterator> keyMap;
    // linked list and map is used to reduce time complexity of to O(1)

public:
    LRU(){ };

    void l_insert(Key key){
            if(keyMap.find(key) != keyMap.end()){
                // update will happen
                keys.erase(keyMap[key]);
                keyMap.erase(key);
            }
            keys.push_front(key);
            keyMap[key] = keys.begin();

    };

    void l_access(Key key){

        if(keyMap.find(key) == keyMap.end()){
            return;
        }

        keys.erase(keyMap[key]);
        keys.push_front(key); 
    };

    pair<Key, bool> l_evict(){
        Key key;
        if(keys.empty()){
            return {key, false};
        }

        key = keys.back();
        keys.pop_back();
        keyMap.erase(key);

        cout<<"evicting"<<key<<"from LRU\n"<<endl;
        return {key, true};
    };

};
