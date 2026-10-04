/*
QUESTION:
Given an integer array nums, return the number of reverse pairs in the array.
A reverse pair is a pair (i, j) where:
0 <= i < j < nums.length and
nums[i] > 2 * nums[j].

Example:
Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1

APPROACH:
To solve this problem, we can use the merge sort algorithm. While merging the two sorted subarrays, we can count the number of reverse pairs.

1. Define a variable 'rev_pair' to store the count of reverse pairs.
2. Implement the 'merge' function to merge two subarrays and count the reverse pairs.
3. Implement the 'mergesort' function to recursively divide the array into subarrays and perform merge sort.
4. Initialize 'rev_pair' to 0 and call the 'mergesort' function on the given array.
5. Return the 'rev_pair' as the result.

CODE:
*/
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<map>

int reversePairsBF(vector<int> &arr)
{
    int n = arr.size();
    int count = 0;
    for(int i=0; i<n; ++i)
    {
        for(int j=i+1; j<n; ++j)
        {
            if(arr[i] > (2 * arr[j]))
            {
                count++;
            }
        }
    }
    return count;
}

void merge(vector<int> &arr, int low, int mid, int high)
{
    int n = arr.size();
    vector<int> temp;
    int left = low;
    int right = mid+1;

    while(left<=mid && right<high)
    {
        if(arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
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
}

int countPairs(vector<int> &arr, int low, int mid, int high)
{
    int right = mid + 1;
    int n = arr.size();
    int count = 0;
    for(int i=low; i<=mid; ++i)
    {
        while(right <= high && arr[i] > 2 * arr[right]) right++;
        count += (right - mid + 1);  
    }
    return count;
}

int mergeSort(vector<int> &arr, int low, int high)
{
    int count = 0;
    int mid = (low + high)/2;
    if(low >= high) return count;
    count += mergeSort(arr, low, mid);
    count += mergeSort(arr, mid+1, high);
    count += countPairs(arr, low, mid, high);

    merge(arr, low, mid, high);

    return count;
}

int reversePairsOptimal(vector<int> &arr)
{
    int n = arr.size();
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

    int result1 = reversePairsBF(arr);
    int result2 = reversePairsOptimal(arr);

    cout<<result1<<" "<<result2;

    return 0;
}

/*
TIME COMPLEXITY: O(n log n), where n is the size of the array.
SPACE COMPLEXITY: O(n), where n is the size of the array.
*/
