/*
QUESTION:
A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.

Example 1:
Input: mat = [[1,4],[3,2]]
Output: [0,1]
Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.

Example 2:
Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
Output: [1,1]
Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.

APPROACH:
- Perform a binary search on the columns of the matrix.
- Find the maximum element in each column and check if it is a peak element by comparing it with its adjacent elements.
- If it is a peak element, return its position [i, j].

TIME COMPLEXITY: O(m log(n)) or O(n log(m)) - Binary search is performed on the columns of the matrix.
SPACE COMPLEXITY: O(1) - Constant space is used.

CODE:
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxElement(vector<vector<int>> &matrix, int n, int m, int col)
{
    int maxValue = -1;
    int index = -1;

    for(int i=0; i<n; ++i)
    {
        if(matrix[i][col] > maxValue)
        {
            maxValue = matrix[i][col];
            index = i;
        }
    }

    return index;
}

vector<int> maxPeakGrid(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int low = 0;
    int high = m-1;

    while(low <= high)
    {
        int mid = (low + high) / 2;
        int maxCol = maxElement(matrix, n, m, mid);

        int left = mid - 1 >= 0 ? matrix[maxCol][mid - 1] : -1;
        int right = mid + 1 < m ? matrix[maxCol][mid + 1] : -1;

        if(matrix[maxCol][mid] > left && matrix[maxCol][mid] > right)
        {
            return {maxCol, mid};
        }

        else if(matrix[maxCol][mid] < left)
        {
            high = mid - 1;
        }

        else
        {
            low = mid + 1;
        }
    }

    return {-1, -1};
}


int main()
{
    int n;
    int m;
    cin>>n>>m;

    vector<vector<int>> matrix(n, vector<int>(m));
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            cin>>matrix[i][j];
        }
    }

    vector<int> result = maxPeakGrid(matrix);

    for(vector<int>::iterator it = result.begin(); it != result.end(); ++it)
    {
        cout<<*it;
    }

    return 0;
}

/*
TIME COMPLEXITY: O(m log(n)) or O(n log(m)) - Binary search is performed on the columns of the matrix.
SPACE COMPLEXITY: O(1) - Constant space is used.
*/