#include <bits/stdc++.h>

// #hashmap, #maps, #arrays

using namespace std;

// #define nCr(n,r)

int numIdenticalPairs(vector<int> &nums)
{
    int p = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] == nums[j])
                p++;
        }
    }

    return p;
}

int numIdenticalPairs2(vector<int> &nums)
{
    unordered_map<int, int> ump;
    int ans = 0;
    for (auto i : nums)
    {
        ump[i]++;
    }
    for (auto m : ump)
    {
        int n = m.second;
        // this formula is for selecting combination of 2 non distinct number out of n elements
        ans += (n * (n - 1)) / 2;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> nums{1, 2, 3, 1, 1, 3};

    int p = numIdenticalPairs2(nums);

    cout << p;

    return 0;
}