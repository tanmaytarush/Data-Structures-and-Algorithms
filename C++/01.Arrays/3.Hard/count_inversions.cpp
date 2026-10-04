/*
QUESTION:
Given an array of integers. Find the Inversion Count in the array.

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

Example 1:
Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).

Example 2:
Input: N = 5, arr[] = {2, 3, 4, 5, 6}
Output: 0
Explanation: As the sequence is already sorted, there is no inversion count.

APPROACH:
To find the inversion count in the array, we can utilize the merge sort algorithm. The idea is to divide the array into two halves, recursively count the inversions in each half, and then merge the two halves while counting the inversions across them.

CODE:
*/

#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
#include<map>

int countInversionsBF(vector<int> &arr)
{
    int n = arr.size();
    int count = 0;
    for(int i=0; i<n; ++i)
    {
        for(int j=i+1; j<n; ++j)
        {
            if(arr[i] > arr[j])
            {
                count++;
            }
        }
    }
    return count;
}


int merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid+1;

    int count = 0;

    while(left<=mid && right<=high)
    {
        if(arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            // count += (mid - left + 1);
            left++;
        }

        else
        {
            temp.push_back(arr[right]);
            count += (mid - left + 1);
            right++;
        }
    }

    while(left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while(right<=high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low; i<=high; ++i)
    {
        arr[i] = temp[i-low];
    }

    return count;
}

int mergeSort(vector<int> &arr, int low, int high)
{
    int mid = (low + high) / 2;
    int count = 0;
    
    if(low >= high)
    {
        return count;
    }

    count += mergeSort(arr, low, mid);
    count += mergeSort(arr, mid+1, high);
    count += merge(arr, low, mid, high);

    return count;
}

int countInversionOptimal(vector<int> &arr)
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

    int result1 = countInversionsBF(arr);
    int result2 = countInversionOptimal(arr);

    cout<<result1<<" "<<result2;

    return 0;
}

/*
TIME COMPLEXITY: O(N log N), where N is the size of the array.
SPACE COMPLEXITY: O(N).
*/
