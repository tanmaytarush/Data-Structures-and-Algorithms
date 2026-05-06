/*

1861. Rotating the Box -> https://leetcode.com/problems/rotating-the-box/description/?envType=daily-question&envId=2026-05-06

You are given an m x n matrix of characters boxGrid representing a side-view of a box. Each cell of the box is one of the following:

A stone '#'
A stationary obstacle '*'
Empty '.'
The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not affect the stones' horizontal positions.

It is guaranteed that each stone in boxGrid rests on an obstacle, another stone, or the bottom of the box.

Return an n x m matrix representing the box after the rotation described above.

*/

#define LOG(x) cerr<<#x<<" "<<x<<endl;
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution
{
    public:
    vector<vector<char>> rotateBoxes(vector<vector<char>> &arr)
    {
        int n = arr.size();
        int m = arr[0].size();

        // transpose a matrix
        vector<vector<char>> transposed(m, vector<char>(n));
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<m; ++j)
            {
                transposed[j][i] = arr[i][j];
            }
        }

        for(int i=0; i<m; ++i)
        {
            reverse(transposed[i].begin(), transposed[i].end());
        }


        // determine and execute gravity
        for(int j=0; j<n; ++j) // traverse column wise
        {
            int bottom = m-1;
            for(int i=m-1; i>=0; --i)
            {
                if(transposed[i][j] == '*')
                {
                    bottom = i-1;
                }
                else if(transposed[i][j] == '#')
                {
                    swap(transposed[i][j], transposed[bottom][j]);
                    bottom--;
                }
            }
        }

        return transposed;
    }
};

int main()
{
    Solution sol;
    int n;
    int m;
    cin>>n>>m;

    vector<vector<char>> arr(n, vector<char>(m));
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            cin>>arr[i][j];
        }
    }

    vector<vector<char>> result = sol.rotateBoxes(arr);

    for(vector<vector<char>>::iterator it = result.begin(); it<=result.end(); ++it)
    {
        for(vector<char>::iterator jt = it->begin(); jt<=it->end(); ++jt)
        {
            cout<<*jt<<" ";
        }
        cout<<endl;
    }

    return 0;
}
