//implementing LRU with stack

#include <bits/stdc++.h>
using namespace std;

template <class Key>
class LRU: public Eviction<Key>
{ 
private:
    queue<Key> keys;

public:
    LRU(){ };

    void l_insert(Key key){
        keys.push(key);
    };

    void l_access(Key key){
        //find the key in the queue and move it to the front 
        Key tempKey;
        queue<Key> temp;
        while(!keys.empty()){
            if(keys.front() == key){
                tempKey = keys.front();
                keys.pop();
            }
            temp.push(keys.front());
            keys.pop();
        }
        temp.push(tempKey);

        while (!temp.empty())
        {
            keys.push(temp.front());
            temp.pop();
        }

        return;
    };

    pair<Key, bool> l_evict(){

        cout<<"evicting from LRU\n"<<endl;
        Key key;
        if(keys.empty()){
            return {key, false};
        }
        key = keys.front();
        keys.pop();
        return {key, true};
    };

    // same as the access method for LRU
    void l_updateKey(Key key){
        queue<Key> temp;
        Key tempKey;

        while(!keys.empty()){
            if(keys.front() == key){
                tempKey = keys.front();
                keys.pop();
            }
            else{
                temp.push(keys.front());
                keys.pop();
            }
        }
        temp.push(tempKey);

        //print the queue

        while (!temp.empty())
        {
            keys.push(temp.front());
            temp.pop();
        }

        return; 
    };

};
