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
-> Traverse the entire array and within it run a loop while element's are equal to 1 and store the count
-> Update the ans as max(ans,cnt)
*/

// CODE:-

#include<iostream>
using namespace std;
#include<vector>

int maxconsecutives1(vector<int> &arr, int n)
{
    int maxcount = 0;
    int count = 0;

    for(int i=0; i<n; ++i)
    {
        if(arr[i] == 1)
        {
            count += 1;
            maxcount = max(maxcount, count);
        }
        else{
            count = 0;
        }
    }
    return maxcount;
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

    int result = maxconsecutives1(arr, n);

    cout<<result;
}

// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(0)
