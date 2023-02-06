#include <bits/stdc++.h>

using namespace std;
template <class Key>
class FIFO: public Eviction<Key>
{
    private:
        // linked list used instead ofa single queue to reduce time complexity of updation to O(1)
        list<Key> keys;
        unordered_map<Key , list<int>::iterator> keyMap;

    public:
        FIFO(){ };

        void l_insert(Key key){

            if(keyMap.find(key) != keyMap.end()){
                // if key already exists, update will happen
                keys.erase(keyMap[key]);
                keyMap.erase(key);
            }
            keys.push_front(key);
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

            cout<<"evicting"<<key<<"from FIFO\n"<<endl;
            return {key, true};
        };

}; 

