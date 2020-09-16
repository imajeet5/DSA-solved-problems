// https://leetcode.com/problems/spiral-matrix/

#include <bits/stdc++.h>

using namespace std;

void printVec(std::vector<int> const &a)
{

    for (int i = 0; i < a.size(); i++)
        cout << a.at(i) << " ";
    cout << endl;
}

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> ans;
    int m = matrix.size();
    if (m == 0)
        return ans;

    int n = matrix[0].size();

    int sr = 0, er = m - 1, sc = 0, ec = n - 1;
    int count = 0;

    while (sr <= er && sc <= ec)
    {
        // print starting row
        for (int i = sc; i <= ec; i++)
        {
            ans.push_back(matrix[sr][i]);
            count++;
        }
        sr++;
        if (count == m * n)
            return ans;

        // print end column
        for (int i = sr; i <= er; i++)
        {
            ans.push_back(matrix[i][ec]);
            count++;
        }
        ec--;
        if (count == m * n)
            return ans;

        for (int i = ec; i >= sc; i--)
        {
            ans.push_back(matrix[er][i]);
            count++;
        }
        er--;
        if (count == m * n)
            return ans;
        for (int i = er; i >= sr; i--)
        {
            ans.push_back(matrix[i][sc]);
            count++;
        }
        sc++;
        if (count == m * n)
            return ans;
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix{{1, 2, 3},
                               {4, 5, 6},
                               {7, 8, 9}};

    vector<int> result = spiralOrder(matrix);

    printVec(result);

    return 0;
}