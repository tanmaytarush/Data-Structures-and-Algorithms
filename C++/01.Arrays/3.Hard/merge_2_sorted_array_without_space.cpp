/*
QUESTION:
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

Example 1:
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

APPROACH:
To merge two sorted arrays, nums1 and nums2, into nums1, we can use a two-pointer approach.
1. Initialize three pointers: i, j, and k, where i points to the last valid element of nums1, j points to the last element of nums2, and k points to the last index of the merged array nums1.
2. Start from the end of the arrays and compare the elements at i and j.
3. If the element at nums1[i] is greater than the element at nums2[j], swap it with the element at nums1[k], decrement i and k.
4. Otherwise, swap the element at nums2[j] with the element at nums1[k], decrement j and k.
5. Repeat steps 3 and 4 until all elements in nums1 and nums2 have been merged.
6. If there are still elements remaining in nums2 after merging, copy them to the remaining positions in nums1.
*/

// CODE:
#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<algorithm>

class Merge2Sorted
{
    private:
    void swapIfGreater(long long arr1[], long long arr2[], int ind1, int ind2)
    {
        if(arr1[ind1] > arr2[ind2])
        {
            swap(arr1[ind1], arr2[ind2]);
        }
    }

    public:

    void mergeBF(long long arr1[], long long arr2[], int n, int m)
    {
        long long arr3[n+m];
        int left = 0;
        int right = 0;
        int index = 0;
        
        while(left < n && right < m)
        {
            if(arr1[left] < arr2[right])
            {
                arr3[index] = arr1[left];
                left++;
                index++;
            }
            else
            {
                arr3[index] = arr2[right];
                index++;
                right++;
            }
        }

        while(left<n)
        {
            arr3[index] = arr1[left];
            index++;
            left++;
        }

        while(right<n)
        {
            arr3[index] = arr2[right];
            index++;
            right++;
        }

        for(int i=0; i<n+m; ++i)
        {
            if(i<n) arr1[i] = arr3[i];
            else arr2[i-n] = arr3[i];
        }
    }

    void mergeOptimal1(long long arr1[], long long arr2[], int n, int m)
    {
        int left = n-1;
        int right = 0;
        while(left>=0 && right<m)
        {
            if(arr1[left] > arr2[right])
            {
                swap(arr1[left], arr2[right]);
                left--;
                right++;
            }
            else
            {
                break;
            }
        }
        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);
    }

    void mergeOptimal2(long long arr1[], long long arr2[], int n, int m)
    {
        int len = (n+m);
        int gap = (len / 2) + (len % 2);
        while(gap > 0)
        {
            int left = 0;
            int right = left + gap;
            while(right < n)
            {
                // arr1 and arr2
                if(left<n && right>=n)
                {
                    swapIfGreater(arr1, arr2, left, right - n);
                }
                // arr2 and arr2
                else if(left>=n && right>=n)
                {
                    swapIfGreater(arr1, arr2, left - n, right - n);
                }
                // arr1 and arr1
                else
                {
                    swapIfGreater(arr1, arr1, left, right);
                }
                left++;
                right++;
            }
            if(gap == 1) break;
            gap = (gap / 2) + (gap % 2);
        }
    }
};


int main()
{
    int n;
    int m;
    cin>>n>>m;

    long long arr1[n];
    long long arr2[m];

    for(int i=0; i<n; ++i)
    {
        cin>>arr1[i];
    }

    for(int i=0; i<m; ++i)
    {
        cin>>arr2[i];
    }

    Merge2Sorted ms;

    ms.mergeBF(arr1, arr2, n, m);
    ms.mergeOptimal1(arr1, arr2, n, m);
    ms.mergeOptimal2(arr1, arr2, n, m);

    for(int i=0; i<n; ++i)
    {
        cout<<arr1[i]<<" ";
    }
    for(int i=0; i<m; ++i)
    {
        cout<<arr2[i]<<" ";
    }

    return 0;
}


/*
TIME COMPLEXITY: O(m + n), where m and n are the lengths of nums1 and nums2 respectively.
The merging process requires iterating through both arrays once.
SPACE COMPLEXITY: O(1)
The merge is performed in-place without using any additional space.

*/

