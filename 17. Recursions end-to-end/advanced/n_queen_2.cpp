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
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
    public:
    void solve(int col, int n, vector<string>&board, 
        vector<int>&left, vector<int>&upperDiagonal, vector<int>&lowerDiagonal, vector<vector<string>>&ans)
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

        for(int row=0; row<n; ++row)
        {
            if(left[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[n-1 + col - row]==0)
            {
                // place the queen
                board[row][col] = 'Q';

                // mark the co-ordinates
                left[row] = 1;
                lowerDiagonal[row+col] = 1;
                upperDiagonal[n-1 + col - row] = 1;

                solve(col + 1, n, board, left, upperDiagonal, lowerDiagonal, ans);

                // remove the queen
                board[row][col] = '.';

                // unmark the co-ordinates
                left[row] = 0;
                lowerDiagonal[row+col] = 0;
                upperDiagonal[n-1 + col - row] = 0;
            } 
        }
    }

    vector<vector<string>> NQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        vector<int> left(2*n+1);
        vector<int> lowerDiagonal(2*n+1);
        vector<int> upperDiagonal(2*n+1);
 
        solve(0, n, board, left, lowerDiagonal, upperDiagonal, ans);

        return ans;
    }
};

int main()
{
    Solution sol;

    int n;
    cin>>n;

    vector<vector<string>> result = sol.NQueens(n);

    for(vector<vector<string>>::iterator it = result.begin(); it != result.end(); ++it)
    {
        for(vector<string>::iterator jt = it->begin(); jt != it->end(); ++jt)
        {
            cout<<*jt<<" ";
            cout<<endl;
        }
        cout<<endl;
    }

    return 0;
}