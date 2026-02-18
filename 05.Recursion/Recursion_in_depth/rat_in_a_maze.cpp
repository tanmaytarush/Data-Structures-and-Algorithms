/*
Problem Statement: Given a grid of dimensions n x n. A rat is placed at coordinates (0, 0) and wants to reach at coordinates (n-1, n-1). Find all possible paths that rat can take to travel from (0, 0) to (n-1, n-1). The directions in which rat can move are 'U' (up) , 'D' (down) , 'L' (left) , 'R' (right).
The value 0 in grid denotes that the cell is blocked and rat cannot use that cell for travelling, whereas value 1 represents that rat can travel through the cell. If the cell (0, 0) has 0 value, then mouse cannot move to any other cell.

Examples
Input: n = 4 , grid = [ [1, 0, 0, 0] , [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1] ]
Output: ["DDRDRR" , "DRDDRR"]
Explanation: The rat has two different path to reach (3, 3).
The first path is (0, 0) => (1, 0) => (2, 0) => (2, 1) => (3, 1) => (3, 2) => (3, 3).
The second path is (0,0) => (1,0) => (1,1) => (2,1) => (3,1) => (3,2) => (3,3).

Input: n = 2 , grid = [[1, 0] , [1, 0]]
Output: []
Explanation: There is no path that rat can choose to travel from (0,0) to (1,1).
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;

void solve(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string move, vector<vector<int>> &vis)
{
    if(i==n-1 && j==n-1)
    {
        ans.push_back(move);
        return;
    }

    //downward
    if((i+1)<n && !vis[i+1][j] && a[i+1][j] == 1)
    {
        vis[i][j] = 1;
        solve(i+1, j, a, n, ans, move + 'D', vis);
        vis[i][j] = 0;
    }

    //left
    if((j-1)>=0 && !vis[i][j-1] && a[i][j-1] == 1)
    {
        vis[i][j] = 1;
        solve(i, j-1, a, n, ans, move + 'L', vis);
        vis[i][j] = 0;
    }

    //right
    if((j+1)<n && !vis[i][j+1] && a[i][j+1] == 1)
    {
        vis[i][j] = 1;
        solve(i, j+1, a, n, ans, move + 'R', vis);
        vis[i][j] = 0;
    }

    //upper
    if((i-1)>=0 && !vis[i-1][j] && a[i-1][j] == 1)
    {
        vis[i][j] = 1;
        solve(i-1, j, a, n, ans, move + 'U', vis);
        vis[i][j] = 0;
    }
}

vector<string> ratInAMaze(vector<vector<int>> &m, int n)
{
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    
    if(m[0][0] == 1)
    {
        solve(0, 0, m, n, ans, "", vis);
    }

    return ans;
}

int main()
{
    int n;
    cin>>n;

    vector<vector<int>> arr(n, vector<int>(n));

    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            cin>>arr[i][j];
        }
    }

    vector<string> result = ratInAMaze(arr, n); 

    for(auto &c : result)
    {
        cout<<c<<endl;
    }

    return 0;
}