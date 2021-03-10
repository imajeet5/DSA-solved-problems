#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void lastIndexOfOne(string str)
{
    vector<int> nums;

    for (auto c : str)
    {
        nums.push_back(c - '0');
    }
    int last = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
            last = i;
    }
    cout << last << endl;
}

int main(int argc, char const *argv[])
{
    // freopen("_input.txt", "r", stdin);
    int t = 0;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        lastIndexOfOne(s);
    }
    return 0;
}