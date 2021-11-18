#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void getSubsets(int currentIndex, vector<vector<int>> &subsets, vector<int> current, vector<int> &nums)
    {
        // in this we will push the current arrays
        // at the end of the recursion call stack
        if (currentIndex >= nums.size())
        {
            subsets.push_back(current);
            return;
        }

        // move one index forward and take the current element in the current vector
        current.push_back(nums[currentIndex]);
        getSubsets(currentIndex + 1, subsets, current, nums);

        // move one index forward and without selecting the next element
        current.pop_back();
        getSubsets(currentIndex + 1, subsets, current, nums);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> current;
        vector<vector<int>> subsets;
        getSubsets(0, subsets, current, nums);
        return subsets;
    }
};

class Solution2
{
public:
    class Solution
    {
    public:
        vector<vector<int>> subsets(vector<int> &nums)
        {
            vector<vector<int>> subs;
            vector<int> sub;
            getSubsets(nums, 0, sub, subs);
            return subs;
        }

    private:
        void getSubsets(vector<int> &nums, int i, vector<int> &sub, vector<vector<int>> &subs)
        {
            subs.push_back(sub);
            for (int j = i; j < nums.size(); j++)
            {
                sub.push_back(nums[j]);
                getSubsets(nums, j + 1, sub, subs);
                sub.pop_back();
            }
        }
    };
};
