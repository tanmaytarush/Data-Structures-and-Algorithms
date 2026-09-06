/*

N Queen
Subscribe to TUF+

Hints
Company
The challenge of arranging n queens on a n × n chessboard so that no two queens attack one another is known as the "n-queens puzzle."



Return every unique solution to the n-queens puzzle given an integer n. The answer can be returned in any sequence.



Every solution has a unique board arrangement for the placement of the n-queens, where 'Q' and '.' stand for a queen and an empty space, respectively.



Here are the attack rules for N-Queens:

Same Row - No two queens can be in the same row.
Same Column - No two queens can be in the same column.
Same Diagonal (top-left to bottom-right) - No two queens can share the same diagonal where (row - col) is equal.
Same Anti-Diagonal (top-right to bottom-left) - No two queens can share the same anti-diagonal where (row + col) is equal.

Example 1

Input : n = 4

Output : [[".Q.." , "...Q" , "Q..." , "..Q."] , ["..Q." , "Q..." , "...Q" , ".Q.."]]

Explanation : There are two possible combinations as shown below.





Example 2

Input : n = 2

Output : [ [] ]

Explanation : There is no possible combination for placing two queens on a board of size 2*2.

*/

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution
{
    public:
    bool isSafe(int row, int col, vector<string>&board, int n)
    {
        // left upper diagonal
        int duprow = row;
        int dupcol = col;
        while(row >= 0 && col >= 0)
        {
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }

        // same row
        row = duprow;
        col = dupcol;
        while(col >= 0)
        {
            if(board[row][col] == 'Q') return false;
            col --;
        }

        // left lower diagonal
        row = duprow;
        col = dupcol;
        while(row<n && col>=0) 
        {
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }

        return true;
    }

    void solve(int col, vector<string>&board, int n, vector<vector<string>>&ans)
    {
        if(col == n)
        {
            vector<string> temp;
            for(int i=0; i<n; i++)
            {
                string row(board[i].begin(), board[i].end());
                temp.push_back(row);
            }
            ans.push_back(temp);
            return;
        }

        for(int row=0; row<n; row++)
        {
            if(isSafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                solve(col + 1, board, n, ans);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> NQueens(int n)
    {
        vector<vector<string>> ans;

        vector<string> board(n, string(n, '.'));

        solve(0, board, n, ans);

        return ans;
    }
};

int main()
{
    Solution sol;
    int n;
    cin >> n;

    // vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans = sol.NQueens(n);

    for(const auto &solution : ans)
    {
        for(const auto &row : solution)
        {
            cout << row << "\n";
        }
        cout << "\n";
    }

    return 0;
}


// Time -> O(3N)*O(N!)
// Space -> O(N^2)