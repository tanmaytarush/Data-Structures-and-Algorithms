/*
QUESTION:-
Given an array Arr of size N, print second largest distinct element from an array.

Example:

Input:
N = 6
Arr[] = {12, 35, 1, 10, 34, 1}
Output: 34
Explanation: The largest element of the
array is 35 and the second largest element
is 34.
*/

/*
APPROACH
-> If the current element is larger than ‘large’ then update second_large and large variables
-> Else if the current element is larger than ‘second_large’ then we update the variable second_large.
-> Once we traverse the entire array, we would find the second largest element in the variable second_large.
*/

// CODE:-

#include<iostream>
#include<vector>
using namespace std;

pair<int, int> secondLargestBF(vector<int> &arr, int n)
{
    int large = INT_MIN;
    int slarge = INT_MIN;
    int small = INT_MAX;
    int ssmall = INT_MAX;

    for(int i=0; i<n; ++i)
    {
        small = min(small, arr[i]);
        large = max(large, arr[i]);
    }

    for(int i=0; i<n; ++i)
    {
        if(arr[i]<small && arr[i]!=small)
        {
            ssmall = arr[i];
        }
        if(arr[i]>large && arr[i]!=large)
        {
            slarge = arr[i];
        }
    }
    return make_pair(slarge, ssmall);
}

int secondLargestOpt(vector<int> &arr, int n)
{
    int largest = INT_MIN;
    int slargest = INT_MIN;

    for(int i=0; i<n; ++i)
    {
        if(arr[i] > largest)
        {
            slargest = largest;
            largest = arr[i];
        }
        else if(arr[i]>slargest && arr[i]!=slargest)
        {
            slargest = arr[i];
        }
    }
    return slargest;
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

    pair<int, int> res1 = secondLargestBF(arr, n);
    int res2 = secondLargestOpt(arr, n);

    cout<<res1.first<<" "<<res1.second<<" "<<res2;
}

// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(0)