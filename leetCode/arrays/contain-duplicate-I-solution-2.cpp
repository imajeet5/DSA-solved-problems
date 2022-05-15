#include <bits/stdc++.h>
#define REP(i, a, n) for (i = a; i < n; i++)
//#define rep(i, n) REP(i, 0, n)

using namespace std;

typedef long long int ll;

bool containsDuplicate(vector<int> &nums)
{
    set<int> nums_sets(nums.begin(), nums.end());

    if (nums_sets.size() == nums.size())
    {
        return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    vector<int> nums{1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    string res = containsDuplicate(nums) ? "true" : "false";
    cout << res << endl;
    return 0;
}