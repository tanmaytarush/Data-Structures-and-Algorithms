/*
Problem Statement: Given an array nums and an integer k. Return true if there exist subsequences such that the sum of all elements in subsequences is equal to k else false.

Examples
Example 1:
Input :
 nums = [1, 2, 3, 4, 5] , k = 8
Output :
 Yes
Explanation :
 The subsequences like [1, 2, 5] , [1, 3, 4] , [3, 5] sum up to 8.

Example 2:
Input :
 nums = [4, 3, 9, 2] , k = 10
Output :
 No
Explanation :
 No subsequence can sum up to 10.
*/

#define LOG(x) cerr << #x <<" "<< x <<endl;

#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

bool checkSubsequenceExists(int index, int s, int sum, vector<int> &arr)
{
    if(index == arr.size())
    {
        if(s == sum)
        {
            return true;
        }
        else return false;
    }

    s += arr[index];
    if(checkSubsequenceExists(index + 1, s, sum, arr) == true)
    {
        return true;
    }

    s -= arr[index];
    if(checkSubsequenceExists(index + 1, s, sum, arr) == true)
    {
        return true;
    }

    return false;
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

    int sum;
    cin>>sum;

    bool result = checkSubsequenceExists(0, 0, sum, arr);

    cout<<result<<endl;

    return 0;
}