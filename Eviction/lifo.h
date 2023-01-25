#ifndef lifo_h 
#define lifo_h

#include <bits/stdc++.h>
using namespace std;

template <class Key>
class LIFO: public Eviction<Key>
{
    private:
        stack<Key> keys;
        set<Key> ids; // to make sure that the keys are unique
    
    public:
        LIFO(){
            ids.clear();
        };

        void insert(Key key){
                keys.push(key);
        };

        void access(Key key){
            return;
        };

        pair<Key, bool> evict(){

            cout<<"evicting from LIFO"<<endl;
            Key key;
            if(keys.empty()){
                return {key, false};
            }
            key = keys.top();
            keys.pop();
            return {key, true};
        };

        void updateKey(Key key){
            Key tempKey;
            stack<Key> temp;
            while(!keys.empty()){
            if(keys.top() == key){
                tempKey = keys.top();
                keys.pop();
            }
            temp.push(keys.top());
            keys.pop();
            }

            temp.push(tempKey);
            while(!temp.empty()){
                keys.push(temp.top());
                temp.pop();
            }
            return;  
        };

};



#endif