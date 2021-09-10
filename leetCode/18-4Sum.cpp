#include <bits/stdc++.h>

using namespace std;

class Solution1
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        set<vector<int>> s;
        vector<vector<int>> ans;

        for (int i = 0; i < n - 3; i++)
        {
            for (int j = i + 1; j < n - 2; j++)
            {
                for (int k = j + 1; k < n - 1; k++)
                {
                    for (int l = k + 1; l < n; l++)
                    {
                        if ((nums[i] + nums[j] + nums[k] + nums[l]) == target)
                        {
                            vector<int> q = {nums[i], nums[j], nums[k], nums[l]};
                            sort(q.begin(), q.end());
                            s.insert(q);
                        }
                    }
                }
            }
        }

        for (auto q : s)
        {
            ans.push_back(q);
        }

        return ans;
    }
};

class Solution2
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;

        int n = nums.size();

        if (n < 4)
        {
            return ans;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++)
        {
            
             if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            // if next three element of the sorted array are greater then target we will not found the ans further
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
            {
                break;
            }

            // if the sum of ith element and adding last 3 greatest element to it still let then target
            // we will not get the target sum for this itereation
            if (nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target)
            {
                continue;
            }

           

            for (int j = i + 1; j < n - 2; j++)
            {
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
                {
                    // if the sum of first 4 smaller element is greater then target then we will not found the
                    // sum as adding further element will only going to increase the sum
                    break;
                }

                if (nums[i] + nums[j] + nums[n - 1] + nums[n - 2] < target)
                {
                    continue;
                }

                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }

                int left = j + 1;
                int right = n - 1;
                // we will take the two pointer approach
                while (left < right)
                {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum < target)
                    {
                        left++;
                    }
                    else if (sum > target)
                    {
                        right--;
                    }
                    else
                    {
                        // if sum == target
                        ans.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        do
                        {
                            left++;
                        } while ((left < right) && nums[left] == nums[left - 1]);

                        do
                        {
                            right--;
                        } while ((left < right) && nums[right] == nums[right + 1]);
                    }
                }
            }
        }
        return ans;
    }
};