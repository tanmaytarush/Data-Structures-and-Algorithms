/*
N Queen Problem | Return all Distinct Solutions to the N-Queens Puzzle

Problem Statement: The n-queens is the problem of placing n queens on n × n chessboard such that no two queens can attack each other. Given an integer n, return all distinct solutions to the n -queens puzzle. Each solution contains a distinct boards configuration of the queen's placement, where ‘Q’ and ‘.’ indicate queen and empty space respectively.

Examples
Input: N = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown below

Input : N = 1
Output: [["Q"]]
Explanation : There is only one way to place 1 queen on 1x1 chessboard.
*/

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;

bool isSafe(int row, int col, vector<string> &board, int n)
{
    int duprow = row;
    int dupcol = col;

    // for upper diagonal check
    while(row>=0 && col>=0)
    {
        if(board[row][col] == 'Q') return false;
        row--;
        col--;
    }

    // for left horizontal check
    col = dupcol;
    row = duprow;
    while(col >= 0)
    {
        if(board[row][col] == 'Q') return false;
        col--;
    }

    // for lower diagonal check
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

void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
{
    if(col == n)
    {
        ans.push_back(board);
        return;
    }

    for(int row = 0; row < n; ++row)
    {
        if(isSafe(row, col, board, n))
        {
            board[row][col] = 'Q';
            solve(col + 1, board, ans, n);
            board[row][col] = '.';
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

    solve(0, board, ans, n);
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