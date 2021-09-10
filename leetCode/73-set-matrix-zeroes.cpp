#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // traverse the matrix row wise

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == 0)
                {
                    // set all the element of the row that are not zero to -999

                    for (int k = 0; k < cols; k++)
                    {
                        if (matrix[i][k] != 0)
                        {
                            matrix[i][k] = -543;
                        }
                    }

                    break;
                }
            }
        }

        // traverse the matrix col wise
        for (int i = 0; i < cols; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                if (matrix[j][i] == 0)
                {
                    // set all the elements of the col that are not zero to -999
                    for (int k = 0; k < rows; k++)
                    {
                        if (matrix[k][i] != 0)
                        {
                            matrix[k][i] = -543;
                        }
                    }
                    break;
                }
            }
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == -543)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

class Solution2
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

        for (int i = 0; i < rows; i++)
        {
            if (matrix[i][0] == 0)
                col0 = 0;
            for (int j = 1; j < cols; j++)
                if (matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
        }

        for (int i = rows - 1; i >= 0; i--)
        {
            for (int j = cols - 1; j >= 1; j--)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            if (col0 == 0)
                matrix[i][0] = 0;
        }
    }
};