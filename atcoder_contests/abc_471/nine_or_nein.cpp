/*

A - Nine or Nein / 
Time Limit: 2 sec / Memory Limit: 1024 MiB

×
Until 2026-08-15(Sat) 19:10, posting problem content, impressions, or solution approaches on social media is prohibited by the rules.

×
AtCoder Rules against Generative AI - Version 20251003

It is prohibited to use generative AI in ongoing AtCoder contests. For details, please see this post.

This rule also applies for Unrated participants.


Score : 
100 points

Problem Statement
You are given positive integers 
A and 
B.

If at least one of the following values is equal to 
9, output Nine; otherwise, output Nein.

A+B
A−B
A×B
A÷B
Constraints
1≤A≤100
1≤B≤100
All input values are integers.
Input
The input is given from Standard Input in the following format:

A 
B
Output
Output the answer.

Sample Input 1
Copy
16 7
Sample Output 1
Copy
Nine
Since 
16−7=9, output Nine.

Sample Input 2
Copy
66 7
Sample Output 2
Copy
Nein
None of the following values is equal to 
9, so output Nein.

66+7=73
66−7=59
66×7=462
66÷7= 
7
66
​
 
Sample Input 3
Copy
9 1
Sample Output 3
Copy
Nine
Sample Input 4
Copy
9 9
Sample Output 4
Copy
Nein

*/

#include<iostream>
using namespace std;

string operation(int A, int B)
{
    string ans;

    if((A+B == 9) || (A-B)==9 || (A*B)==9 || (A/B)==9)
    {
        ans = "Nine";
    }

    else{
        ans = "Nein";
    }

    return ans;
}

int main()
{
    int A;
    int B;
    cin>>A>>B;

    string ans = operation(A, B);

    cout<<ans<<endl;

    return 0;
}