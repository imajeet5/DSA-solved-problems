#include <bits/stdc++.h>

using namespace std;

void printVec(std::vector<int> const &a)
{

    for (int i = 0; i < a.size(); i++)
        cout << a.at(i) << " ";
    cout << endl;
}

int removeElement(vector<int> &nums, int val)
{
    int count = 0;

    remove(nums.begin(), nums.end(), val);

    // nums.erase(remove(nums.begin(), nums.end(), val), nums.end());

    return nums.size();
}
int main(int argc, char const *argv[])
{
    vector<int> nums{1, 2, 3, 4, 5, 3};
    int val = 3;
    removeElement(nums, val);
    printVec(nums);
    return 0;
}