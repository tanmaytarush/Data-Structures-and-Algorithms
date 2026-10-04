/*

Problem Statement: Given an array of N integers, write a program to implement the Recursive Bubble Sort algorithm.

Examples:

Example 1:
Input: N = 6, array[] = {13,46,24,52,20,9}
Output: 9,13,20,24,46,52
Explanation: After sorting we get 9,13,20,24,46,52

Example 2:
Input: N = 5, array[] = {5,4,3,2,1}
Output: 1,2,3,4,5
Explanation: After sorting we get 1,2,3,4,5

*/

#include<iostream>
using namespace std;

void recursiveBS(int arr[], int n)
{
    if(n==1)
        return;

    for(int i=0; i<=n-2; ++i)
    {
        if(arr[i]>arr[i+1]) {
            int temp = arr[i+1];
            arr[i+1] = arr[i];
            arr[i] = temp;
        }
    }

    recursiveBS(arr, n-1);
}

int main()
{
    int n;
    cin>>n;
    int arr[n];

    for(int i=0; i<n; ++i)
    {
        cin>>arr[i];
    }

    recursiveBS(arr, n);

    for(int i=0; i<n; ++i)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}