/*Question:
Given an array containing N integers and an integer K, find the length of the longest subarray with the sum of the elements equal to K.

Example:
Input:
A[] = {10, 5, 2, 7, 1, 9}
K = 15
Output:
4
Explanation:
The sub-array is {5, 2, 7, 1}.

Approach:
To solve this problem, we can use a prefix sum approach along with a hashmap to keep track of the prefix sums encountered so far. We iterate through the array and maintain a prefix sum variable. At each index, we check if the prefix sum equals K, in which case we update the maximum length of the subarray found so far. Additionally, we check if the current prefix sum minus K exists in the hashmap. If it does, it means there is a subarray between the previous occurrence of the prefix sum minus K and the current index that sums up to K. We update the maximum length accordingly. We store the prefix sums and their corresponding indices in the hashmap.

Code:
*/

#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<algorithm>

int longestSubarrayMap(vector<int> &arr, int k)
{
    int n = arr.size();
    map<int, int> mp;
    int sum = 0;
    int ans = 0;
    int rem = 0;
    for(int i=0; i<n; ++i)
    {
        sum += arr[i];
        rem = sum - k;

        if(sum == k) ans = max(ans, i+1);

        if(!mp.count(sum)) mp[sum] = i;

        auto it = mp.find(rem);
        if(it != mp.end())
        {
            ans = max(ans, i - it->second);
        }
    }

    return ans;
}

int longestSubarrayBF(vector<int> &arr, int k)
{
    int n = arr.size();
    int sum = 0;
    int result = 0;
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            sum = arr[i] + arr[j];

            if(sum < k) j++;
            else if(sum > k) 
            {
                i++; j++;
            }
            else 
            {
                result = j-i+1;
            }
        }
    }
    return result;
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

    int result1 = longestSubarrayBF(arr, k);
    int result2 = longestSubarrayMap(arr, k);

    cout<<result1<<" "<<result2;

    return 0;
}

/*
Time Complexity: The code iterates through the array once, resulting in a time complexity of O(N), where N is the size of the array.
Space Complexity: The code uses an unordered map to store the prefix sums and their corresponding indices. In the worst case, all elements of the array could be distinct, leading to a space complexity of O(N) to store the prefix sums in the map.
*/

