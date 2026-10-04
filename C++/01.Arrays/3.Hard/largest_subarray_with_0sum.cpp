/*
QUESTION:
Given an array with both positive and negative integers, we need to compute the length of the largest subarray with a sum of 0.

Example:
Input:
N = 8
A[] = {15, -2, 2, -8, 1, 7, 10, 23}
Output: 5
Explanation: The largest subarray with a sum of 0 will be -2, 2, -8, 1, 7.

APPROACH:
To find the length of the largest subarray with a sum of 0, we can use a technique called prefix sum.
1. Create a prefix sum array of the same size as the input array.
2. Initialize a map to store the prefix sum and its corresponding index. Initialize it with an entry for prefix sum 0 and index -1.
3. Iterate through the input array and calculate the prefix sum by adding each element.
4. For each prefix sum encountered, check if it exists in the map. If it does, update the answer by taking the maximum of the current answer and the difference between the current index and the index stored in the map for that prefix sum.
5. If the prefix sum is not found in the map, add it to the map with its corresponding index.
6. Finally, return the answer as the length of the largest subarray with a sum of 0.
*/

// CODE:
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int longestSubarray(vector<int> &arr)
{
    unordered_map<int, int> mpp;
    int n = arr.size();
    int maximum = 0;
    int sum = 0;

    for(int i=0; i<n; ++i)
    {
        sum += arr[i];
        if(sum == 0)
        {
            maximum = i+1; // If zero exists then simply return length to the maximum
        }
        else
        {
            if(mpp.find(sum) != mpp.end())
            {
                maximum = max(maximum, i - mpp[sum]); // If element exists that means the preSum exists, (i - mpp[sum]) is the maximum
            }
            else
            {
                mpp[sum] = i; // If element doesn't exist then push that (element, index) to the hashmap
            }
        }
    }
    return maximum;
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

    int result = longestSubarray(arr);
    cout<<result;

    return 0;
}

/*
TIME COMPLEXITY: O(n), where n is the size of the input array A.
SPACE COMPLEXITY: O(n), as we are using a map to store the prefix sums and their corresponding indices.
*/
