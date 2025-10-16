/*
QUESTION:
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

Example:
Input: nums = [1,1,1], k = 2
Output: 2

APPROACH:
To find the total number of subarrays with sum equal to k, we can use the technique of prefix sum along with a hashmap.
1. Initialize a variable `count` to keep track of the count of subarrays with sum equal to k.
2. Initialize a variable `prefixSum` to keep track of the prefix sum while iterating through the array.
3. Initialize a hashmap `sumCount` to store the frequency of prefix sums encountered so far.
4. Set the initial prefix sum to 0 and set its count to 1 in the `sumCount` hashmap.
5. Iterate through the array and update the prefix sum by adding each element.
6. Check if the current prefix sum minus k exists in the `sumCount` hashmap. If it does, add the count of that prefix sum to the `count` variable.
7. Increment the count of the current prefix sum in the `sumCount` hashmap.
8. Finally, return the `count` variable as the total number of subarrays with sum equal to k.
*/

// CODE:
#include<iostream>
using namespace std;
#include<vector>
#include<map>

int subarrayNumBF(vector<int> &arr, int k)
{
    int n = arr.size();
    int count = 0;
    for(int i=0; i<n; ++i)
    {
        int sum = 0;
        for(int j=i; j<n; ++j)
        {
            sum += arr[j];
            if(sum == k)
            {
                count++;
            }
        }
    }
    return count;
}

int subarraySumOpt(vector<int> &arr, int k)
{
    int n = arr.size();
    unordered_map<int, int> mpp;
    int ans = 0;
    int preSum = 0;

    for(int i=0; i<arr.size(); ++i)
    {
        preSum += arr[i];
        
        if(preSum == k)
        {
            ans += 1;
        }

        if(mpp.find(preSum - k) != mpp.end())
        {
            ans += mpp[preSum - k];
        }

        mpp[preSum]++;
    }
    return ans;
}

int main()
{
    int n;
    int k;
    cin>>n;
    cin>>k;
    vector<int> arr(n);
    for(int i=0; i<n; ++i)
    {
        cin>>arr[i];
    }

    int res1 = subarrayNumBF(arr, k);
    int res2 = subarraySumOpt(arr, k);

    cout<<res1<<" "<<res2;
}

/*
TIME COMPLEXITY: O(n), where n is the size of the input array nums.
SPACE COMPLEXITY: O(n), as we are using a hashmap to store the prefix sums and their corresponding counts.
*/
