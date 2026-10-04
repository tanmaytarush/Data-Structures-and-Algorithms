/*
QUESTION:-

You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

Example 2:
Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

*/

/*
APPROACH:-

To rotate the image by 90 degrees clockwise in-place, we can follow these steps:

1. Transpose the matrix: Iterate over the matrix and swap each element (i, j) with its corresponding element (j, i). This step transforms rows into columns.

2. Reverse each row: Iterate over each row in the transposed matrix and reverse the elements. This step ensures the rotation in a clockwise direction.

*/

// CODE: 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Brute Force: Create new rotated matrix
vector<vector<int>> rotateMatrixBF(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<vector<int>> rotated(n, vector<int>(n, 0));
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            rotated[j][n-i-1] = matrix[i][j];
        }
    }
    return rotated;
}
// TIME: O(N²), SPACE: O(N²)

void reverseArr(vector<int> &arr)
{
    int n = arr.size();
    int startPtr = 0;
    int endPtr = n-1;
    while(startPtr < endPtr)
    {
        swap(arr[startPtr], arr[endPtr]);
        startPtr++;
        endPtr--;
    }
}

// Optimal: In-place rotation via transpose + reverse
void rotateMatrixOpt(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    
    // Step 1: Transpose
    for(int i=0; i<n; ++i)
    {
        for(int j=i+1; j<n; ++j)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Step 2: Reverse each row
    for(int i=0; i<n; ++i)
    {
        reverseArr(matrix[i]);
    }
}
// TIME: O(N²), SPACE: O(1)

int main()
{
    int n;
    cin>>n;

    vector<vector<int>> matrix(n, vector<int>(n));

    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            cin>>matrix[i][j];
        }
    }

    vector<vector<int>> matrixBF = matrix;

    vector<vector<int>> rotated = rotateMatrixBF(matrixBF);
    cout << "Brute Force Result:" << endl;
    for(auto it = rotated.begin(); it!=rotated.end(); ++it)
    {
        for(auto jt = it->begin(); jt!=it->end(); ++jt)
        {
            cout<<*jt<<" ";
        }
        cout<<endl;
    }

    cout << "\nOptimal Result:" << endl;
    rotateMatrixOpt(matrix);
    for(vector<vector<int>>::iterator it = matrix.begin(); it != matrix.end(); ++it)
    {
        for(vector<int>::iterator jt = it->begin(); jt != it->end(); ++jt)
        {
            cout << *jt << " ";
        }
        cout << endl;
    }
    return 0;
}

// TIME COMPLEXITY = O(N^2), where N is the size of the matrix.
// SPACE COMPLEXITY = O(1)
