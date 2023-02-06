
#include <bits/stdc++.h>
using namespace std;

template <class Key>
class LIFO: public Eviction<Key>
{
    private:
    // list used to reduce time complexity of updation to O(1)
        list<Key> keys;
        unordered_map<Key , list<int>::iterator> keyMap;   
    public:
        LIFO(){ };

        void l_insert(Key key){
            if(keyMap.find(key) != keyMap.end()){
                // update will happen
                keys.erase(keyMap[key]);
                keyMap.erase(key);
            }
            keys.push_back(key);
            keyMap[key] = keys.begin();
        };

        void l_access(Key key){
            return;
        };

        pair<Key, bool> l_evict(){
            Key key;
            if(keys.empty()){
                return {key, false};
            }

            key = keys.back();
            keys.pop_back();
            keyMap.erase(key);

            cout<<"evicting"<<key<<"from LIFO\n"<<endl;
            return {key, true};
        };

};


