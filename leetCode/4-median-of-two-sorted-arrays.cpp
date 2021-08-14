#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int i = 0, j = 0;
        vector<int> merged;
        while (i < nums1.size() && j < nums2.size())
        {
            int e1 = nums1[i];
            int e2 = nums2[j];
            if (e1 < e2)
            {
                merged.push_back(e1);
                i++;
            }
            else
            {
                merged.push_back(e2);
                j++;
            }
        }

        while (i < nums1.size())
        {
            merged.push_back(nums1[i]);
            i++;
        }
        while (j < nums2.size())
        {
            merged.push_back(nums2[j]);
            j++;
        }

        int len = merged.size();
        if (len % 2 == 1)
        {
            int middleElementIndex = ((len + 1) / 2) - 1;
            return merged[middleElementIndex];
        }
        else
        {
            return merged[(len / 2) - 1] + merged[len / 2];
        }
    }
};