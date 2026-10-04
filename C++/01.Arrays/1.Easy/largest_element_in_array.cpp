/*
QUESTION:-
Given an array A[] of size n. The task is to find the largest element in it.

Example:

Input:
n = 5
A[] = {1, 8, 7, 56, 90}
Output:
90
Explanation:
The largest element of given array is 90
*/

/*
APPROACH:-
-> Intialize the ans with starting element
-> Traverse the entire array and update the ans if the element is greater then ans
-> Finally, return the ans
*/

// CODE:-

#include<iostream>
#include<vector>
using namespace std;

int largestElement(vector<int> &arr, int n)
{
    int max = arr[0];
    for(int i=0; i<n; ++i)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
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

    int answer = largestElement(arr, n);
    cout<<answer;
    
    return 0;
}

// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(0)