/******************************************************************************

                              Online C++ Debugger.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Debug" button to debug it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class MyHashMap
{
    vector<vector<pair<int, int>>> mp;
    const int size = 10000;

public:
    MyHashMap()
    {
        mp.resize(size);
    }

    void put(int key, int value)
    {
        int index = key % size;
        // but first we also have to check if the key exist in the map or not
        auto &row = mp[index];
        for (int i = 0; i < row.size(); i++)
        {
            if (row[i].first == key)
            {
                row[i].second = value;
                return;
            }
            // we dont need to add the value again and just update the value
        }

        mp[index].push_back({key, value});
    }

    int get(int key)
    {
        int index = key % size;
        auto &row = mp[index];
        for (int i = 0; i < row.size(); i++)
        {
            if (row[i].first == key)
            {
                return row[i].second;
            }
        }

        return -1;
    }

    void remove(int key)
    {
        int index = key % size;
        auto &row = mp[index];
        for (int i = 0; i < row.size(); i++)
        {
            if (row[i].first == key)
            {
                row.erase(row.begin() + i);
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main()
{
    // cout<<"Hello World";
    MyHashMap myHashMap;
    myHashMap.put(1, 1);
    myHashMap.put(2, 2);
    cout << myHashMap.get(1) << endl;
    cout << myHashMap.get(3) << endl;
    myHashMap.put(2, 1);
    cout << myHashMap.get(2) << endl;
    myHashMap.remove(2);
    cout << myHashMap.get(2) << endl;
    return 0;
}
