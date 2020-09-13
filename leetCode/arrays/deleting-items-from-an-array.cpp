#include <bits/stdc++.h>

using namespace std;

int removeElement(vector<int> &nums, int val)
{
    vector<int> newArr;
    for (auto n : nums)
        if (n != val)
            newArr.push_back(n);
    nums = newArr;
}

int main(int argc, char const *argv[])
{
    vector<int> nums{3, 2, 2, 3};
    int val = 3;
    removeElement(nums, val);
    return 0;
}