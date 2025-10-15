/*

** WORKING OF HASHING :-

- Division Method 

Consider a situation in which we want to use an unordered map for the purpose of our usage of 
hashing of elements. Now, suppose we have an array like [2, 34, 78, 55, 69], so in normal 
hash table we need to declare max+1 elements and fill it with counters. To cover this 
situation, hash comes into picture. Consider what if we chunk down each element as 
element%10 and store the remainder. In this case, usually we need array of lesser size
in the memory, and all the repeated remainders are stored in the form of a linkedlist. 

Now if a situation arises, that all the remainders map to the same key or their values are the
same. Then in that case, collision occurs, and the unordered map deals with o(N) time
complexity.

- Folding Method
- Mid Square Method


Q.) Problem Statement: Given an array of size N. Find the highest and lowest frequency element.

Pre-requisite: Hashing Theory and  Counting frequencies of array elements

Examples:

Example 1:
Input: array[] = {10,5,10,15,10,5};
Output: 10 15
Explanation: The frequency of 10 is 3, i.e. the highest and the frequency of 15 is 1 i.e. the lowest.

Example 2:

Input: array[] = {2,2,3,4,4,2};
Output: 2 3
Explanation: The frequency of 2 is 3, i.e. the highest and the frequency of 3 is 1 i.e. the lowest.

*/


#include<iostream>
#include<map>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    int arr[n];
    for(int i=0; i<n; ++i)
    {
        cin>>arr[i];
    }

    map<int, int> mp;
    for(int i=0; i<n; ++i)
    {
        mp[arr[i]]++;
    }

    int max = INT_MIN;
    int min = INT_MAX;
    for(auto it : mp)
    {
        if(it.second > max)
        {
            max = it.second;
        }

        if(it.second < min)
        {
            min = it.second;
        }
    }

    cout<<min<<" "<<max<<endl; 

    // int q;
    // cin>>q;
    // while(q--)
    // {
    //     // int n;
    //     // cin>>n;
    //     cout<<min<<" "<<max<<endl;
    // }
}