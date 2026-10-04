/*
QUESTION:
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Example 2:
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

APPROACH:
To solve this problem in-place, we can follow these steps:
1. Use two boolean variables, firstRowZero and firstColZero, to check if the first row and first column contain zeros initially.
2. Iterate through the matrix and if an element is zero, set the corresponding element in the first row and first column to zero.
3. Iterate through the matrix again, excluding the first row and first column. If an element in the first row or first column is zero, set the current element to zero.
4. Finally, based on the values in firstRowZero and firstColZero, set the first row and first column to zero if needed.

TIME COMPLEXITY: O(m * n), where m and n are the dimensions of the matrix.
SPACE COMPLEXITY: O(1), as we are using constant extra space.

*/

// CODE:
#include<iostream>
#include<vector>
using namespace std;

void markRow(vector<vector<int>> &nums, int i)
{
    int m = nums[0].size();
    for(int j=0; j<m; ++j)  // Bug Fix: was i<m; ++i
    {
        if(nums[i][j] != 0)
        {
            nums[i][j] = -1;
        }
    }
}

void markCol(vector<vector<int>> &nums, int j)
{
    int n = nums.size();
    for(int i=0; i<n; ++i)
    {
        if(nums[i][j] != 0)
        {
            nums[i][j] = -1;
        }
    }
}

vector<vector<int>> setMatrixZerosBF(vector<vector<int>> &nums)
{
    int n = nums.size();
    int m = nums[0].size();

    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            if(nums[i][j] == 0)
            {
                markRow(nums, i);
                markCol(nums, j);
            }
        }
    }

    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            if(nums[i][j] == -1)
            {
                nums[i][j] = 0;
            }
        }
    }

    return nums;
}

vector<vector<int>> setMatrixZerosBetter(vector<vector<int>> &nums)
{
    int n = nums.size();
    int m = nums[0].size();

    vector<int> row(n, 0);
    vector<int> col(m, 0);

    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            if(nums[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            if(row[i] == 1 || col[j] == 1)  // Bug Fix: was &&
            {
                nums[i][j] = 0;
            }
        }
    }

    return nums;
}

vector<vector<int>> setMatrixZerosOpt(vector<vector<int>> &nums)
{
    int col0 = 1;
    int n = nums.size();
    int m = nums[0].size();
    // Step 1: Mark first row and column
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            if(nums[i][j] == 0)
            {
                nums[i][0] = 0;
                if(j != 0)
                    nums[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }  
    
    // Step 2: Mark cells based on first row/col
    for(int i=1; i<n; ++i)
    {
        for(int j=1; j<m; ++j)
        {
            if(nums[i][j] != 0)
            {
                if(nums[i][0] == 0 || nums[0][j] == 0)
                {
                    nums[i][j] = 0;
                }
            }
        }
    }
    
    // Step 3: Handle first row
    if(nums[0][0] == 0)
    {
        for(int j=0; j<m; ++j)
        {
            nums[0][j] = 0;
        }
    }
    
    // Step 4: Handle first column
    if(col0 == 0)
    {
        for(int i=0; i<n; ++i)
        {
            nums[i][0] = 0;
        }
    }

    return nums;
}

int main()
{
    int n, m;
    cin >> n >> m;

    // Bug Fix: Properly initialize 2D vector
    vector<vector<int>> arr(n, vector<int>(m));
    
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            cin >> arr[i][j];
        }
    }

    // Make copies since functions modify the matrix
    vector<vector<int>> arr1 = arr;
    vector<vector<int>> arr2 = arr;
    vector<vector<int>> arr3 = arr;

    vector<vector<int>> result1 = setMatrixZerosBF(arr1);
    vector<vector<int>> result2 = setMatrixZerosBetter(arr2);
    vector<vector<int>> result3 = setMatrixZerosOpt(arr3);

    // Complete main function using ITERATORS
    cout << "Brute Force Result:" << endl;
    for(auto it = result1.begin(); it != result1.end(); ++it)
    {
        for(auto jt = it->begin(); jt != it->end(); ++jt)
        {
            cout << *jt << " ";
        }
        cout << endl;
    }

    cout << "\nBetter Result:" << endl;
    for(auto it = result2.begin(); it != result2.end(); ++it)
    {
        for(auto jt = it->begin(); jt != it->end(); ++jt)
        {
            cout << *jt << " ";
        }
        cout << endl;
    }

    cout << "\nOptimal Result:" << endl;
    for(auto it = result3.begin(); it != result3.end(); ++it)
    {
        for(auto jt = it->begin(); jt != it->end(); ++jt)
        {
            cout << *jt << " ";
        }
        cout << endl;
    }

    return 0;
}


// TIME COMPLEXITY: O(m * n), where m and n are the dimensions of the matrix.
// SPACE COMPLEXITY: O(1), as we are using constant extra space.
