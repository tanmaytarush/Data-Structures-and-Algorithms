/*QUESTION:

Given a row-wise sorted matrix of size R*C where R and C are always odd, find the median of the matrix.

Example:

Input:
R = 3, C = 3
M = [[1, 3, 5], 
     [2, 6, 9], 
     [3, 6, 9]]
Output: 5
Explanation: Sorting matrix elements gives us {1, 2, 3, 3, 5, 6, 6, 9, 9}. Hence, 5 is the median. 

APPROACH:

To find the median of a row-wise sorted matrix, we can follow these steps:

1. Initialize two variables, `low` and `high`, to keep track of the minimum and maximum elements in the matrix.
2. Iterate through each row and update `low` with the minimum value of the first element in each row and `high` with the maximum value of the last element in each row.
3. Perform binary search between `low` and `high`.
4. For each iteration of binary search, count the number of elements in the matrix that are less than or equal to the mid value.
   - If the count is less than the desired median position, update `low` to mid + 1.
   - If the count is greater than or equal to the desired median position, update the answer with the mid value and update `high` to mid - 1.
5. Repeat steps 3-4 until `low` becomes greater than `high`.
6. Return the final answer as the median of the matrix.

CODE:*/

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<math.h>

int upperBound(vector<int> &arr, int ele)
{
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int ans = n;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] > ele)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int countRequiredElements(vector<vector<int>> &matrix, int ele)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int count = 0;

    for(int i=0; i<n; ++i)
    {
        count += upperBound(matrix[i], ele);
    }
    return count;
}

int median2D(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int low = INT_MIN;
    int high = INT_MAX;

    for(int i=0; i<n; ++i)
    {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][m-1]);
    }

    int required = (n*m)/2;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        int countRequired = countRequiredElements(matrix, mid);

        if(countRequired <= required)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
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

    int result = median2D(matrix);

    cout<<result;
}

/*
TIME COMPLEXITY: O(R * log(C) * log(range)), where R is the number of rows, C is the number of columns, and range is the difference between the minimum and maximum elements in the matrix. 
                The algorithm performs binary search on each row, which takes O(log(C)) time, and the outer binary search iterates log(range) times.
SPACE COMPLEXITY: O(1) as the algorithm only uses a constant amount of additional space to store variables.
*/