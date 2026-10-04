/*
QUESTION:-
You are given an array 'A' of size 'N' and an integer 'K'. You need to print the length of the longest subarray of array 'A' whose sum = 'K'.
Example:
Input: 'N' = 7 'K' = 3
'A' = [1, 2, 3, 1, 1, 1, 1]
Output: 3
Explanation: Subarrays whose sum = '3' are:
[1, 2], [3], [1, 1, 1], [1, 1, 1]
Here, the length of the longest subarray is 3, which is our final answer.
*/

/*
APPROACH:-
-> Use sliding window approach using two pointers start and end
-> Run a loop to traverse the entire array add from end and subtract from start when sum>k
-> If sum==k then, update the ans now, window size = end-start+1
*/

// CODE:-
#include<iostream>
using namespace std;
#include<vector>
#include<map>

int longestSubarrayBF(vector<int> &arr, int k)
{
    int n = arr.size();
    int len = 0;
    for(int i=0; i<n; ++i)
    {
        int sum = 0;
        for(int j=i; j<n; ++j)
        {
            sum += arr[j];
            if(sum == k)
            {
                len = max(len, j-i+1);
            }
        }
    }
    return len;
}

int longestSubarrayBetter(vector<int> &arr, long long k)
{
    map<long long, int> preSumMap;
    int maxLen = 0;
    long long sum = 0;
    for(int i=0; i<arr.size(); ++i)
    {
        sum += arr[i];
        if(sum == k)
        {
            maxLen = max(maxLen, i+1);
        }

        long long rem = sum - k;
        if(preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        if(preSumMap.find(sum) == preSumMap.end())
        {
            preSumMap[sum] = i;
        }
    }
    return maxLen;
}

int longestSubarrayOptimal(vector<int> &arr, int k)
{
    int sum = arr[0];
    int maxLen = 0;
    int left = 0;
    int right = 0;
    int n = arr.size();

    while(right<n)
    {
        while(left<=right && sum > k)
        {
            sum -= arr[left];
            left++;
        }
        if(sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }

        right++;
        if(right<n)
        {
            sum += arr[right];
        }
    }
    return maxLen;
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

    int k;
    cin>>k;

    int res1 = longestSubarrayBF(arr, k);
    int res2 = longestSubarrayBetter(arr, k);
    int res3 = longestSubarrayOptimal(arr, k);

    cout<<res1<<" "<<res2<<" "<<res3;
    return 0;
}

// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(0)