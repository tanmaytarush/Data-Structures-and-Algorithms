/*

A - Second Half Sum / 
Time Limit: 2 sec / Memory Limit: 1024 MiB

×
Until 2026-08-29(Sat) 19:10, posting problem content, impressions, or solution approaches on social media is prohibited by the rules.

×
AtCoder Rules against Generative AI - Version 20251003

It is prohibited to use generative AI in ongoing AtCoder contests. For details, please see this post.

This rule also applies for Unrated participants.


Score : 
100 points

Problem Statement
You are given an integer sequence of length 
N: 
A=(A 
1
​
 ,A 
2
​
 ,…,A 
N
​
 ). Here, 
N is even.
Find the sum of the latter half of 
A, that is, the sum of 
A 
(N/2)+1
​
 ,A 
(N/2)+2
​
 ,…,A 
N
​
 .

Constraints
All input values are integers.
N is an even number satisfying 
2≤N≤100.
1≤A 
i
​
 ≤100
Input
The input is given from Standard Input in the following format:

N
A 
1
​
  
A 
2
​
  
… 
A 
N
​
 
Output
Output the answer.

Sample Input 1
Copy
8
1 3 7 8 4 2 5 6
Sample Output 1
Copy
17
The length of the sequence 
A is 
N=8, and you should find the sum of 
A 
5
​
 ,A 
6
​
 ,A 
7
​
 ,A 
8
​
 .
Since 
A 
5
​
 +A 
6
​
 +A 
7
​
 +A 
8
​
 =4+2+5+6=17, output 
17.

Sample Input 2
Copy
2
1 100
Sample Output 2
Copy
100
Sample Input 3
Copy
10
31 41 59 26 53 58 97 93 23 84
Sample Output 3
Copy
355

*/

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<climits>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution
{
    public:
    int secondHalf(vector<int>&nums)
    {
        int n = nums.size();
        int sum = 0;
        for(int i=n/2; i<n; i++)
        {
            sum += nums[i];
        }

        return sum;
    }
};

int main()
{
    Solution sol;
    int n;
    cin>>n;

    vector<int> nums(n);
    for(int i=0; i<n; i++)
    {
        cin>>nums[i];
    }

    int result = sol.secondHalf(nums);
    cout<<result<<endl;

    return 0;
}