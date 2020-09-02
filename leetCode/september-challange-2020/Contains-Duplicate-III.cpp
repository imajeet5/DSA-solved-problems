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

void containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
{
   
}

int main(int argc, char const *argv[])
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n, k, t;
        cout << "Enter number of values in arrays " << endl;
        cin >> n;
        vector<int> nums(n);
        cout << "Enter k and t" << endl;
        cin >> k >> t;
        cout << "Enter values of array " << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> nums.at(i);
        }
        cout << "Result: " << endl;
        containsNearbyAlmostDuplicate(nums, k, t);
    }
    return 0;
}