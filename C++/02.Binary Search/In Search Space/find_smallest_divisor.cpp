/*
Question:
You are given an array of integers nums and an integer threshold. We need to find the smallest divisor
such that the result of dividing each element of the array by the divisor and summing up the results
is less than or equal to the threshold.

Example:
Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum of 17 (1+2+5+9) if the divisor is 1.
If the divisor is 4, we can get a sum of 7 (1+1+2+3).
If the divisor is 5, the sum will be 5 (1+1+1+2).
The smallest divisor that gives a sum less than or equal to the threshold is 5.

Approach:
- Start with a range of possible divisors from 1 to the maximum value in the array.
- Use binary search to find the smallest divisor that satisfies the given condition.
- Check the midpoint of the range and calculate the sum of divisions using the current divisor.
- If the sum is less than or equal to the threshold, update the answer and continue searching in the lower half of the range.
- If the sum is greater than the threshold, search in the upper half of the range.
- Repeat this process until the range is narrowed down to a single value, which will be the smallest divisor.

Code:
*/

#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

int sumOfD(vector<int> &arr, int div)
{
    int sum = 0;
    int n = arr.size();
    for(int i=0; i<n; ++i)
    {
        sum += ceil((double)arr[i] / div);
    }
    return sum;
}

int findSmallestDivisorOpt(vector<int> &arr, int limit)
{
    int n = arr.size();
    int low = 1;
    int high = *max_element(arr.begin(), arr.end());
    int ans = 1;

    // if(n > limit) return -1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(sumOfD(arr, mid) <= limit)
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

int findSmallestDivisorBF(vector<int> &arr, int threshold)
{
    int maxi = *max_element(arr.begin(), arr.end());
    int n = arr.size();
    for(int div = 1; div <= maxi; ++div)
    {
        int sum = 0;
        for(int i=0; i<n; ++i)
        {
            sum += ceil((double)arr[i] / div);
        }
        if(sum <= threshold)
        {
            return div;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;

    int limit;
    cin>>limit;

    vector<int> arr(n);
    for(int i=0; i<n; ++i)
    {
        cin>>arr[i];
    }

    int result1 = findSmallestDivisorBF(arr, limit);
    int result2 = findSmallestDivisorOpt(arr, limit);

    cout<<result1<<" "<<result2;

    return 0;
}

// Time Complexity: O(n log(max(nums)))
// Space Complexity: O(1)
