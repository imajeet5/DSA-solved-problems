#include <bits/stdc++.h>
#define REP(i, a, n) for (i = a; i < n; i++)
//#define rep(i, n) REP(i, 0, n)

using namespace std;

typedef long long int ll;

bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
{
    if (k < 0 || t < 0)
        return false;
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
        //cout<<nums[i]<<"\n";
        if (map.count(nums[i]) > 0)
        {
            if ((i - map[nums[i]]) <= k)
                return true;
            nums[i] = i;
        }
        else if (t > 0 && map.size() > 0)
        {
            int key = -1;
            for (auto Ref = map.begin(); Ref != map.end(); Ref++)
            {
                if (key != -1)
                {
                    map.erase(key);
                    key = -1;
                }
                if ((i - Ref->second) <= k)
                {
                    if (abs(((long long)Ref->first - nums[i])) <= t)
                        return true;
                }
                else
                {
                    //cout<<Ref->first<<" erase\n";
                    key = Ref->first;
                }
            }
            //cout<<"after\n";
            map[nums[i]] = i;
        }
        else
            map[nums[i]] = i;
    }
    return false;
}

int main(int argc, char const *argv[])
{

    vector<int> nums{1, 5, 9, 1, 5, 9};
    int k = 1;
    int t = 2;
    string res = containsNearbyAlmostDuplicate(nums, k, t) ? "true" : "false";
    cout << res << endl;

    return 0;
}