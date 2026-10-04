/*

Problem Statement: You are given an array. The task is to reverse the array and print it. 

Examples:

Example 1:
Input: N = 5, arr[] = {5,4,3,2,1}
Output: {1,2,3,4,5}
Explanation: Since the order of elements gets reversed the first element will occupy the fifth position, the second element occupies the fourth position and so on.

Example 2:
Input: N=6 arr[] = {10,20,30,40}
Output: {40,30,20,10}
Explanation: Since the order of elements gets reversed the first element will occupy the fifth position, the second element occupies the fourth position and so on.


*/

#include<iostream>
using namespace std;

class FunctionalRecursion{
public:
    void reverseArray(int l, int arr[], int r)
    {
        if(l>=r)
            return;
        swap(arr[l], arr[r]);
        reverseArray(l+1, arr, r-1);
    }

    void reverseArray_SinglePointer(int i, int arr[], int n)
    {
        if(i>=n/2)
        {
            return;
        }
        swap(arr[i], arr[n-i-1]);
        reverseArray_SinglePointer(i+1, arr, n);
    }

};

int main()
{
    FunctionalRecursion fr1;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; ++i)
    {
        cin>>arr[i];
    }
    fr1.reverseArray(0, arr, n-1); // Start from [0, n-1]
    fr1.reverseArray_SinglePointer(0, arr, n); // Single Pointer
    for(int i=0; i<n; ++i)
    {
        cout<<arr[i]<<" ";
    }
}