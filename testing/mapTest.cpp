#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // unordered_map<int, int> t;
    // t[1] = 3;
    // auto x = t.find(1) != t.end();

    // cout << t[2] << endl;

    // pair<int, int> p;
    // p.first = 10;
    // cout << p.second << endl;

    set<vector<int>> setOfVectors;

    vector<int> v1 = {1, 2, 3};
    setOfVectors.insert(v1);

    vector<int> v2 = {1, 2, 3};
    setOfVectors.insert(v2);
    
    vector<int> v3 ={2,3,1};
    setOfVectors.insert(v3);

    for (auto it : setOfVectors)
    {
        for (auto el : it)
        {
            cout << el << " ";
        }

        cout << endl;
    }

    return 0;
}