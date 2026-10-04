/*
QUESTION:-
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.


Example 1:
Input: nums = [2,2,1]
Output: 1

Example 2:
Input: nums = [4,1,2,1,2]
Output: 4
*/

/*
APPROACH:-
-> We can use XOR operation as we know xor cancles out the same elements
-> Intial xr=0 then traverse the entire array and xor each element with xr
-> Since only one element is present once and all other are present twice so the remaining element would be the
    one which is present only once cause all other gets cancels out
*/

// CODE:-

#include<iostream>
using namespace std;
#include<vector>
#include<map>

int elementPresentOnceBF(vector<int> &arr, int n)
{
    for(int i=0; i<n; ++i)
    {
        int ele = arr[i];
        int count = 0;
        for(int j=0; j<n; ++j)
        {
            if(arr[j] == arr[i])
            {
                count++;
            }
        }
        if(count == 1)
        {
            return arr[i];
        }
    }
    return -1;
}

int elementPresentOnceBetter1(vector<int> &arr, int n)
{
    int maxi = arr[0];
    for(int i=0; i<n; ++i)
    {
        maxi = max(arr[i], maxi);
    }

    vector<int> hash(maxi + 1, 0);
    for(int i=0; i<n; ++i)
    {
        hash[arr[i]]++;
    }

    for(int i=0; i<n; ++i)
    {
        if(hash[arr[i]] == 1)
        {
            return arr[i];
        }
    }
    return -1;
}

int elementPresentOnceBetter2(vector<int> &arr, int n)
{
    map<int, int> mp;
    for(int i=0; i<n; ++i)
    {
        mp[arr[i]]++;
    }

    for(map<int, int>::iterator it = mp.begin(); it!=mp.end(); ++it)
    {
        if(it->second == 1)
        {
            return it->first;
        }
    }
    return -1;
}

int elementPresentOpt(vector<int> &arr, int n)
{
    int xorVal = 0;
    for(int i=0; i<n; ++i)
    {
        xorVal = xorVal ^ arr[i];
    }
    return xorVal;
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

    int res1 = elementPresentOnceBF(arr, n);
    int res2 = elementPresentOnceBetter1(arr, n);
    int res3 = elementPresentOnceBetter2(arr, n);
    int res4 = elementPresentOpt(arr, n);

    cout<<res1<<" "<<res2<<" "<<res3<<" "<<res4;
    return 0;
}

// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(0)