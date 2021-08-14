#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    unordered_map<int, int> t;
    t[1] = 3;
    auto x = t.find(1) != t.end();

    cout << t[2] << endl;

    // pair<int, int> p;
    // p.first = 10;
    // cout << p.second << endl;

    return 0;
}