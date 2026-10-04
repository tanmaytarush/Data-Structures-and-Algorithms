/*
Question: Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized. Return the minimized largest sum of the split.

Example:
Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays. The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.

Approach:
- The problem can be solved using the binary search algorithm.
- We need to find the range of possible values for the minimized largest sum.
- The lower bound of the range is the maximum element in the array (as each subarray must contain at least one element).
- The upper bound of the range is the sum of all elements in the array (as the largest sum cannot exceed the total sum of the array).
- We perform binary search within this range to find the minimum largest sum that satisfies the given condition.
- In each iteration, we calculate the mid value of the range and check if it is a valid solution using a helper function.
- The helper function checks if it is possible to split the array into k subarrays with a maximum sum of mid.
- If it is possible, we update the answer and search the lower half of the range.
- If it is not possible, we search the upper half of the range.
- We continue this process until we find the optimal solution.

Time Complexity: O(n * log(sum of array))
Space Complexity: O(1)
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int countPartitions(vector<int> &arr, int maxcount)
{
    int n = arr.size();
    int partition = 1;
    int countPartitions = 0;

    for(int i=0; i<n; ++i)
    {
        if(countPartitions + arr[i] <= maxcount)
        {
            countPartitions += arr[i];
        }
        else
        {
            partition++;
            countPartitions = arr[i];
        }
    }
    return partition;
}

int minmaxSubarray(vector<int> &arr, int k)
{
    int n = arr.size();
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;

    if(k > n)
    {
        return -1;
    }

    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(countPartitions(arr, mid) > k)
        {
            low = mid + 1;
        }
        else
        {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;

    int k;
    cin>>k;

    vector<int> arr(n);
    for(int i=0; i<n; ++i)
    {
        cin>>arr[i];
    }

    int result1 = minmaxSubarray(arr, k);
    cout<<result1;

    return 0;
}
