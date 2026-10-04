/*

37. Sudoku Solver
Solved
Hard
Topics
premium lock icon
Companies
Hint
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.
 

Example 1:


Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:


Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit or '.'.
It is guaranteed that the input board has only one solution.

*/

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution
{
public:
    void sudokuSolver(vector<vector<char>>& board)
    {
        solve(board);
    }

    bool solve(vector<vector<char>>& board)
    {
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] == '.')
                {
                    for (char ch = '1'; ch <= '9'; ++ch)
                    {
                        if (isValid(board, i, j, ch))
                        {
                            board[i][j] = ch;

                            if (solve(board))
                                return true;

                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(const vector<vector<char>>& board, int row, int col, char ch)
    {
        for (int i = 0; i < 9; ++i)
        {
            if (board[row][i] == ch) return false;
            if (board[i][col] == ch) return false;
        }

        int boxRow = (row / 3) * 3;
        int boxCol = (col / 3) * 3;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (board[boxRow + i][boxCol + j] == ch)
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;

    vector<vector<char>> board(9, vector<char>(9));
    for (int i = 0; i < 9; ++i)
    {
        string row;
        cin >> row;
        for (int j = 0; j < 9; ++j)
        {
            board[i][j] = row[j];
        }
    }

    cout<<endl;

    sol.sudokuSolver(board);

    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            cout << board[i][j];
        }
        cout << endl;
    }

    return 0;
}