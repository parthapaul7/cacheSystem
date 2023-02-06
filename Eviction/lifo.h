
#include <bits/stdc++.h>
using namespace std;

template <class Key>
class LIFO: public Eviction<Key>
{
    private:
        stack<Key> keys;
    
    public:
        LIFO(){ };

        void l_insert(Key key){
            keys.push(key);
        };

        void l_access(Key key){
            return;
        };

        pair<Key, bool> l_evict(){

            cout<<"evicting from LIFO\n"<<endl;
            Key key;
            if(keys.empty()){
                return {key, false};
            }
            key = keys.top();
            keys.pop();
            return {key, true};
        };

        void l_updateKey(Key key){
            Key tempKey;
            stack<Key> temp;
            while(!keys.empty()){
            if(keys.top() == key){
                tempKey = keys.top();
                keys.pop();
            }
            else{
                temp.push(keys.top());
                keys.pop();
            }
            }

            while(!temp.empty()){
                keys.push(temp.top());
                temp.pop();
            }
            keys.push(tempKey);
            return;  
        };

};


