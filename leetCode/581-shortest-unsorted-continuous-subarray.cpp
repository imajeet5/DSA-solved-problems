
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {

        int n = nums.size(), mx = nums[0], mn = nums[n - 1], end = -2, begin = -1;
        if (n == 0 || n == 1)
        {
            return 0;
        }

        // left pass, in this we will determine the end
        for (int i = 1; i < n; i++)
        {
            mx = max(mx, nums[i]);
            // if the current element is less the max value until now, then we will update the end
            if (nums[i] < mx)
            {
                end = i;
            }
        }

        // right pass, in this we will determine the start
        for (int i = n - 2; i >= 0; i--)
        {
            mn = min(mn, nums[i]);

            // in a sorted array next left value must be smaller than the right value, be if the value is greater then the min value upto now then we will update the index
            if (nums[i] > mn)
            {
                begin = i;
            }
        }

        return end - begin + 1;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> values = {1, 2, 3, 4, 5};
    int result = sol.findUnsortedSubarray(values);
    cout << result;
    return 0;
}