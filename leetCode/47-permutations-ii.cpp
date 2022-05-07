#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        // we will take a result vector
        vector<vector<int>> result;
        vector<int> current;
        // this array represent which element are in the permutation array
        vector<bool> used(nums.size(), 0);
        sort(nums.begin(), nums.end());
        getPermutations(current, used, result, nums);
        return result;
    }

    void getPermutations(vector<int> current, vector<bool> used, vector<vector<int>> &result, vector<int> &nums)
    {
        // base case
        if (current.size() == nums.size())
        {
            result.push_back(current);
            return;
        }
        // now we will iterate over the elements and get permutation
        for (int i = 0; i < nums.size(); i++)
        {
            // now the most important condition for skipping the elements
            if (used[i] == true || i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
                continue;
            used[i] = true;
            current.push_back(nums[i]);
            getPermutations(current, used, result, nums);
            used[i] = false;
            current.pop_back();
        }
    }
};

int main(int argc, char const *argv[])
{
    int x{};
    cout << "Enter a integer" << endl;
    cin >> x;
    cout << "Result: " << x << endl;
    return 0;
}