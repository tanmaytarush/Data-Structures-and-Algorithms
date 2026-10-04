/*
QUESTION:
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

APPROACH:
Since the array is sorted and every element appears exactly twice except for one element, we can use binary search to find the single element.
1. Initialize low = 0 and high = nums.size()-1, where nums is the input array.
2. While low < high, calculate mid = low + (high - low) / 2.
3. Check if mid is an even index (mid % 2 == 0).
    - If nums[mid] is equal to nums[mid + 1], it means the single element is on the right side, so update low = mid + 1.
    - Otherwise, the single element is on the left side, so update high = mid.
4. If mid is an odd index (mid % 2 == 1).
    - If nums[mid] is not equal to nums[mid + 1], it means the single element is on the right side, so update low = mid + 1.
    - Otherwise, the single element is on the left side, so update high = mid.
5. After the loop ends, low will be pointing to the single element.
6. Return nums[low] as the result.

CODE:
*/
#include<iostream>
#include<vector>
#include<map>
using namespace std;

int singleElementBF(vector<int> &arr)
{
    int n = arr.size();
    if(n==1)
    {
        return arr[0];
    }

    if(arr[0] != arr[1]) return arr[0];
    if(arr[n-1] != arr[n-2]) return arr[n-1];

    for(int i=0; i<n; ++i)
    {
        if((arr[i]!=arr[i-1]) && (arr[i]!=arr[i+1]))
        {
            return arr[i];
        } 
    }
    return -1;
}


int singleElementOpt(vector<int> &arr)
{
    int n = arr.size();

    if(n == 1) return arr[0];
    if(arr[0] != arr[1]) return arr[0];
    if(arr[n-1] != arr[n-2]) return arr[n-1];

    int low = 1;
    int high = n-2;

    while(low <= high)
    {
        int mid = (low + (high - low)/2);
        if((arr[mid] != arr[mid + 1]) && (arr[mid] != arr[mid - 1]))
        {
            return arr[mid];
        }

        if((mid % 2 == 1 && arr[mid] == arr[mid-1]) || (mid%2 == 0 && arr[mid] == arr[mid + 1]))
        {
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
        }
    }

    return -1;
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

    int result1 = singleElementBF(arr);
    int result2 = singleElementOpt(arr);

    cout<<result1<<" "<<result2;

    return 0;
}

// TIME COMPLEXITY: O(log n)
// SPACE COMPLEXITY: O(1)
