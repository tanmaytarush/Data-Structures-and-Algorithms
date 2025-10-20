/*
QUESTION:-

Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

*/

/*
APPROACH:-

To traverse the matrix in a spiral order, we can use the following steps:

1. Initialize four variables: top, bottom, left, and right to keep track of the boundaries of the current spiral.
2. Create an empty vector called 'ans' to store the elements in spiral order.
3. While the top boundary is less than or equal to the bottom boundary and the left boundary is less than or equal to the right boundary:
   - Traverse the top row from left to right and add each element to 'ans'.
   - Increment the top boundary.
   - Traverse the right column from top to bottom and add each element to 'ans'.
   - Decrement the right boundary.
   - Check if the top boundary is still less than or equal to the bottom boundary:
     - Traverse the bottom row from right to left and add each element to 'ans'.
     - Decrement the bottom boundary.
   - Check if the left boundary is still less than or equal to the right boundary:
     - Traverse the left column from bottom to top and add each element to 'ans'.
     - Increment the left boundary.
4. Return the 'ans' vector containing all the elements in spiral order.

*/

// CODE:
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

void spiralMatrix(vector<vector<int>> matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
    int top = 0;
    int bottom = n-1;
    int left = 0;
    int right = m-1;

    while(top<=bottom && left<=right)
    {
        for(int i=left; i<=right; ++i)
        {
            cout<<matrix[top][i];
        }
        top++;

        for(int i=top; i<=bottom; ++i)
        {
            cout<<matrix[i][right];
        }
        right--;

        if(top<=bottom)
        {
            for(int i=right; i>=left; --i)
            {
                cout<<matrix[bottom][i];
            }
            bottom--;
        }

        if(left<=right)
        {
            for(int i=bottom; i>=top; --i)
            {
                cout<<matrix[i][left];
            }
            left++;
        }
    }
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

    spiralMatrix(matrix);
    cout<<endl;
    return 0;
}

// TIME COMPLEXITY: O(N), where N is the total number of elements in the matrix.
// SPACE COMPLEXITY: O(1)
