/*

Score : 
100 points

Problem Statement
There is a train consisting of 
N cars. What is the position, counted from the back, of the car that is 
K-th from the front of this train?

Constraints
1≤K≤N≤100
All input values are integers.
Input
The input is given from Standard Input in the following format:

N 
K  
Output
If the car is 
X-th from the back, output the integer 
X in one line.

Sample Input 1
Copy
5 2
Sample Output 1
Copy
4
For a train consisting of five cars, the car that is second from the front is fourth from the back.

Sample Input 2
Copy
1 1
Sample Output 2
Copy
1
Sample Input 3
Copy
99 50
Sample Output 3
Copy
50


*/

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,K;
    cin>>N>>K;

    cout<<N-K+1<<endl;
    return 0;
}