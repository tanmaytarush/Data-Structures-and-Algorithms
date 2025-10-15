/*
QUESTION:-

Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
*/

/*
APPROACH:-
To rotate the array k places to right follow below steps
-> Reverse first n-k elements
-> Reverse last k elements
-> Reverse the entire array

To rotate the array k places to left follow below steps
-> Reverse first k elements
-> Reverse last n-k elements
-> Reverse the entire array
*/

// CODE:-
#include<iostream>
using namespace std;
#include<vector>

// Declare reverseArr for initialization
void reverseArr(vector<int> &arr, int start, int end);

vector<int> left_rotate_bf(vector<int> &arr, int d)
{
    int n = arr.size();
    if(n==0)
        return arr;
    d = d%n;

    vector<int> temp(d);

    for(int i=0; i<d; ++i)
    {
        temp[i] = arr[i];
    }

    for(int i=d; i<n; ++i)
    {
        arr[i-d] = arr[i];
    }

    for(int i=n-d; i<n; ++i)
    {
        arr[n-d+1] = temp[i];
    }

    return arr;
}

vector<int> right_rotate_bf(vector<int> &arr, int d)
{
    int n = arr.size();
    if(n==0)
        return arr;
    d = d%n;

    vector<int> temp(d);

    for(int i=0; i<d; ++i)
    {
        temp[i] = arr[n-d+i];
    }

    for(int i=n-d-1; i>=0; --i)
    {
        arr[i+d] = arr[i];
    }

    for(int i=0; i<d; ++i)
    {
        arr[i] = temp[i];
    }

    return arr;
}

void left_rotate_opt(vector<int> &arr, int d)
{ 
    int n = arr.size();
    if(n == 0) return;
    d = d%n;
    reverseArr(arr, 0, d-1);
    reverseArr(arr, d, n-1);
    reverseArr(arr, 0, n-1);
}

void right_rotate_opt(vector<int> &arr, int d)
{
    int n = arr.size();
    if(n == 0) return;
    d = d%n;
    reverseArr(arr, 0, n-d-1);
    reverseArr(arr, n-d, n-1);
    reverseArr(arr, 0, n-1);
}

void reverseArr(vector<int> &arr, int start, int end)
{
    while(start<end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

int main()
{
    int n;
    cin>>n;

    int d;
    cin>>d;

    vector<int> arr(n);

    for(int i=0; i<n; ++i)
    {
        cin>>arr[i];
    }

    arr = left_rotate_bf(arr, d);
    arr = right_rotate_bf(arr, d);
    left_rotate_opt(arr, d);
    right_rotate_opt(arr, d);

    for(int i=0; i<n; ++i)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}

// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(0)