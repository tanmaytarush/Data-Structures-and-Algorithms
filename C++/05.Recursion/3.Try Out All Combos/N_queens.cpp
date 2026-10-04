/**
 * Question: The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 *
Example 1:


Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

 * Approach:
 * 1. Use backtracking to solve the n-queens puzzle.
 * 2. Start with an empty chessboard and try placing queens in each row, ensuring that no two queens threaten each other.
 * 3. Use row, column, and diagonal constraints to validate the queen placements.
 * 4. If a valid configuration is found, add it to the list of solutions.
 *
 * Time Complexity: O(N!), where N is the input parameter representing the size of the chessboard.
 *   - In the worst case, there can be N! possible configurations to check.
 *   - However, with the pruning technique used in backtracking, the actual runtime is much less than N! in most cases.
 *
 * Space Complexity: O(N^2), where N is the input parameter representing the size of the chessboard.
 *   - The space is used to store the chessboard configuration and the auxiliary arrays for tracking the used columns and diagonals.
 */

#define LOG(x) cerr<<#x<<" "<<x<<endl;

#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool isSafe(int row, int col, vector<vector<char>>&board, int n)
{
    // checking presence in the row
    for(int j=0; j<col; ++j)
    {
        if(board[row][j] == 'Q') return false;
    }

    // checking presence in the upper diagonal
    for(int i=row, j=col; i>=0 && j>=0; i--, j--)
    {
        if(board[i][j] == 'Q') return false;
    }

    // checking presence in the lower diagonal
    for(int i=row, j=col; i<n && j>=0; i++, j--)
    {
        if(board[i][j] == 'Q') return false;
    }

    return true;
}

void solve(int col, vector<vector<char>> &board, vector<vector<string>> &ans, int n)
{
    if(col == n)
    {
        vector<string> temp;
        for(int i=0; i<n; ++i)
        {
            string row(board[i].begin(), board[i].end());
            temp.push_back(row);
        }
        ans.push_back(temp);
        return;
    }

    for(int row=0; row<n; ++row)
    {
        if(isSafe(row, col, board, n))
        {
            board[row][col] = 'Q';
            solve(col+1, board, ans, n);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{   
    vector<vector<string>> ans;
    vector<vector<char>> board(n, vector<char>(n, '.'));
    solve(0, board, ans, n);
    return ans;
}

int main()
{
    int n;
    cin>>n; 

    vector<vector<string>> result = solveNQueens(n);

    for(auto &board : result)
    {
        for(auto &row : board)
        {
            cout<<row<<" ";
        }
        cout<<endl;
    }

    return 0;
}