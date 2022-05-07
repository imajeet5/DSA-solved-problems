#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void getSubsets(int currentIndex, vector<int> current, vector<vector<int>> &subsets, vector<int> &nums)
    {
        subsets.push_back(current);

        for (int i = currentIndex; i < nums.size(); i++)
        {

            // if it is not the first index and we have a duplicate number then we will not pick it
            if (i != currentIndex && nums[i] == nums[i - 1])
            {
                continue;
            }
            current.push_back(nums[i]);
            getSubsets(i + 1, current, subsets, nums);
            current.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> subsets;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        getSubsets(0, curr, subsets, nums);
        return subsets;
    }
};

class Solution2
{
public:
    void getSubsets(int i, vector<int> current, vector<vector<int>> &subsets, vector<int> &nums)
    {
        if (i == nums.size())
        {
            subsets.push_back(current);
            return;
        }

        // Picking the current element
        current.push_back(nums[i]);
        getSubsets(i + 1, current, subsets, nums);
        // Now at the time of not picking the element, we will not pick all the duplicate element
        while (i + 1 < nums.size() && nums[i] == nums[i + 1])
            i++;
        // we will get the subset after skipping the duplicate elements
        getSubsets(i + 1, current, subsets, nums);
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> subsets;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        getSubsets(0, curr, subsets, nums);
        return subsets;
    }
};
