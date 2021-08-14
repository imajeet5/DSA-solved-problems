// CPP program
#include <bits/stdc++.h>

using namespace std;
int main()
{

    unordered_map<char, int> mpp;
    mpp['a'] = 1;
    mpp['b'] = 2;
    mpp['c'] = 3;
    mpp.insert({'d', 4});
    cout << mpp['c'];

    return 0;
}
