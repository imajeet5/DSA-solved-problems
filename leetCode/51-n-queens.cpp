#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isValid(int row, int col, vector<string> board, int n)
    {
        int irow = row;
        int icol = col;
        // first check the upper diagonal
        while (row >= 0 && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }

        row = irow;
        col = icol;
        // now we wil check for horizontal col
        while (col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            col--;
        }

        row = irow;
        col = icol;
        // now we will check the bottom diagonal to the right side
        while (row < n && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            row++;
            col--;
        }

        return true;
    }

    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isValid(row, col, board, n))
            {
                // we will at queen at the position and continue recursion with for the next row
                board[row][col] = 'Q';
                solve(col + 1, board, ans, n);
                // at the time of backtracking we will remove the add queen as this poistion is
                // already processed by from recursion
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }

        solve(0, board, ans, n);

        return ans;
    }
};

class SolutionOptimized
{
public:
    void solve(int col, vector<string> &board, vector<vector<string>> ans, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            // first we will check if it is a valid place to put queen
            if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0)
            {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;
                solve(col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
                // at the time of backtracking we will remove element from the board as well as map
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }

        // now we will create three hash array
        vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
        solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
        return ans;
    }
};