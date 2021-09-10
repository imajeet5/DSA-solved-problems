#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size() - 1;
        int i = 0, j = n - 1;

        // matrix is within the bounds
        while (i < n && j >= 0)
        {
            if (matrix[i][j] == target)
            {
                return true;
            }

            if (matrix[i][j] > target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }

        return false;
    }
};

class Solution2
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        // this this technique we will use bubble sort
        int n = matrix.size(), m = matrix[0].size();
        int lo = 0, hi = n * m - 1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (matrix[mid / m][mid % m] == target)
            {
                return true;
            }

            if (matrix[mid / m][mid % m] < target)
            {
                // then we will discard the left half
                lo = mid + 1;
            }
            else
            {
                // we will discard the right half
                hi = mid - 1;
            }
        }

        return true;
    }
};