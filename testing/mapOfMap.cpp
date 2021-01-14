#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void doSomething() {}

int main(int argc, char const *argv[])
{
    map<int, map<int, set<int>>> mymap;
    map<int, int> mymap2;

    mymap2[2] = 3;
    mymap2[1] = 2;
    mymap2[5] = 6;
    mymap2[3] = 4;
    for (auto m : mymap2)
    {
        cout << m.first << ": " << m.second << endl;
    }

    return 0;
}