#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void backtracking(int start, int remaining, vector<int> current, vector<int> &nums, vector<vector<int>> &result)
    {

        if (remaining < 0)
        {
            return;
        }

        if (remaining == 0)
        {
            result.push_back(current);
            return;
        }

        for (int i = start; i < nums.size(); i++)
        {

            if (i > start && nums[i] == nums[i - 1])
                continue;

            if (remaining - nums[i] < 0)
                break;
            // we will first push the current element in array
            current.push_back(nums[i]);
            // we will go in the recursion and take the next element
            backtracking(i + 1, remaining - nums[i], current, nums, result);
            // at the time of backtracking we will remove the added element
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        backtracking(0, target, current, candidates, result);
        return result;
    }
};