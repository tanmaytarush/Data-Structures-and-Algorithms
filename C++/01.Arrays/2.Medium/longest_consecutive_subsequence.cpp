/*
QUESTION:-

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
*/

/*
APPROACH:-

To find the length of the longest consecutive elements sequence, we can follow these steps:

1. Create a set to store all the elements of the array.
2. Iterate through the array and insert each element into the set.
3. For each element, check if its previous consecutive element (num-1) exists in the set. If it does not exist, it means the current element is the starting element of a sequence.
4. For each starting element, keep incrementing the current element (num+1) and checking if it exists in the set. This will help find the consecutive elements in the sequence.
5. Keep track of the maximum length of consecutive elements encountered.
6. Return the maximum length as the result.

*/

// CODE:
#include<iostream>
using namespace std;
#include<set>
#include<vector>
#include <unordered_set>
#include<algorithm>

bool linearSearch(vector<int> &arr, int x)
{
    int n = arr.size();
    for(int i=0; i<n; ++i)
    {
        if(arr[i] == x)
        {
            return true;
        }
    }
    return false;
}

int longestSubSeqBF(vector<int> &arr, int n)
{
    int longest = 1;
    for(int i=0; i<n; ++i)
    {
        int x = arr[i];
        int count = 1;
        while(linearSearch(arr, x+1) == true)
        {
            count = count+1;
            x = x+1;
        }
        longest = max(longest, count);
    }
    return longest;
}

int longestSubSeqBetter(vector<int> &arr, int n)
{
    int longest = 1;
    int count = 0;
    int lastStartElement = INT_MIN;
    sort(arr.begin(), arr.end());
    for(int i=0; i<n; ++i)
    {
        if(arr[i]-1 == lastStartElement)
        {
            count += 1;
            lastStartElement = arr[i];
        }

        else if(arr[i] != lastStartElement)
        {
            count = 1;
            lastStartElement = arr[i];
        }
        longest = max(longest, count);
    }
    return longest;
}

int longestSubSeqOpt(vector<int> &arr, int n)
{
    int longest = 0;
    unordered_set<int> set;
    for(int i=0; i<n; ++i)
    {
        set.insert(arr[i]);
    }

    for(auto it : arr)
    {
        if(set.find(it-1) == set.end())
        {
            int cnt = 1;
            int x = it;
            while(set.find(x+1) != set.end())
            {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
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

    int res1 = longestSubSeqBF(arr, n);
    int res2 = longestSubSeqBetter(arr, n);
    int res3 = longestSubSeqOpt(arr, n);

    cout<<res1<<" "<<res2<<" "<<res3<<endl;
    return 0;
}

// TIME COMPLEXITY: O(n), where n is the size of the input array.
// SPACE COMPLEXITY: O(n), as we are using a set to store the elements of the array.
