/*

B - Break a Stick / 
Time Limit: 2 sec / Memory Limit: 1024 MiB

×
Until 2026-08-22(Sat) 19:10, posting problem content, impressions, or solution approaches on social media is prohibited by the rules.

×
AtCoder Rules against Generative AI - Version 20251003

It is prohibited to use generative AI in ongoing AtCoder contests. For details, please see this post.

This rule also applies for Unrated participants.


Score : 
200 points

Problem Statement
There is one stick. This stick has 
N−1 notches, which divide it into 
N parts.

The lengths of the parts are 
L 
1
​
 ,L 
2
​
 ,…,L 
N
​
  in order from one end.

When choosing one notch and breaking the stick there to obtain two sticks, find the minimum possible absolute value of the difference between the lengths of the two resulting sticks.

Here, the width of a notch can be ignored, and the length of each resulting stick is the sum of the lengths of the parts it contains.

Constraints
2≤N≤100
1≤L 
i
​
 ≤10 
5
 
All input values are integers.
Input
The input is given from Standard Input in the following format:

N
L 
1
​
  
L 
2
​
  
… 
L 
N
​
 
Output
Output the answer.

Sample Input 1
Copy
4
5 2 3 8
Sample Output 1
Copy
2
Breaking the stick at each notch results in the following:

Breaking at the first notch from the end results in two sticks of lengths 
5 and 
13, with an absolute difference of 
8.
Breaking at the second notch from the end results in two sticks of lengths 
7 and 
11, with an absolute difference of 
4.
Breaking at the third notch from the end results in two sticks of lengths 
10 and 
8, with an absolute difference of 
2.
Sample Input 2
Copy
7
31 41 59 26 53 58 97
Sample Output 2
Copy
51
Sample Input 3
Copy
10
67011 35764 33042 24098 63738 98760 17199 68579 21812 45408
Sample Output 3
Copy
28105

*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
    using LL = long long;
    public:
    LL lengthDifference(vector<long long>&sticks, int n)
    {
        long long minimum = LLONG_MAX;
        long long left = 0;

        long long S = accumulate(sticks.begin(), sticks.end(), 0LL);

        // calculating the minimum breakage point
        for(int i=0; i<n-1; i++)
        {
            left += sticks[i];
            minimum = min(minimum, abs(2*left - S));
        }

        return minimum;
    }
};

int main()
{
    Solution sol;

    int n;
    cin>>n;

    vector<long long> sticks(n);
    for(int i=0; i<n; i++)
    {
        cin>>sticks[i];
    }

    long long result = sol.lengthDifference(sticks, n);

    cout<<result<<endl;

    return 0;
}