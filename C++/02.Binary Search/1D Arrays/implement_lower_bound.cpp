/*
QUESTION:
Given a sorted array arr[] of size N without duplicates, and given a value x. Floor of x is defined as the largest element K in arr[] such that K is smaller than or equal to x. Find the index of K (0-based indexing).

Example 1:
Input:
N = 7, x = 0
arr[] = {1,2,8,10,11,12,19}
Output: -1
Explanation: No element less than 0 is found. So the output is "-1".

Example 2:
Input:
N = 7, x = 5
arr[] = {1,2,8,10,11,12,19}
Output: 1
Explanation: Largest number less than 5 is 2 (i.e K = 2), whose index is 1 (0-based indexing).

APPROACH:
- Initialize low as 0 and high as N-1.
- Iterate using a while loop until low is less than or equal to high.
- Calculate the mid index using mid = low + (high - low) / 2.
- Check if the element at mid index is less than or equal to x.
  - If true, update the answer as mid and move the low pointer to mid+1 to search for a larger element.
  - If false, update the high pointer to mid-1 to search in the lower half of the array.
- Finally, return the answer.


SIMILAR PROBLEM:

Problem statement
You are given a sorted array 'arr' of distinct values and a target value 'm'. You need to search for the index of the target value in the array.

Note:
1. If the value is present in the array, return its index.
2. If the value is absent, determine the index where it would be inserted in the array while maintaining the sorted order. 
3. The given array has distinct integers.
4. The given array may be empty.

Example:
Input:  arr = [1, 2, 4, 7],  m = 6 

Output: 3

Explanation: If the given array 'arr' is: [1, 2, 4, 7] and m = 6. We insert m = 6 in the array and get 'arr' as: [1, 2, 4, 6, 7]. The position of 6 is 3 (according to 0-based indexing)

CODE:
*/
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int lowerBoundBF(vector<int> &arr, int target)
{
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int answer = n;

    while(low <= high)
    {
        int mid = (low + high)/2;

        if(arr[mid] >= target) // Just this difference
        {
            answer = mid;
            high = mid - 1;
        }

        else
        {
            low = mid + 1;
        }
    }

    return answer;
}

int upperBoundBF(vector<int> &arr, int target)
{
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int answer = n;

    while(low <= high)
    {
        int mid = (low + high)/2;

        if(arr[mid] > target) // Just this difference
        {
            answer = mid;
            high = mid - 1;
        }

        else
        {
            low = mid + 1;
        }
    }

    return answer;
}

int main()
{
    int n;
    cin>>n;

    int target;
    cin>>target;

    vector<int> arr(n);
    for(int i=0; i<n; ++i)
    {
        cin>>arr[i];
    }

    int result1 = lowerBoundBF(arr, target);
    int result2 = upperBoundBF(arr, target);

    cout<<result1<<" "<<result2;

    return 0;
}

// TIME COMPLEXITY: O(log N)
// SPACE COMPLEXITY: O(1)
