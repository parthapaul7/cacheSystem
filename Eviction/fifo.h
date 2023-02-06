#include <bits/stdc++.h>

using namespace std;
template <class Key>
class FIFO: public Eviction<Key>
{
    private:
        queue<Key> keys;

    public:
        FIFO(){ };

        void l_insert(Key key){
            keys.push(key);
        };

        void l_access(Key key){
            return;
        };

        pair<Key, bool> l_evict(){

            cout<<"evicting from FIFO\n"<<endl;
            Key key;
            if(keys.empty()){
                return {key, false};
            }
            key = keys.front();
            keys.pop();
            return {key, true};
        };

        void l_updateKey(Key key){
            Key tempKey;
            queue<Key> temp;
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
            while(!temp.empty()){
                keys.push(temp.front());
                temp.pop();
            }
            return;
        };

        

}; 

