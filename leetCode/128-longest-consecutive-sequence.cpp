#include <bits/stdc++.h>

using namespace std;

class Solution1
{
public:
    int longestConsecutive(vector<int> &nums)
    {

        if (nums.size() == 0)
        {
            return 0;
        }
        if (nums.size() == 1)
        {
            return 1;
        }

        sort(nums.begin(), nums.end());

        int seq = 1, mxSeq = 1, curr = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            while ((i < nums.size() - 1) && nums[i] == curr)
                i++;

            if (nums[i] == curr + 1)
            {
                seq++;
                curr++;
                mxSeq = max(mxSeq, seq);
            }
            else
            {
                // reset the value of sequence
                seq = 1;
                curr = nums[i];
            }
        }

        return mxSeq;
    }
};

class Solution2
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 0)
        {
            return 0;
        }

        unordered_set<int> hashSet(nums.begin(), nums.end());

        for (int num : nums)
        {
            hashSet.insert(num);
        }

        int longestStreak = 0;

        for (int num : nums)
        {
            if (!hashSet.count(num - 1))
            {
                int currStreak = 1;
                int currNum = num;
                while (hashSet.count(currNum++))
                {
                    currStreak++;
                }

                longestStreak = max(longestStreak, currStreak);
            }
        }

        return longestStreak;
    }
};

// it is better to use unordered_set

class Solution3
{
public:
    int longestConsecutive(vector<int> &num)
    {
        unordered_set<int> record(num.begin(), num.end());
        int res = 1;
        for (int n : num)
        {
            if (record.find(n) == record.end())
                continue;
            record.erase(n);
            int prev = n - 1, next = n + 1;
            while (record.find(prev) != record.end())
                record.erase(prev--);
            while (record.find(next) != record.end())
                record.erase(next++);
            res = max(res, next - prev - 1);
        }
        return res;
    }
};

// int main(int argc, char const *argv[])
// {
//     vector<int> nums = {1, 2, 0, 1};
//     Solution sol;

//     cout << "Result: " << sol.longestConsecutive(nums) << endl;
//     return 0;
// }