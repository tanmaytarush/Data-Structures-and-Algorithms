/*
QUESTION:-
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
*/

/*
APPROACH:-
-> The idea is while traversing the array if we found any zero then we have to swap it with next non-zero
*/

// CODE:-
// function to find the next non-zero element
#include<iostream>
using namespace std;
#include<vector>

vector<int> moveZerosBF(vector<int> &arr, int n)
{
    vector<int> temp;
    for(int i=0; i<n; ++i)
    {
        if(arr[i]!=0)
        {
            temp.push_back(arr[i]);    
        }
    }
    int nz = temp.size();
    for(int i=0; i<nz; ++i)
    {
        arr[i] = temp[i];
    }
    for(int i=nz; i<n; ++i)
    {
        arr[i] = 0;
    }
    return arr;
}

vector<int> moveZerosOpt(vector<int> &arr, int n)
{
    int j=-1;
    for(int i=0; i<n; ++i)
    {
        if(arr[i] == 0)
        {
            j = i;
            break;
        }
    }

    if(j==-1) return arr;

    for(int i=j+1; i<n; ++i)
    {
        if(arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
    return arr;
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

    vector<int> ans1 = moveZerosBF(arr, n);
    vector<int> ans2 = moveZerosOpt(arr, n);

    for(auto &it : ans1)
    {
        cout<<it<<" ";
    }

    cout<<'\n';

    for(auto &it : ans2)
    {
        cout<<it<<" ";
    }

    cout<<'\n';
    
    return 0;
}


// TIME COMPLEXITY = O(N) (as we moving j throught the array only once)
// SPACE COMPLEXITY = O(0)