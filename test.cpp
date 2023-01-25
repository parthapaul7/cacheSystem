#include <iostream>
using namespace std;
#include "storage/storage.h"


#include "cache.h"


template <class Key, class Value>
class A{
    private:
        set<Key> keys;
        stack<Value> vals; 
    public:
        A(){
            cout<<"A constructor"<<endl;
        }
        void print(){
            cout<<"A print"<<endl;
            for(auto i: keys){
                cout<<i<<endl;
            }
        }
        void insert(Key key){
            keys.insert(key);
        }
};





int main(){
    auto *s = new StorageMap<int, string>(3);
    auto *e = new LRU<int>();
    Cache<int, string> *cache = new Cache<int, string>(s,e);

    cache->insert(1, "one");
    cache->insert(2, "two");
    // cout<<cache->get(2).first<<endl;
    cache->insert(3, "three");
    cache->insert(3, "three updated");
    cout<<cache->get(1).first<<endl;
    cache->insert(6, "six");
    // cache->insert(5, "five");
    // cache->insert(4, "four");
    cout<<cache->get(1).first<<endl;
    cout<<cache->get(2).first<<endl;
    cout<<cache->get(3).first<<endl;
    cout<<cache->get(4).first<<endl;
    cout<<cache->get(5).first<<endl;
    cout<<cache->get(6).first<<endl;
    // cache->insert(3, "three");

    // map<int, int> m;
    // set<int> s;

    // m.insert({1, 10});
    // StorageMap<int, string> cache(2);
    // cache.insert(1, "one");
    // cout<<cache.isEmpty()<<endl;

    // cout<<m[1]<<endl;

}