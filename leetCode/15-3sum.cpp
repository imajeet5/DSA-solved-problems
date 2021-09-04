#include <bits/stdc++.h>

using namespace std;

class SolutionBruteForce
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        set<vector<int>> setOftriplets;

        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        vector<int> triplet = {nums[i], nums[j], nums[k]};
                        sort(triplet.begin(), triplet.end());
                        setOftriplets.insert(triplet);
                    }
                }
            }
        }

        vector<vector<int>> ans;
        for (auto it : setOftriplets)
        {
            ans.push_back(it);
        }

        return ans;
    }
};

class SolutionOptimizedBetter
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> freq;
        set<vector<int>> setOftriplets;

        for (auto el : nums)
            freq[el]++;
        for (int i = 0; i < n; i++)
        {
            freq[nums[i]]--;
            for (int j = i + 1; j < n; j++)
            {
                freq[nums[j]]--;

                int remaining = -(nums[i] + nums[j]);
                // if the remaining value that is needed to make this to zero is in the map
                if (freq[remaining])
                {
                    vector<int> triplet = {nums[i], nums[j], remaining};
                    sort(triplet.begin(), triplet.end());
                    setOftriplets.insert(triplet);
                }
                freq[nums[j]]++;
            }
            freq[nums[i]]++;
        }

        vector<vector<int>> ans;
        for (auto it : setOftriplets)
        {
            ans.push_back(it);
        }

        return ans;
    };
};

class SolutionOptimizedBest
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        // first we will sort the array
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        int n = nums.size();

        for (int i = 0; i < n - 2; i++)
        {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
            {
                int left = i + 1, right = n - 1;
                int target = 0 - nums[i];

                while (left < right)
                {
                    if (nums[left] + nums[right] == target)
                    {
                        // we have found our triplet
                        vector<int> triplet = {nums[i], nums[left], nums[right]};
                        ans.push_back(triplet);

                        // now we will skip all the same number after this
                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        while (left < right && nums[right] == nums[right - 1])
                            right--;
                        left++;
                        right--;
                    }
                    else if (nums[left] + nums[right] < target)
                    {
                        left++;
                    }
                    else
                    {
                        right--;
                    }
                }
            }
        }

        return ans;
    };
};