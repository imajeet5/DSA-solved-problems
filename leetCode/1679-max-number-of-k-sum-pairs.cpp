#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        int ans = 0;
        for (auto cur : nums)
        {
            int complement = k - cur;
            if (freq[complement] > 0)
            {
                ans++;
                freq[complement]--;
            }
            else
                freq[cur]++;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> el = {2, 2, 2, 3, 1, 1, 4, 1};
    int k = 4;
    int result = sol.maxOperations(el, k);
    cout << "Result is " << result;
    return 0;
}