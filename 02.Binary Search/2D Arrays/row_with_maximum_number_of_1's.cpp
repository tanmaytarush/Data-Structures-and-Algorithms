/*
QUESTION:-
Given a boolean 2D array of n x m dimensions where each row is sorted. Find the 0-based index of the first row that has the maximum number of 1's.

Example 1:

Input:
N = 4 , M = 4
Arr[][] = {{0, 1, 1, 1},
           {0, 0, 1, 1},
           {1, 1, 1, 1},
           {0, 0, 0, 0}}
Output: 2
Explanation: Row 2 contains 4 1's (0-based indexing).
*/

/*
APPROACH:-
-> We can use two pointer i and j which indicates current row and col
-> As we know the matrix is row-wise sorted we can intilaize j=m-1 i.e. last col and i=0 i.e. first row
-> Now, the idea is we will keep moving left j while we occur 1 and if 0 is found we will check in next row
-> The last row where we encountered 1 will be our ans

                {*0, *1, *1, *1}
                {*0,  0,  1,  1}
out of matrix  *{*1,  1,  1,  1} ---> ans
                {0,  0,  0,  0}



*/

// CODE:-

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int rowWithMax1sBF(vector<vector<int> > &arr, int n, int m)
{
    int cntMax = -1;
    int index = -1;

    for(int i=0; i<n; ++i)
    {
        int cnt_ones = 0;
        for(int j=0; j<m; ++j)
        {
            if(arr[i][j] == 1)
            {
                cnt_ones++;
            }
        }
        if(cnt_ones > cntMax)
        {
            cntMax = cnt_ones;
            index = i;
        }
    }
    return index;
}


int lowerBound(vector<int> &arr, int target)
{
    int n = arr.size();
    int low = 0;
    int high = n-1;

    int ans = n;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] >= target)
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


int rowWithMax1s(vector<vector<int> > &arr, int n, int m)
{
    int cntMax = 0;
    int index = -1;

    for(int i=0; i<n; ++i)
    {
        int lb = lowerBound(arr[i], 1);
        int cnt_ones = m - lb;

        if(cnt_ones > cntMax)
        {
            cntMax = cnt_ones;
            index = i;
        }
    }

    return index;
}


int main()
{
    int n, m;
    cin>>n>>m;


    vector<vector<int> > arr(n, vector<int>(m));

    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            cin>>arr[i][j];
        }
    }

    int result1 = rowWithMax1sBF(arr, n, m);
    int result2 = rowWithMax1s(arr, n, m);

    cout<<result1<<" "<<result2;

    return 0; 
}

// TIME COMPLEXITY = O(N+M)
// SPACE COMPLEXITY = O(0)