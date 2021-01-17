#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void doSomething() {}

int main(int argc, char const *argv[])
{
    map<int, int> mymap1;
    map<int, map<int, int>> mymap2;
    map<int, map<int, set<int>>> mymap3;

    cout << "Normal map" << endl;
    mymap1[1] = 5;
    mymap1[1] = 6;
    mymap1[1] = 7;
    for (auto m : mymap1)
    {
        cout << m.first << ": " << m.second << endl;
    }

    cout << "Map of map " << endl;

    // mymap3[2].insert(pair<int, int>(1, 2));
    mymap2[2][1] = 2;
    mymap2[2][1] = 3;
    mymap2[2][3] = 4;
    mymap2[3][1] = 4;
    // mymap2[2] = 3;
    for (auto innerMap : mymap2)
    {
        cout << innerMap.first << ": ";
        for (auto m : innerMap.second)
            cout << m.first << ": " << m.second << " ";
        cout << endl;
    }

    cout << "Map of map of set " << endl;
    set<int> s1;
    s1.insert(10);
    s1.insert(20);
    mymap3[1][2] =  s1;
    mymap3[1][3] =  s1;

    return 0;
}