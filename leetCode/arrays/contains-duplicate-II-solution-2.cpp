#include <bits/stdc++.h>
#define REP(i, a, n) for (i = a; i < n; i++)
//#define rep(i, n) REP(i, 0, n)

using namespace std;

typedef long long int ll;

bool containsNearbyDuplicate(vector<int> &nums, int k)
{

    if (k <= 0)
        return false;
    if (k >= nums.size())
        k = nums.size() - 1;
    // set of first k element
    set<int> k_set(nums.begin(), nums.begin() + k);
    // if the number are repeating in first 3
    if (k_set.size() < k)
    {
        return true;
    }
    for (int i = k; i < nums.size(); i++)
    {
        // next element is already present in the set
        if (k_set.find(nums[i]) != k_set.end())
        {
            return true;
        }
        k_set.erase(nums[i - k]);
        k_set.insert(nums[i]);
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