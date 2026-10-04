/*
QUESTION:
Given a sorted array Arr of size N and a number X, you need to find the number of occurrences of X in Arr.

Example:

Input:
N = 7, X = 2
Arr[] = {1, 1, 2, 2, 2, 2, 3}
Output: 4
Explanation: 2 occurs 4 times in the given array.
Example 2:

Input:
N = 7, X = 4
Arr[] = {1, 1, 2, 2, 2, 2, 3}
Output: 0
Explanation: 4 is not present in the given array.
*/

/*
APPROACH:
1. Use binary search to find the first occurrence of the target element.
2. Use binary search to find the last occurrence of the target element.
3. Return the difference between the indices of the first and last occurrence + 1.

CODE:
*/
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

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


int upperBound(vector<int> &arr, int target)
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

int countOccurences(vector<int> &arr, int target)
{
    int n = arr.size();
    int lb = lowerBound(arr, target);
    int ub = upperBound(arr, target);

    if(lb == n || arr[lb] != target)
    {
        return -1;
    }

    return ub - lb;
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

    int result = countOccurences(arr, target);

    cout<<result;

    return 0;
}

// TIME COMPLEXITY: O(log N), where N is the size of the array.
// SPACE COMPLEXITY: O(1).
