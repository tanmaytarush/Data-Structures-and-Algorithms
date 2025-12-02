/*
Question: Given a sorted array arr of positive integers and an integer k, find the kth positive integer that is missing from the array.

Example:
Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.

Approach:
- We can solve this problem by finding the position in the array where the count of missing positive integers becomes greater than or equal to k.
- Initialize a variable `low` to 0 to represent the start of the array.
- Initialize a variable `high` to the size of the array minus 1 to represent the end of the array.
- Initialize a variable `pos` to -1 to store the position of the missing integer.
- Perform a binary search on the array:
  - Calculate the middle index `mid` using the formula `low + (high - low) / 2`.
  - If the count of missing positive integers in the subarray from the start to `mid` is less than k, update `low` to `mid + 1`.
  - Otherwise, update `pos` to `mid` and update `high` to `mid - 1`.
- After the binary search, check if a missing integer was found:
  - If `pos` is still -1, it means that the missing integer should be after the last element in the array. Return the sum of the size of the array and k.
  - Otherwise, return `pos + k` as the kth missing positive integer.

Time Complexity: O(log n), where n is the size of the array.
Space Complexity: O(1)

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int kthElementOpt(vector<int> &a, vector<int> &b, int k)
{
    int n1 = a.size();
    int n2 = b.size();

    if(n1 > n2) return kthElementOpt(b, a, k);

    int low = max(0, k-n2);
    int high = min(n1, k);

    while(low <= high)
    {
        int cut1 = (low + high) / 2;
        int cut2 = k - cut1;

        int l1 = INT_MIN;
        int l2 = INT_MIN;
        int r1 = INT_MAX;
        int r2 = INT_MAX;

        if(cut1 < n1) r1 = a[cut1];
        if(cut2 < n2) r2 = b[cut2];
        if(cut1 > 0) l1 = a[cut1 - 1];
        if(cut2 > 0) l2 = b[cut2 - 1];

        if(l1 <= r2 && l2<=r1)
        {
            return max(l1, l2);
        } 

        else if(l1 > r2) high = cut1 - 1;
        else low = cut1 + 1;
    }
    return -1;
}

int main()
{
    int n1, n2;
    cin>>n1>>n2;

    int n = (n1 + n2);

    int k;
    cin>>k;

    vector<int> arr1(n1);
    vector<int> arr2(n2);

    for(int i=0; i<n1; ++i)
    {
        cin>>arr1[i];
    }

    for(int i=0; i<n2; ++i)
    {
        cin>>arr2[i];
    }

    int result = kthElementOpt(arr1, arr2, k);

    cout<<result<<endl;

    return 0;
}

/*
Time Complexity: O(log(min(N, M)))
Space Complexity: O(1)
*/
