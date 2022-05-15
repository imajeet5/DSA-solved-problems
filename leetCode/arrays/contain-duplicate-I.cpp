#include <bits/stdc++.h>
#define REP(i, a, n) for (i = a; i < n; i++)
//#define rep(i, n) REP(i, 0, n)

using namespace std;

typedef long long int ll;

bool containsDuplicate(vector<int> &nums)
{
    sort(begin(nums), end(nums));
    bool repeating = false;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i - 1] == nums[i])
        {
            repeating = true;
            return repeating;
        }
    }
    return repeating;
}

int main(int argc, char const *argv[])
{
    vector<int> nums{1,1,1,3,3,4,3,2,4,2};
    string res = containsDuplicate(nums) ? "true" : "false";
    cout << res << endl;
    return 0;
}