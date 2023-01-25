#ifndef fifo_h
#include <bits/stdc++.h>

using namespace std;
template <class Key>
class FIFO: public Eviction<Key>
{
    private:
        queue<Key> keys;

    public:
        FIFO(){ };

        void insert(Key key){
            keys.push(key);
        };

        void access(Key key){
            return;
        };

        pair<Key, bool> evict(){

            cout<<"evicting from FIFO"<<endl;
            Key key;
            if(keys.empty()){
                return {key, false};
            }
            key = keys.front();
            keys.pop();
            return {key, true};
        };

        void updateKey(Key key){
            queue<Key> temp;
            while(!keys.empty()){
            if(keys.front() == key){
                keys.pop();
                break;
                }
                temp.push(keys.front());
                keys.pop();
            }
            while(!temp.empty()){
                keys.push(temp.front());
                temp.pop();
            }
            return;
        };

        

}; 

#endif