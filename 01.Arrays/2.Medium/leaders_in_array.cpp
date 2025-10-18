/*
QUESTION:-

Given an array A of positive integers. Your task is to find the leaders in the array. An element of the array is a leader if it is greater than or equal to all the elements to its right side. The rightmost element is always a leader.

Example 1:
Input:
n = 6
A[] = {16,17,4,3,5,2}
Output: 17 5 2
Explanation: The first leader is 17 as it is greater than all the elements to its right. Similarly, the next leader is 5. The rightmost element is always a leader, so it is also included.

*/

/*
APPROACH:-

To find the leaders in the array, we can follow these steps:

1. Initialize a variable `maxRight` with the rightmost element of the array.
2. Iterate the array from right to left:
   - If the current element is greater than or equal to `maxRight`, it is a leader. Print the current element and update `maxRight` to the current element.
3. Finally, print `maxRight` as it is always a leader.

*/

// CODE:
#include<iostream>
using namespace std;
#include<vector>

vector<int> isLeaderBF(vector<int> &arr, int n)
{
    vector<int> ans(n);
    for(int i=0; i<n; ++i)
    {
        int isLeader = true;
        for(int j=i+1; j<n; ++j)
        {
            if(arr[j] > arr[i])
            {
                isLeader = false;
                break;
            }
        }
        if(isLeader == true)
        {
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

vector<int> isLeaderOpt(vector<int> &arr, int n)
{
    vector<int> ans;
    int maxLeader = arr[n-1];
    ans.push_back(maxLeader);

    for(int i=n-1; i>0; --i)
    {
        if(arr[i] > maxLeader)
        ans.push_back(arr[i]);
        maxLeader = arr[i];
    }

    return ans;
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

    vector<int> result1 = isLeaderBF(arr, n);
    vector<int> result2 = isLeaderOpt(arr, n);
    
    for(vector<int>::iterator it = result1.begin(); it!=result1.end(); ++it)
    {
        cout<<*it<<" ";
    }

    for(vector<int>::iterator it = result2.begin(); it!=result2.end(); ++it)
    {
        cout<<*it<<" ";
    }
}

// TIME COMPLEXITY: O(n), where n is the size of the array.
// SPACE COMPLEXITY: O(1)

