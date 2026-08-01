/*

Score : 
200 points

Problem Statement
You are given a string 
S of length 
N consisting of o and x.
N chairs are arranged in a row from left to right. If the 
i-th character of 
S is o, a person is sitting in the 
i-th chair from the left; if it is x, no person is sitting there.
Find the number of chairs that satisfy all of the following conditions.

No person is sitting in it.
There is no chair to its left, or no person is sitting in the chair to its left.
There is no chair to its right, or no person is sitting in the chair to its right.
Constraints
1≤N≤100
N is an integer.
S is a string of length 
N consisting of o and x.
Input
The input is given from Standard Input in the following format:

N  
S  
Output
Output the answer in one line.

Sample Input 1
Copy
8
xxoxxxox
Sample Output 1
Copy
2
Only the first and fifth chairs from the left satisfy the conditions.

Sample Input 2
Copy
5
ooooo
Sample Output 2
Copy
0
Sample Input 3
Copy
1
x
Sample Output 3
Copy
1

*/

#include<iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string S;

    cin>>N>>S;

    int count = 0;

    for(int i=0; i<N; i++)
    {
        if((S[i] == 'x') && (i==0 || S[i-1]=='x') && (i==(N-1) || S[i+1] == 'x'))
        {
            count++;
        }
    }

    cout<<count;
}