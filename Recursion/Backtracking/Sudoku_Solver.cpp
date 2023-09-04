// Given a 9×9 incomplete sudoku, solve it such that it becomes valid sudoku. Valid sudoku has the following properties.

// 1. All the rows should be filled with numbers(1 – 9) exactly once.
// 2. All the columns should be filled with numbers(1 – 9) exactly once.
// 3. Each 3×3 submatrix should be filled with numbers(1 – 9) exactly once.


// TC - O(9 ^ (n * n))
// n = size of board
// SC - O(1)


#include <iostream>
#include <vector>
using namespace std;


bool isValid(vector<vector<char>> &board, int row, int col, char c)
{

    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == c) return false;

        if (board[row][i] == c) return false;

        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
    }

    return true;
}


bool solveSudoku(vector<vector<char>> &board)
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

                        if (solveSudoku(board)) return true;
                        else board[i][j] = '.';
                    }
                }

                return false;
            }
        }
    }
    
    return true;
}