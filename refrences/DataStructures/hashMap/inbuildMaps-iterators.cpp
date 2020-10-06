#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    unordered_map<string, int> map_unordered;
    map_unordered["abc"] = 1;
    map_unordered["abc1"] = 2;
    map_unordered["abc2"] = 3;
    map_unordered["abc3"] = 4;
    map_unordered["abc4"] = 5;
    map_unordered["abc5"] = 6;

    // unordered_map<string, int>::iterator it = map_unordered.begin();

    for (auto it = map_unordered.begin(); it != map_unordered.end(); it++)
    {
        cout << "Key: " << it->first << " Value: " << it->second << endl;
    }

    cout << "***********************************************" << endl;

    map<string, int> map_ordered;

    map_ordered["abc2"] = 3;
    map_ordered["abc3"] = 4;
    map_ordered["abc4"] = 5;
    map_ordered["abc5"] = 6;
    map_ordered["abc"] = 1;
    map_ordered["abc1"] = 2;

    // it will sort out keys, we will traverse in sorted manner according to keys
    for (auto it = map_ordered.begin(); it != map_ordered.end(); it++)
    {
        cout << "Key: " << it->first << " Value: " << it->second << endl;
    }

    // find
    if (map_unordered.find("abc") == map_unordered.end())
    {
        cout << "Not present" << endl;
    }
    else
    {
        cout << "Present" << endl;
    }

    if (map_unordered.count("abc") == 0)
    {
        cout << "Not present" << endl;
    }
    else
    {
        cout << "Present" << endl;
    }

    // this will give iterator to that element
    unordered_map<string, int>::iterator it = map_unordered.find("abc");
    //erase function takes two things as input, either we can give a key or we can also give iterator
    map_unordered.erase(it);

    if (map_unordered.find("abc") == map_unordered.end())
    {
        cout << "Not present" << endl;
    }
    else
    {
        cout << "Present" << endl;
    }

    map_unordered.erase(map_unordered.begin(), map_unordered.end());

    cout << "Size " << map_unordered.size() << endl;

    return 0;
}