#include <bits/stdc++.h>
#define REP(i, a, n) for (i = a; i < n; i++)
//#define rep(i, n) REP(i, 0, n)

using namespace std;

typedef long long int ll;

void printVec(std::vector<int> const &a)
{

    for (int i = 0; i < a.size(); i++)
        cout << a.at(i) << " ";
    cout << endl;
}

int getMinSub(vector<int> &A)
{
    int min_val = INT_MAX;
    for (int i = 0; i < A.size() - 1; i++)
    {
        for (int j = i + 1; j < A.size(); j++)
        {
            int diff = abs(A[i] - A[j]);
            if (diff < min_val)
                min_val = diff;
        }
    }
    return min_val;
}

bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
{
    vector<int> slider(nums.begin(), nums.begin() + k + 1);
    int i = k;
    do
    {
        i++;
        int min_value = getMinSub(slider);
        if (min_value <= t)
        {
            return true;
        }
        slider.erase(slider.begin());
        slider.push_back(nums[i]);
    } while (i < nums.size());

    return false;
}

int main(int argc, char const *argv[])
{

    vector<int> nums{1,0,1,1};
    int k = 1;
    int t = 2;
    string res = containsNearbyAlmostDuplicate(nums, k , t) ? "true" : "false";
    cout << res << endl;

    return 0;
}