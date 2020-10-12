//Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].

//Return the array in the form [x1,y1,x2,y2,...,xn,yn].

#include <bits/stdc++.h>

using namespace std;

vector<int> shuffle(vector<int> &nums, int n)
{
    vector<int> result(2*n, 0);
    for (int i = 0; i < n; i++)
    {
        result[2 * i] = nums[i];
        result[2 * i + 1] = nums[n + i];
    }

    return result;
}

int main(int argc, char const *argv[])
{
    vector<int> nums{2, 5, 1, 3, 4, 7};
    int n = 3;
    vector<int> result = shuffle(nums, n);

    return 0;
}