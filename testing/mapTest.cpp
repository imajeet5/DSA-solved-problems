#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    unordered_map<int, int> t;
    t[1] = 3;
    auto x = t.find(1) != t.end();
    cout << x << endl;
    return 0;
}