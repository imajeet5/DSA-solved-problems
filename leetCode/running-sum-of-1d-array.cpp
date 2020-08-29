#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        int size = nums.size();
        vector<int> sums(size);
        int sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += nums.at(i);
            sums.at(i) = sum;
        }
        return sums;
    }
};

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;
    while (n--)
    {
    }
    return 0;
}