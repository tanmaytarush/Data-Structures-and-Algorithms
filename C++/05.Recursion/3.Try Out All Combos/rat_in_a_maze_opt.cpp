/*QUESTION:
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.

Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at 
(3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order 
we get DDRDRR DRDDRR.

Approach:
We can use a backtracking approach to find all possible paths.
1. Create a helper function called 'solve' that takes the current row index, column index, a string representing the current path, a vector of strings to store the paths, the matrix, and the size of the matrix.
2. In the 'solve' function:
   - If the current position is the destination (N-1, N-1), add the current path to the vector of paths and return.
   - Check if the current position is valid and not a blocked cell.
   - Mark the current position as visited (by setting its value to 0) to avoid revisiting it.
   - Recursively call the 'solve' function for the neighboring cells (left, right, up, down) with the updated path.
   - After the recursive calls, restore the original value of the current position to allow other paths to visit it.
3. Create the main function called 'findPath' that calculates and returns all possible paths from (0, 0) to (N-1, N-1).
   - If the source cell or the destination cell is blocked, return an empty vector.
   - Initialize an empty vector of strings to store the paths.
   - Call the 'solve' function with the initial position (0, 0), an empty path string, the vector of paths, the matrix, and the size of the matrix.
   - Return the vector of paths.
   
Time Complexity: O(3^(N^2)), where N is the size of the matrix. In the worst case, each cell can have three possible neighboring cells to explore.
Space Complexity: O(N^2), as we are using a vector of strings to store the paths.

CODE:*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;

void solve(int i, int j, vector<vector<int>>&a, int n, vector<string>&ans, string move, vector<vector<int>>&vis, int di[], int dj[])
{
    if(i==n-1 && j==n-1)
    {
        ans.push_back(move);
        return;
    }

    string dir = "DLRU";
    for(int index = 0; index<4; ++index)
    {
        int nexti = i + di[index];
        int nextj = j + dj[index];

        if(nexti>=0 && nextj>=0 && nexti<n && nextj<n && !vis[nexti][nextj] && a[nexti][nextj]==1)
        {
            vis[i][j] = 1;
            solve(nexti, nextj, a, n, ans, move+dir[index], vis, di, dj);
            vis[i][j] = 0;
        }
    }
}

vector<string> path(vector<vector<int>>&m, int n)
{
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    int di[] = {+1, 0, 0, -1};
    int dj[] = {0, -1, +1, 0};
    if(m[0][0] == 1) solve(0, 0, m, n, ans, "", vis, di, dj);
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

    vector<string> result = path(arr, n);

    for(auto &ds : result)
    {
        for(auto &it : ds)
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }

    return 0;
}