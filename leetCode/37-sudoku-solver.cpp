#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }

    bool solve(vector<vector<char>> &board)
    {
        // first we will search for empty place in the sudoku
        // by traversing rows and cols
        for (int row = 0; row < board.size(); row++)
        {
            for (int col = 0; col < board[0].size(); col++)
            {
                if (board[row][col] == '.')
                {
                    // we will try to put numbers from 1 to 9
                    for (char c = '1'; c <= '9'; c++)
                    {
                        // if it is a valid place to put number
                        if (isValid(board, row, col, c))
                        {
                            // we will put that number on the board
                            board[row][col] = c;
                            // now we will move to the recursion and search for next empty cell
                            bool isBoardSolved = solve(board);
                            if (isBoardSolved)
                                return true;
                            else
                                // if board is not solve, at the time of backtracking
                                // we will remove the currently added number so that we can
                                // the next number
                                board[row][col] = '.';
                        }
                        // if we have tried all the number 1 to 9 and unable to place any number at empty spot
                        // then we cannot solve the sudoku
                    }
                    return false;
                }
            }
        }

        // if we have move to the end and did not found any empty cell then the board is solved
        return true;
    }

    bool isValid(vector<vector<char>> &board, int row, int col, char c)
    {
        // we will loop from 1 to 9
        for (int i = 0; i < 9; i++)
        {
            // first we will check for the col
            if (board[row][i] == c)
                return false;
            if (board[i][col])
                return false;
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false;
        }
    }
};

class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }

    bool solve(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == '.')
                {
                    for (char c = '1'; c <= '9'; c++)
                    {
                        if (isValid(board, i, j, c))
                        {
                            board[i][j] = c;

                            if (solve(board))
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }

                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>> &board, int row, int col, char c)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == c)
                return false;

            if (board[row][i] == c)
                return false;

            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false;
        }
        return true;
    }
};