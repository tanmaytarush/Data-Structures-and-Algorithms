#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;

void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n)
{
    if(col == n)
    {
        ans.push_back(board);
        return;
    }

    for(int row=0; row<n; ++row)
    {
        if(leftRow[row] == 0 && upperDiagonal[row+col] == 0 && lowerDiagonal[n-1 + col - row] == 0)
        {
            board[row][col] = 'Q';
            leftRow[row] = 1;
            upperDiagonal[col + row] = 1;
            lowerDiagonal[n-1 + col - row] = 1;
            solve(col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
            board[row][col] = '.';
            leftRow[row] = 0;
            upperDiagonal[col + row] = 0;
            lowerDiagonal[n-1 + col - row] = 0;
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for(int i=0; i<n; ++i)
    {
        board[i] = s;
    } 

    vector<int> leftRow(n, 0);
    vector<int> upperDiagonal(2*n-1, 0);
    vector<int> lowerDiagonal(2*n-1, 0);

    solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
    return ans;
} 

int main()
{
    int n;
    cin>>n;

    vector<vector<string>> result = solveNQueens(n);

    for(vector<vector<string>>::iterator it = result.begin(); it != result.end(); ++it)
    {
        for(vector<string>::iterator jt = it->begin(); jt != it->end(); ++jt)
        {
            cout<<*jt<<" ";
        }

        cout<<endl;
    }

    return 0;
}