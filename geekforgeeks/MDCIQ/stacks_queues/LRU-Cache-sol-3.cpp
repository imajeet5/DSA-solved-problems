
#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
private:
    unordered_map<int, pair<int, list<int>::iterator>> value; // will keep only existing elements
    list<int> dq;
    // unordered_map<int,int> cnt_in_queue;
    int capacity;
    void erase(int key)
    {
        auto it = value.find(key);
        // for(int x : dq) cout << x << ", ";
        // cout << endl;
        assert(it != value.end());
        dq.erase(it->second.second);
        value.erase(it);
    }
    void push(int key, int v)
    {
        dq.push_back(key);
        value[key] = {v, prev(dq.end())};
    }

public:
    LRUCache(int given_capacity)
    {
        capacity = given_capacity;
    }

    int get(int key)
    {
        auto it = value.find(key);
        if (it == value.end())
        {
            return -1;
        }
        int old_value = it->second.first;
        // erase the key from it current position 
        erase(key);
        // push the same value to the front
        push(key, old_value);
        return old_value;
    }

    void put(int key, int v)
    {
        // if key is already exits
        if (value.find(key) != value.end())
        {
            erase(key);
        }
        if ((int)value.size() == capacity)
        {
            assert(!dq.empty());
            erase(dq.front());
        }
        push(key, v);

        /*if((int) value.size() < capacity) {
            add_to_queue(key);
            value[key] = {v, ..};
            return;
        }
        auto it = value.find(key);
        if(it != value.end()) { // this key exists
            it->second = v;
            // value[key] = value;
            add_to_queue(key);
            return;
        }
        while(true) {
            int candidate = dq.front();
            dq.pop();
            if(--cnt_in_queue[candidate] == 0) {
                cnt_in_queue.erase(candidate);
                value.erase(candidate);
                break;
            }
        }
        value[key] = v;
        add_to_queue(key);*/
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */