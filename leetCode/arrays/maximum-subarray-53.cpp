#include <bits/stdc++.h>
#define REP(i, a, n) for (i = a; i < n; i++)
//#define rep(i, n) REP(i, 0, n)

//https://leetcode.com/problems/maximum-subarray/

using namespace std;

typedef long long int ll;

int maxSubArrayBruteForce(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    int m = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum = nums[i];
        for (int j = i + 1; j <= n; j++)
        {
            m = max(m, sum);
            if (j == n)
            {
                break;
            }
            sum += nums[j];
        }
    }

    return m;
}

int maxSubArray(vector<int> &nums)
{
    int sum = 0;
    int m = INT_MIN;
    for (auto it : nums)
    {
        sum += it;
        m = max(sum, m);
        if (sum < 0)
            sum = 0;
    }
    cout << m << endl;
    return m;
}

int main(int argc, char const *argv[])
{
    vector<int> nums{-2, -3, -1, -5};
    maxSubArray(nums);
    return 0;
}