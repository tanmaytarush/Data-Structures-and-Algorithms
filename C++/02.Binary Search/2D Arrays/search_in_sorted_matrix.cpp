/*
QUESTION:-
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.



Example 1:
Input:  matrix = [[1,3,5,7]
                [10,11,16,20]
                [23,30,34,60]]
        target = 3
Output: true
*/

/*
APPROACH:-
-> Since the array is sorted we can use binary search low = 0 and high = n*m-1 i.e. total number of elements
-> Value at mid position could be accessed by matrix[mid/m][mid%m]
-> Then, follow the traditional binary search
*/

// CODE:-
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

bool searchMatrixBF(vector< vector<int> > &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();

    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            if(matrix[i][j] == target)
            {
                return true;
            }
        }
    }
    return false;
}

int binarySearch(vector<int> &arr, int target)
{
    int n = arr.size();
    int low = 0;
    int high = n-1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == target)
        {
            return mid;
        }
        else if(arr[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

bool searchMatrixBetter(vector< vector<int> > &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();

    for(int i=0; i<n; ++i)
    {
        if(matrix[i][0] <= target && target <= matrix[i][m-1])
        {
            int ans = binarySearch(matrix[i], target);
            if(ans != -1)
            {
                return true;
            }
        }
    }
    
    return false;
}


bool searchMatrixOptimal(vector< vector<int> > &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int low = 0;
    int high = (n*m) - 1;

    while(low <= high)
    {
        int mid = (low + high) / 2;
        int val = matrix[mid/m][mid%m];

        if(val == target)
        {
            return true;
        }

        else if(val > target)
        {
            high = mid - 1;
        }

        else
        {
            low = mid + 1;
        }
    }
    return false;
}


int main()
{
    int n, m;
    cin>>n>>m;

    int target;
    cin>>target;

    vector< vector<int> > matrix(n, vector<int>(m));

    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            cin>>matrix[i][j];
        }
    }

    bool result1 = searchMatrixBF(matrix, target);
    bool result2 = searchMatrixBetter(matrix, target);
    bool result3 = searchMatrixOptimal(matrix, target);

    cout<<result1<<" "<<result2<<" "<<result3;

    return 0;
}

// TIME COMPLEXITY = O(N^2) for brute force and O(NlogM) for better and O(log(M*N)) for optimal
// SPACE COMPLEXITY = O(1) for all