/*
Generate all binary strings

Problem Statement: Given an integer n, return all binary strings of length n that do not contain consecutive 1s. Return the result in lexicographically increasing order.

A binary string is a string consisting only of characters '0' and '1'.

Examples
Example 1:
Input:
 n = 3  
Output:
 ["000", "001", "010", "100", "101"]  
Explanation:
 All binary strings of length 3 that do not contain consecutive 1s.

Example 2:
Input:
 n = 2  
Output:
 ["00", "01", "10"]  
Explanation:
 All binary strings of length 2 that do not contain consecutive 1s.
Approach
Algorithm
At each step, try to place '0' or '1' at the current position.
You can always place '0'.
You can place '1' only if the previous character was not '1'.
Recurse until the length becomes n, and collect all valid strings.
*/

#define LOG(x) curr << #x <<" "<<x<<endl;
#define MOD 1000000007;

#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
using namespace std;

void generateBinary(int n, string curr, vector<string> &result)
{
    if(curr.length() == n)
    {
        result.push_back(curr);
        return;
    }

    // Add 0's initially
    generateBinary(n, curr + "0", result);

    // Add 1's if previous is not 1
    if(curr.empty() || curr.back() != '1')
    {
        generateBinary(n, curr + "1", result);
    }
}

int main()
{
    int n;
    cin>>n;

    vector<string> result;

    generateBinary(n, "", result);

    for(auto &s : result)
    {
        cout<<s<<" ";
    }
    cout<<endl;

    return 0;
}