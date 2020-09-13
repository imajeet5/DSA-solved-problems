#include <bits/stdc++.h>

using namespace std;

void printVec(std::vector<int> const &a)
{

    for (int i = 0; i < a.size(); i++)
        cout << a.at(i) << " ";
    cout<<endl;
}

int removeDuplicates(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;
    int i = 0;
    for (int j = 1; j < nums.size(); j++)
    {
        if (nums[j] != nums[i])
        {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}

int main(int argc, char const *argv[])
{
    vector<int> num1{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    removeDuplicates(num1);
    printVec(num1);
    return 0;
}