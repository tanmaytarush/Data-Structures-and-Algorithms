/*
QUESTION:-
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
*/

/*
APPROACH:-
-> Initialize three pointers: low at the beginning of the array, mid at the beginning of the array, and high at the end of the array.
-> Iterate through the array while the mid pointer is less than or equal to the high pointer:
1. If the current element at the mid pointer is 0 (red), we swap it with the element at the low pointer and increment both low and mid pointers. This ensures that red elements are moved to the left side of the array.
2. If the current element at the mid pointer is 1 (white), we simply increment the mid pointer. This keeps white elements in the middle of the array.
3. If the current element at the mid pointer is 2 (blue), we swap it with the element at the high pointer and decrement the high pointer. This ensures that blue elements are moved to the right side of the array.

Repeat step 2 until the mid pointer crosses the high pointer.
At the end of the algorithm, the array will be sorted in the desired order.
*/

// CODE:-
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

void sort012BF(vector<int> &arr, int n) // Normal count function
{
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;

    for(int i=0; i<n; ++i)
    {
        if(arr[i] == 0)
        {
            cnt0 += 1;
        }
        else if(arr[i] == 1)
        {
            cnt1 += 1;
        }
        else
        {
            cnt2 += 1;
        }
    }

    for(int i=0; i<cnt0; ++i)
    {
        arr[i] = 0;
    }
    for(int i=cnt0; i<cnt0+cnt1; ++i)
    {
        arr[i] = 1;
    }
    for(int i=cnt0+cnt1; i<n; ++i)
    {
        arr[i] = 2;
    }
}


void sort012Opt(vector<int> &arr, int n) // Dutch National Flag Algo
{
    int low = 0;
    int mid = 0;
    int high = n-1;

    while(mid<=high)
    {
        if(arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
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

    sort012BF(arr, n);
    sort012Opt(arr, n);

    for(int i=0; i<n; ++i)
    {
        cout<<arr[i]<<" ";
    }
}

// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(0)