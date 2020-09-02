#include <bits/stdc++.h>
#define REP(i, a, n) for (i = a; i < n; i++)
//#define rep(i, n) REP(i, 0, n)

using namespace std;

typedef long long int ll;

bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    if (nums.size() == 0)
    {
        return false;
    }
    map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        if (mp.find(nums[i]) == mp.end())
        {
            mp[nums[i]] = i;
        }
        else
        {
            if (i - mp[nums[i]] <= k)
            {
                return true;
            }
            else
            {
                mp[nums[i]] = i; //Update the position
            }
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> nums{2, 2};
        int k = 3;
        string res = containsNearbyDuplicate(nums, k) ? "true" : "false";
        cout << res << endl;
    }

    return 0;
}