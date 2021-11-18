#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void getCombinationSum(int start, int remaining, vector<int> current, vector<int> &nums, vector<vector<int>> &results)
    {
        // we target has become less then 0, then just return
        if (remaining < 0)
        {
            return;
        }
        if (remaining == 0)
        {
            // then we will push the current into the result;
            results.push_back(current);
            return;
        }

        for (int i = start; i < nums.size(); i++)
        {
            current.push_back(nums[i]);
            // we will keep on recursive until remaining is less then or equal to 0
            // value of i will not increase as i as we are allowed to have duplicate
            getCombinationSum(i, remaining - nums[i], current, nums, results);
            // now when we return from this we will remove the last element
            // at the time of backtracking
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> current;
        vector<vector<int>> results;
        getCombinationSum(0, target, current, candidates, results);
        return results;
    }
};

class Solution2
{
public:
    void getCombinationSum(int i, int remaining, vector<int> current, vector<int> &nums, vector<vector<int>> &results)
    {
        // this is another way of performing the recursion
        if (remaining < 0)
        {

            return;
        }

        // if we have reach the end
        if (remaining == 0)
        {
            results.push_back(current);
            return;
        }

        // so we have two choice 1) either pick the current element, which we are doing in this case
        // we will pick the current element, pick in the sense that it will reduce the target sum
        current.push_back(nums[i]);
        // we will not increase i in this case as we can pick same element multiple times
        getCombinationSum(i, remaining - nums[i], current, nums, results);
        // at the time of backtracking we will remove the added element
        current.pop_back();

        // another choice we have is to move to next element without selecting the current element
        // in this case i will increase
        getCombinationSum(i + 1, remaining, current, nums, results);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> current;
        vector<vector<int>> results;
        getCombinationSum(0, target, current, candidates, results);
        return results;
    }
};