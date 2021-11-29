#include <bits/stdc++.h>

using namespace std;

// first we will define a doubly linked list
class node
{
public:
    int key;
    int val;
    node *next;
    node *prev;
    node(int _key, int _val)
    {
        key = _key;
        val = _val;
    }
};

class LRUCache
{
public:
    // we will have a head pointer and a tail pointer for the list
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    int cap;
    // in this map we will store the key and it corresponding node reference
    unordered_map<int, node *> m;

    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    // this will add a node right after head
    void addnode(node *newnode)
    {
        node *temp = head->next;

        newnode->next = temp;
        newnode->prev = head;

        head->next = newnode;
        temp->prev = newnode;
    }

    void deletenode(node *delnode)
    {
        node *delprev = delnode->prev;
        node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int _key)
    {
        // we will check first if the key exist in the map
        if (m.find(_key) != m.end())
        {
            // we will get the address of the node
            node *resnode = m[_key];
            int val = resnode->val;
            // we have go the value, we have to make it most recently used
            // for that first we delete it from the map
            // delete it from the DLL
            // we will add the same node in the front, i.e. just after head
            // and map will hold the new address of the node
            m.erase(_key);
            deletenode(resnode);
            addnode(resnode);
            m[_key] = head->next;
            return val;
        }

        // if it is not found we will return -1
        return -1;
    }

    void put(int key, int value)
    {
        // first we check if key already exist in the map or not
        if (m.find(key) != m.end())
        {
            node *existingnode = m[key];
            // we will erase the existing node from the map and delete it from the list as well
            m.erase(key);
            deletenode(existingnode);
        }
        // next we will check the capacity of the Cache, if we are reaching the capacity
        // the we will delete the least recently used cache
        // least recently used is tail->prev
        if (m.size() == cap)
        {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }

        // now we will add the new node after the head
        addnode(new node(key, value));
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */