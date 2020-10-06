#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    unordered_map<string, int> my_map;
    // insert
    pair<string, int> p("abc", 1);
    my_map.insert(p);
    my_map["def"] = 2;

    // find or access elements

    cout << my_map["abc"] << endl;

    cout << my_map.at("def") << endl;

    cout << "Size " << my_map.size() << endl;

    // this will push ghi in the map and return 0 as it was assign the value as 0
    cout << my_map["ghi"] << endl;

    // check the presence of a key
    if (my_map.count("jkl"))
    {
        cout << "Key is present" << endl;
    }
    else
    {
        cout << "Key is not present" << endl;
    }

    // update
    my_map["abc"] = 20;

    cout << my_map["abc"] << endl;

    // size of the map
    cout << "Size " << my_map.size() << endl;

    //erase
    my_map.erase("abc");
    cout << "Size " << my_map.size() << endl;

    return 0;
}