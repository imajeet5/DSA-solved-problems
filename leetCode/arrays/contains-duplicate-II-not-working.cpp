#include <bits/stdc++.h>
#define REP(i, a, n) for (i = a; i < n; i++)
//#define rep(i, n) REP(i, 0, n)

// not working

using namespace std;

typedef long long int ll;

void printVec(std::vector<int> const &a)
{

    for (int i = 0; i < a.size(); i++)
        cout << a.at(i) << " ";
    cout << endl;
}

bool containsNearbyDuplicate(vector<int> &nums, int k)
{

    vector<int> sorted_nums(nums.begin(), nums.end());

    sort(sorted_nums.begin(), sorted_nums.end());

    set<int> duplicates;
    for (int i = 1; i < sorted_nums.size(); i++)
    {
        if (sorted_nums[i - 1] == sorted_nums[i])
        {
            duplicates.insert(sorted_nums[i]);
        }
    }

    for (auto s : duplicates)
    {
        int i = -1;
        int j = -1;
        for (int a = 0; a < nums.size(); a++)
        {
            if (i == -1 && nums.at(a) == s)
            {
                i = a;
            }
            if (i > -1 && i != a && nums.at(a) == s)
            {
                j = a;
            }
            if (i > -1 && j > -1 && abs(i - j) <= k)
            {
                return true;
            }
        }
    }

    return false;
}

int main(int argc, char const *argv[])
{
    vector<int> nums{1,0,1,1};
    int k = 1;
    string res = containsNearbyDuplicate(nums, k) ? "true" : "false";
    cout << res << endl;
    return 0;
}