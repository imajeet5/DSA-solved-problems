//  implementation using spearate chaining

#include <bits/stdc++.h>

using namespace std;

template <typename V>
class MapNode
{
public:
    string key;
    V value;
    MapNode *next;

    MapNode(string key, V value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }
    ~MapNode()
    {
        delete next;
    }
};

template <typename V>
class My_map
{
private:
    MapNode<V> **buckets;
    int count;
    int bucketSize;

    int getBucketIndex(string key)
    {
        int hashcode = 0;
        int base = 1;
        int p = 37;
        for (int i = key.size() - 1; i >= 0; i--)
        {
            hashcode += key[i] * base;
            base = base * p;

            hashcode = hashcode % bucketSize;
            base = base % bucketSize;
        }

        return hashcode % bucketSize;
    }

    void rehash()
    {
        MapNode<V> **temp = buckets;
        int oldBucketSize = bucketSize;
        bucketSize *= 2;
        buckets = new MapNode<V> *[bucketSize];
        for (int i = 0; i < bucketSize; i++)
        {
            buckets[i] = NULL;
        }

        count = 0;

        // for the old array we will iterate over each element in the list and insert into the new bucket
        for (int i = 0; i < oldBucketSize; i++)
        {
            MapNode<V> *head = temp[i];
            while (head != NULL)
            {

                string key = head->key;
                V value = head->value;

                insert(key, value);

                head = head->next;
            }
        }

        for (int i = 0; i < oldBucketSize; i++)
        {
            delete temp[i];
        }

        delete[] temp;
    }

public:
    My_map()
    {
        count = 0;
        bucketSize = 5;
        buckets = new MapNode<V> *[bucketSize];
        for (int i = 0; i < bucketSize; i++)
        {
            buckets[i] = NULL;
        }
    }

    ~My_map()
    {
        for (int i = 0; i < bucketSize; i++)
        {
            delete buckets[i];
        }

        delete[] buckets;
    }

    int size()
    {
        return count;
    }

    V getValue(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];

        while (head != NULL)
        {
            if (head->key == key)
            {
                return head->value;
            }

            head = head->next;
        }

        return 0;
    }

    void insert(string key, V value)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                head->value = value;
                return;
            }

            head = head->next;
        }

        // create a new node
        MapNode<V> *node = new MapNode<V>(key, value);
        // new node next will point to the current head node
        node->next = buckets[bucketIndex];
        // update the head node as the new node
        buckets[bucketIndex] = node;
        count++;

        // calculate the load factor
        double loadFactor = (1.0 * count) / bucketSize;
        // rehash if loadFactor greater then 0.7
        if (loadFactor > 0.7)
        {
            rehash();
        }
    }

    V remove(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        MapNode<V> *prev = NULL;
        while (head != NULL)
        {
            if (head->key == key)
            {
                if (prev == NULL)
                {
                    buckets[bucketIndex] = head->next;
                }
                else
                {
                    prev->next = head->next;
                }
                V value = head->value;
                head->next = NULL;
                delete head;
                count--;
                return value;
            }

            prev = head;
            head = head->next;
        }

        return 0;
    }

    double getLoadFactor()
    {
        return (1.0 * count) / bucketSize;
    }
};

int main(int argc, char const *argv[])
{
    My_map<int> hashMap;

    for (int i = 0; i < 10; i++)
    {
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        int value = i + 1;
        hashMap.insert(key, value);

        cout << hashMap.getLoadFactor() << endl;
    }

    cout << "Size: " << hashMap.size() << endl;
    
    hashMap.remove("abc1");
    hashMap.remove("abc6");
    
    
    for (int i = 0; i < 10; i++)
    {
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        cout << key << ": " << hashMap.getValue(key) << endl;
    }
    
    cout << "Size: " << hashMap.size() << endl;

    return 0;
}