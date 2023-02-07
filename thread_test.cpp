#include <bits/stdc++.h>

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
    cache->insert(5, "five");
    cache->insert(4, "four");
    cout<<cache->get(1).first<<endl;
    cout<<cache->get(2).first<<endl;
    cout<<cache->get(3).first<<endl;
    cout<<cache->get(4).first<<endl;
    cout<<cache->get(5).first<<endl;
}

void testThread(Cache<int , string> *cache){
    cache->insert(1, "one 1");
    cache->insert(2, "two 1");
    cache->insert(3, "three 1");
    cache->insert(4, "four 1");
    cout<<cache->get(1).first<<endl;
    cout<<cache->get(2).first<<endl;
    // cout<<cache->get(3).first<<endl;
    // cout<<cache->get(4).first<<endl;
    // cout<<cache->get(5).first<<endl;
}

void testThread2(Cache<int , string> *cache){
    cache->insert(1, "one 2");
    cache->insert(2, "two 2");
    cout<<cache->get(1).first<<endl;
    cout<<cache->get(2).first<<endl;
    // cout<<cache->get(3).first<<endl;
    // cout<<cache->get(4).first<<endl;
    // cout<<cache->get(5).first<<endl;
}

int main(){
    cout<< "TEST: LRU" << endl;
    auto *s = new StorageMap<int, string>(3);
    auto *e = new LRU<int>();

    auto *cache1 = new Cache<int, string>(s, e);

    testCache(cache1);
    thread t1(testThread,cache1);
    thread t2(testThread,cache1);
    thread t3(testThread2,cache1);
    thread t4(testThread2,cache1);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    delete s, e, cache1;

}