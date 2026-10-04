/*
QUESTION:
Given an unsorted array Arr[] of N integers and an integer X, find floor and ceiling of X in Arr[0..N-1].

Floor of X is the largest element which is smaller than or equal to X. Floor of X doesn’t exist if X is smaller than the smallest element of Arr[].

Ceil of X is the smallest element which is greater than or equal to X. Ceil of X doesn’t exist if X is greater than the greatest element of Arr[].

Example:

Input:
N = 8, X = 7
Arr[] = {5, 6, 8, 9, 6, 5, 5, 6}
Output: 6 8
Explanation:
Floor of 7 is 6 and ceil of 7 is 8.

APPROACH:
1. Sort the array in ascending order.
2. Use binary search to find the floor and ceil values.
3. The floor value is the largest element smaller than or equal to X, and the ceil value is the smallest element greater than or equal to X.
4. If the floor or ceil values are not found, set them to -1.

CODE:
*/
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int lowerBoundBF(vector<int> &arr, int target)
{
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int answer = n;

    while(low <= high)
    {
        int mid = (low + high)/2;

        if(arr[mid] >= target) // Just this difference
        {
            answer = mid;
            high = mid - 1;
        }

        else
        {
            low = mid + 1;
        }
    }

    return answer;
}

int upperBoundBF(vector<int> &arr, int target)
{
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int answer = n;

    while(low <= high)
    {
        int mid = (low + high)/2;

        if(arr[mid] > target) // Just this difference
        {
            answer = mid;
            high = mid - 1;
        }

        else
        {
            low = mid + 1;
        }
    }

    return answer;
}

pair<int, int> getFloorAndCeil(vector<int> &arr, int n, int x) {
    sort(arr.begin(), arr.end());
    int Floor = lowerBoundBF(arr,x);
    int Ceil = upperBoundBF(arr,x);
    return std::make_pair(Floor, Ceil);
}


int main()
{
    int n;
    cin>>n;

    int target;
    cin>>target;

    vector<int> arr(n);
    for(int i=0; i<n; ++i)
    {
        cin>>arr[i];
    }

    int result1 = lowerBoundBF(arr, target);
    int result2 = upperBoundBF(arr, target);
    pair<int, int> result3 = getFloorAndCeil(arr, n, target);

    cout<<result1<<" "<<result2<<endl;
    cout<<result3.first<<" "<<result3.second<<endl;

    return 0;
}

// TIME COMPLEXITY: O(NlogN)
// SPACE COMPLEXITY: O(1)
