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

// solution with time complexity on log(Min(n, m))

class SolutionOptimized
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        // we will run this function for the array with sorter length
        if (nums2.size() < nums1.size())
            return findMedianSortedArrays(nums1, nums2);

        int n1 = nums1.size(), n2 = nums2.size();
        // low and high represent minimum and maximum number of elements of num1 that
        // we can include on the left side
        // we can either take none or all the elements
        int low = 0;
        int high = n1;

        //now we will do the binary search
        while (low <= high)
        {
            // we will take two index cut1 for the element upto which we can include from nums1
            // and cut2 for the element of nums2 that we can include
            // cut1 represent from where we are partitioning the nums1
            int cut1 = (low + high) >> 1;
            // (n1 + n2 + 1)/2 => total number of elements that are there on the left side
            // from that we are subtracting the element that are already there in cut1
            // cut2 is from where we are partitioning the nums2
            int cut2 = (n1 + n2 + 1) / 2 - cut1;

            // get all the left and right side element
            int left1 = cut1 != 0 ? nums1[cut1 - 1] : INT_MIN;
            int left2 = cut2 != 0 ? nums2[cut2 - 1] : INT_MIN;
            int right1 = cut1 != n1 ? nums1[cut1] : INT_MAX;
            int right2 = cut2 != n2 ? nums2[cut2] : INT_MAX;

            if (left1 <= right2 && left2 <= right1)
            {
                if ((n1 + n2) % 2 == 0)
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                else
                    return max(left1, left2);
            }
            else if (left1 > right2)
            {
                high = cut1 - 1;
            }
            else
            {
                low = cut1 + 1;
            }
        }

        return 0.0;
    }
};