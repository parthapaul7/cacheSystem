#include <iostream>
using namespace std;
#include "cache.h"

void testCache(Cache<int , string> *cache){

    cache->insert(1, "one");
    cache->insert(2, "two");

    cache->insert(3, "three");
    cache->insert(2, "two updated");
    cout<<cache->get(1).first<<endl;
    cache->insert(4, "six");

    cout<<cache->get(3).first<<endl; // not found in case of LRU
    cache->insert(5, "five");
    // cache->insert(5, "five");
    // cache->insert(4, "four");
    cout<<cache->get(1).first<<endl;
    cout<<cache->get(2).first<<endl;
    cout<<cache->get(3).first<<endl;
    cout<<cache->get(4).first<<endl;
    cout<<cache->get(5).first<<endl;
    // cout<<cache->get(6).first<<endl;
}



int main(){
    cout<< "TEST: LRU" << endl;
    auto *s = new StorageMap<int, string>(3);
    auto *e = new LRU<int>();
    auto *cache1 = new Cache<int, string>(s, e);
    testCache(cache1);
    delete s, e, cache1;


    cout<< "\nTEST: FIFO\n" << endl;
    auto *s2 = new StorageMap<int, string>(3);
    auto *e2 = new FIFO<int>();
    auto *cache2 = new Cache<int, string>(s2, e2);
    testCache(cache2);
    delete s2, e2, cache2;

    cout<< "\nTEST: LIFO\n" << endl;
    auto *s3 = new StorageMap<int, string>(3);
    auto *e3 = new LIFO<int>();
    auto *cache3= new Cache<int, string>(s3, e3);
    testCache(cache3);
    delete s3, e3, cache3;


}