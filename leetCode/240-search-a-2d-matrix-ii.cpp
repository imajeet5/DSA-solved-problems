#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
        {
            return false;
        }

        int row = 0;
        int col = matrix[0].size() - 1;

        while (col >= 0 && row <= matrix.size() - 1)
        {
            if (matrix[row][col] == target)
            {
                return true;
            }

            if (target < matrix[row][col])
            {
                col--;
            }
            else
            {
                // if target > matrix[row][col]
                row++;
            }
        }
        return false;
    }
};