/*
3193. Count the Number of Inversions
Hard
Topics
premium lock icon
Companies
Hint
You are given an integer n and a 2D array requirements, where requirements[i] = [endi, cnti] represents the end index and the inversion count of each requirement.

A pair of indices (i, j) from an integer array nums is called an inversion if:

i < j and nums[i] > nums[j]
Return the number of permutations perm of [0, 1, 2, ..., n - 1] such that for all requirements[i], perm[0..endi] has exactly cnti inversions.

Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:

Input: n = 3, requirements = [[2,2],[0,0]]

Output: 2

Explanation:

The two permutations are:

[2, 0, 1]
Prefix [2, 0, 1] has inversions (0, 1) and (0, 2).
Prefix [2] has 0 inversions.
[1, 2, 0]
Prefix [1, 2, 0] has inversions (0, 2) and (1, 2).
Prefix [1] has 0 inversions.
Example 2:

Input: n = 3, requirements = [[2,2],[1,1],[0,0]]

Output: 1

Explanation:

The only satisfying permutation is [2, 0, 1]:

Prefix [2, 0, 1] has inversions (0, 1) and (0, 2).
Prefix [2, 0] has an inversion (0, 1).
Prefix [2] has 0 inversions.
Example 3:

Input: n = 2, requirements = [[0,0],[1,0]]

Output: 1

Explanation:

The only satisfying permutation is [0, 1]:

Prefix [0] has 0 inversions.
Prefix [0, 1] has no inversions.
 

Constraints:

2 <= n <= 300
1 <= requirements.length <= n
requirements[i] = [endi, cnti]
0 <= endi <= n - 1
0 <= cnti <= 400
The input is generated such that there is at least one i such that endi == n - 1.
The input is generated such that all endi are unique.


LEETCODE - https://leetcode.com/problems/count-the-number-of-inversions/description/
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
using namespace std;

int merge(vector<int> &arr, int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;
    vector<int> temp;
    int count = 0;

    while(left <= mid && right <= high)
    {
        if(arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            count += (mid - left + 1); // all right elements are valid pairs in first half, count all
            right++;
        }
    }

    while(left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while(right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low; i<=high; ++i)
    {
        arr[i] = temp[i - low];
    }

    return count;
}

int mergeSort(vector<int> &arr, int low, int high)
{
    int count = 0;
    if(low >= high) return 0;
    int mid = (low + high) / 2;

    count += mergeSort(arr, low, mid);
    count += mergeSort(arr, mid+1, high);
    count += merge(arr, low, mid, high);

    return count;
}

int mergeSortAlgorithm(vector<int> &arr, int n)
{
    return mergeSort(arr, 0, n-1);
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

    int result = mergeSortAlgorithm(arr, n);
    cout<<result;

    return 0;
}