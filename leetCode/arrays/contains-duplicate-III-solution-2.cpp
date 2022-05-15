#include <bits/stdc++.h>
#define REP(i, a, n) for (i = a; i < n; i++)
//#define rep(i, n) REP(i, 0, n)

using namespace std;

typedef long long int ll;

bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
{
    int n = nums.size();

    vector<pair<long long, int>> arr_pairs;
    for (int i = 0; i < n; i++)
    {
        arr_pairs.push_back({nums[i], i});
    }
    sort(arr_pairs.begin(), arr_pairs.end());

    int i = 0, j = 1;
    while (j < n)
    {
        int num_diff = abs(arr_pairs[j].first - arr_pairs[i].first);
        int index_diff = abs(arr_pairs[i].second - arr_pairs[j].second);

        if (num_diff > t && i != j)
        {
            i++;
            continue;
        };
        if (index_diff > k || i == j  )
        {
            j++;
        }
        else
        {
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{

    vector<int> nums{1, 5, 9, 1, 5, 9};
    int k = 1;
    int t = 2;
    // vector<int> nums{1,2,3,1};
    // int k = 3;
    // int t = 0;
    // vector<int> nums{1,0,1,1};
    // int k = 1;
    // int t = 2;
    string res = containsNearbyAlmostDuplicate(nums, k, t) ? "true" : "false";
    cout << res << endl;

    return 0;
}