#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void getPermutations(int start, vector<int> &nums, vector<vector<int>> &result)
    {

        if (start > nums.size())
        {
            result.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); i++)
        {
            swap(nums[start], nums[i]);
            getPermutations(start + 1, nums, result);
            // we will unswap the numbers
            swap(nums[start], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        getPermutations(0, nums, result);

        return result;
    }
};

class Solution2
{
public:
    void getPermutations(vector<int> current, int freq[], vector<int> nums, vector<vector<int>> result)
    {
        if (current.size() == nums.size())
        {
            result.push_back(current);
            return;
        }

        // now here we will iterate all the elements of nums
        for (int i = 0; i < nums.size(); i++)
        {
            // if element does not exist in the frequency map
            if (!freq[i])
            {
                current.push_back(nums[i]);
                freq[i] = 1;
                // we will again call the recursive function for the element and push the remaining elements
                getPermutations(current, freq, nums, result);
                // this this at the time of backtracking
                current.pop_back();
                freq[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> current;
        int freq[nums.size()] = {0};
        getPermutations(current, freq, nums, result);

        return result;
    }
};