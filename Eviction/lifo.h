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
            if(ids.find(key) == ids.end()){
                keys.push(key);
                ids.insert(key);
            }
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
            ids.erase(key);
            return {key, true};
        };

        void updateKey(Key key){
            stack<Key> temp;
            while(!keys.empty()){
            if(keys.top() == key){
                keys.pop();
                break;
            }
            temp.push(keys.top());
            keys.pop();
            }

            while(!temp.empty()){
                keys.push(temp.top());
                temp.pop();
            }
            return;  
        };

};



#endif