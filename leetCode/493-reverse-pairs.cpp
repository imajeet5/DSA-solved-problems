#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int merge(vector<int> &nums, int low, int mid, int high)
    {
        int inv = 0;
        int j = mid + 1;
        for (int i = low; i <= mid; i++)
        {

            while (j <= high && nums[i] > 2LL * nums[j])
            {
                // if the current element at j satisfy the condition for i, we will move the j point by one
                // and check if the next element satisfy the condition for that i

                // alt all the element to the left of i will make pair with that j
                inv += ((mid + 1) - i);
                j++;
            }
            // what ever distance j is moved all the element will make pair with that j
            // inv += (j - (mid + 1));
        }

        // perform the remaining merge sort
        vector<int> temp;
        int left = low, right = mid + 1;
        // left and right are the two pointer, from where we will start merging two arrays
        while (left <= mid && right <= high)
        {
            if (nums[left] <= nums[right])
            {
                temp.push_back(nums[left]);
                left++;
            }
            else
            {
                temp.push_back(nums[right]);
                right++;
            }
        }

        while (left <= mid)
        {
            temp.push_back(nums[left++]);
        }
        while (right <= high)
        {
            temp.push_back(nums[right++]);
        }

        for (int i = low; i <= high; i++)
        {
            nums[i] = temp[i - low];
        }

        return inv;
    }

    int mergeSort(vector<int> &nums, int low, int hight)
    {
        if (low >= hight)
        {
            return 0;
        }
        int inv = 0;
        int mid = (low + hight) / 2;

        inv += mergeSort(nums, low, mid);
        inv += mergeSort(nums, mid + 1, hight);
        inv += merge(nums, low, mid, hight);
        return inv;
    };

    int reversePairs(vector<int> &nums)
    {

        return mergeSort(nums, 0, nums.size() - 1);
    }
};