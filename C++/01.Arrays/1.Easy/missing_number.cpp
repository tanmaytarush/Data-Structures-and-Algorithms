/*
QUESTION:-
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Example 1:

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
Example 2:

Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
*/

/*
APPROACH:-
-> Calculate the optimum sum i.e. sum when all elements were present
-> Calculate the actual array's sum
-> Return the optimum sum - actual sum
*/

// CODE:-
#include<iostream>
using namespace std;
#include<vector>
#include<map>

int missingNumberBF(vector<int> &arr, int n)
{
    for(int i=1; i<=n; ++i)
    {
        int flag = 0;
        for(int j=0; j<n-1; ++j)
        {
            if(arr[j] == i)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            return i;
        }
    }
    return -1;
}

int missingNumberBetter(vector<int> &arr, int n)
{
    vector<int> hash(n+1, 0);
    for(int i=0; i<n-1; ++i)
    {
        hash[arr[i]]++;
    }

    for(int i=1; i<=n; ++i)
    {
        if(hash[i] == 0)
        {
            return i;
        }
    }
    return -1;
}

int missingNumberOpt1(vector<int> &arr, int n)
{
    long long s1 = (n*(n+1))/2;
    int s2 = 0;
    for(int i=0; i<n-1; ++i) // One element is less in the array
    {
        s2+=arr[i];
    }
    int missingNumber = s1 - s2;
    return missingNumber;
}

int missingNumberOpt2(vector<int> &arr, int n)
{
    int xor1 = 0;
    int xor2 = 0;
    for(int i=0; i<n-1; ++i)
    {
        xor1 = xor1^arr[i];
        xor2 = xor2^(i+1);
    }
    xor2 = xor2^n;
    return xor1^xor2;
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

    int ans1 = missingNumberBF(arr, n);
    int ans2 = missingNumberBetter(arr, n);
    int ans3 = missingNumberOpt1(arr, n);
    int ans4 = missingNumberOpt2(arr, n);

    cout<<ans1<<" "<<ans2<<" "<<ans3<<" "<<ans4;

    return 0;
}

// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(0)