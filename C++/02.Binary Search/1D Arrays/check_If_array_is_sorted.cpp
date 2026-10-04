/*
QUESTION:
Given an array arr[] of size N, check if it is sorted in non-decreasing order or not.

APPROACH:
- We can use a recursive approach to check if the array is sorted in non-decreasing order or not.
- The base case for recursion is when the subarray has only one element or when the subarray is empty, in which case we consider it to be sorted.
- For a non-empty subarray, we compare the middle element with its next element. If they are in non-decreasing order and both the left and right subarrays are also sorted, then we consider the entire array to be sorted.
- We recursively check the left and right subarrays using the same approach.
- If any of the recursive calls returns false, we return false. Otherwise, we return true.

Example:

Input:
N = 5
arr[] = {10, 20, 30, 40, 50}
Output: 1
Explanation: The given array is sorted.

CODE:
*/
#include<iostream>
#include<vector>
#include<map>
using namespace std;

bool checkArraySorted(vector<int> arr, int low, int high)
{
    int n = arr.size();
    int mid = low + (high - low)/2;

    if(low >= high) return true;
    if(arr[mid] > arr[mid + 1]) return false;

    return checkArraySorted(arr, low, mid) && checkArraySorted(arr, mid + 1, high);
}

bool isSorted(vector<int> &arr)
{
    int n = arr.size();
    if(n<=1) return true;
    return checkArraySorted(arr, 0, n-1);
}

int main()
{
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; ++i)
    {
        cin>>arr[i];
    }

    bool result = isSorted(arr);

    cout<<result;

    return 0;
}

// TIME COMPLEXITY: O(log N)
// SPACE COMPLEXITY: O(log N) (for recursion stack)
