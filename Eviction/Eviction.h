// Eviction policy template class
// you can make your own eviction policy by inheriting this class


#include <bits/stdc++.h>
using namespace std;

template <class Key>
class Eviction
{
private:
    mutex m_mutex;
public:
    Eviction(){};
    virtual void insert(Key key) {
        lock_guard<mutex> lock(m_mutex);
        l_insert(key);
    };
    virtual pair<Key, bool> evict() {
        lock_guard<mutex> lock(m_mutex);
        return l_evict();
    };
    virtual void access(Key key) {
        lock_guard<mutex> lock(m_mutex);
        l_access(key);
    };
    virtual void updateKey(Key key) {
        lock_guard<mutex> lock(m_mutex);
        l_updateKey(key);
    };

protected:
    virtual void l_insert(Key key) = 0;
    virtual pair<Key, bool> l_evict() = 0;
    virtual void l_access(Key key) = 0;
    virtual void l_updateKey(Key key) = 0;
};
