#include <bits/stdc++.h>

using namespace std;

void printVec(std::vector<int> const &a)
{

    for (int i = 0; i < a.size(); i++)
        cout << a.at(i) << " ";
    cout << endl;
}

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    if (m == 0)
    {
        nums1 = nums2;
        return;
    }
    if (n == 0)
    {
        return;
    }

    vector<int> mergedArray;
    int j = 0;
    int i = 0;

    while (i < m)
    {
        if (j >= n)
        {
            break;
        }
        if (nums1[i] <= nums2[j])
        {
            mergedArray.push_back(nums1[i]);
            i++;
        }
        else
        {
            mergedArray.push_back(nums2[j]);
            j++;
        }
    }

    while (j < n)
    {
        mergedArray.push_back(nums2[j]);
        j++;
    }
    while (i < m)
    {
        mergedArray.push_back(nums1[i]);
        i++;
    }

    nums1 = mergedArray;
}

int main(int argc, char const *argv[])
{
    vector<int> num1{4,0,0,0,0,0};
    int m = 1;
    vector<int> num2{1,2,3,5,6};
    int n = 5;
    merge(num1, m, num2, n);
    printVec(num1);
    return 0;
}