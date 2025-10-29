/*
QUESTION:
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

APPROACH:
1. Use lower_bound to find the index of the first occurrence of the target in the array.
2. If the target is not found, return [-1, -1].
3. Use upper_bound to find the index of the last occurrence of the target in the array.
4. Return the range [first, last-1] as the starting and ending positions.

CODE:
*/
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int lowerBound(vector<int> &arr, int target)   // first occurence (>= target)
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

int upperBound(vector<int> &arr, int target)  // last occurence (> target)
{
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int ans = n;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] > target)
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

pair<int, int> first_last_occurence(vector<int> &arr, int target)
{
    int n = arr.size();
    int lb = lowerBound(arr, target);
    int ub = upperBound(arr, target);

    if(lb == n || arr[lb] != target) // Edge case
    {
        return std::make_pair(-1, -1);
    }

    return std::make_pair(lb, ub - 1);
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

    pair<int, int> result = first_last_occurence(arr, target);

    cout<<result.first<<" "<<result.second;

    return 0;
}

// TIME COMPLEXITY: O(log n)
// SPACE COMPLEXITY: O(1)
