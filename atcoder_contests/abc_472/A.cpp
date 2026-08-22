/*

A - A / 
Time Limit: 2 sec / Memory Limit: 1024 MiB

×
Until 2026-08-22(Sat) 19:10, posting problem content, impressions, or solution approaches on social media is prohibited by the rules.

×
AtCoder Rules against Generative AI - Version 20251003

It is prohibited to use generative AI in ongoing AtCoder contests. For details, please see this post.

This rule also applies for Unrated participants.


Score : 
100 points

Problem Statement
You are given a string 
S consisting of uppercase English letters.

Output the string obtained by replacing every character in 
S other than A with ..

Constraints
S is a string of length between 
1 and 
100 (inclusive) consisting of uppercase English letters.
Input
The input is given from Standard Input in the following format:

S
Output
Output the answer.

Sample Input 1
Copy
ATCODER
Sample Output 1
Copy
A......
Since the first character is the only occurrence of A in 
S, output the string obtained by changing the second through seventh characters of 
S to ..

Sample Input 2
Copy
BANANA
Sample Output 2
Copy
.A.A.A
S may contain two or more occurrences of A.

Sample Input 3
Copy
CORRECT
Sample Output 3
Copy
.......
S may contain no occurrence of A.

*/

#include<iostream>
#include<string>
using namespace std;

class Solution
{
    public:
    string refinedString(string &S)
    {
        int n = S.length();

        for(auto &it : S)
        {
            if(it != 'A')
            {
                it = '.';
            }
        }

        return S;
    }
};

int main()
{
    Solution sol;

    string S;
    getline(cin, S);

    string res = sol.refinedString(S);

    cout<<res<<endl;

    return 0;
}