/*
QUESTION:-
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:

Input: nums = [3,2,3]
Output: 3

Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/

/*
APROACH:-
-> Initialize two variables: candidate and count. Set candidate to the first element of the array, and count to 1.
-> Iterate through the array starting from the second element:
    If the current element is equal to the candidate, increment the count by 1.
    If the current element is different from the candidate, decrement the count by 1.
    If the count becomes 0, update the candidate to the current element and set the count to 1 again.
-> After the iteration, the candidate variable will hold the majority element.
Return the candidate as the result.
*/

// CODE:-
#include<iostream>
#include<vector>
using namespace std;
#include<map>

int majorityElementBF(vector<int> &arr, int n)
{
    for(int i=0; i<n; ++i)
    {
        int count = 0;
        for(int j=0; j<n; ++j)
        {
            if(arr[j] == arr[i])
            {
                count++;
            }
        }
        if(count > (n/2))
        {
            return arr[i];
        }
    }
    return -1;
}

int majorityElementBetter(vector<int> &arr, int n)
{
    map<int, int> mpp;
    for(int i=0; i<n; ++i)
    {
        mpp[arr[i]]++;
    }

    for(map<int, int>::iterator it = mpp.begin(); it!=mpp.end(); ++it)
    {
        if(it->second > (n/2))
        {
            return it->first;
        }
    }
    return -1;
}

int majorityElementOpt(vector<int> &arr, int n) // Moore's Voting Algorithm
{
    int ele;
    int count = 0;
    for(int i=0; i<n; ++i)
    {
        if(count == 0)
        {
            ele = arr[i];
            count = 1;
        }
        else if(arr[i] == ele)
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    int finalCount = 0;
    for(int i=0; i<n; ++i)
    {
        if(arr[i] == ele)
        {
            finalCount++;
        }
    }

    if(finalCount > (n/2))
    {
        return ele;
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

    int res1 = majorityElementBF(arr, n);
    int res2 = majorityElementBetter(arr, n);
    int res3 = majorityElementOpt(arr, n);

    cout<<res1<<" "<<res2<<" "<<res3;
    return 0;
}


// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(0)