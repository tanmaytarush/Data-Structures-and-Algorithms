/*
ABC 467 - Keep the Change

Problem Statement
Takahashi made purchases at N stores. Initially, he had 10000 yen.

At the i-th store, he bought an item worth A_i yen and paid B_i yen.
Here, A_i <= B_i holds.

If S_i = "keep", he did not receive the change.
If S_i = "take", he received the change.

Let X be Takahashi's final amount of money.
Let Y be his final amount of money in the case where he received the
change at every store.

Find Y - X.

Constraints
  - 1 <= N <= 100
  - 1 <= A_i <= B_i <= 100
  - S_i is "keep" or "take"
  - N, A_i, and B_i are all integers

Input
  N
  A_1 B_1 S_1
  A_2 B_2 S_2
  ...
  A_N B_N S_N

Output
  Print the amount of money Takahashi lost compared to the case where
  he received the change at every store.

Sample Input 1
  3
  1 2 keep
  3 6 take
  5 9 keep

Sample Output 1
  5

Sample Input 2
  8
  36 49 take
  38 73 keep
  27 85 take
  65 71 take
  52 86 keep
  48 60 keep
  37 98 keep
  5 38 keep

Sample Output 2
  175
*/

#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int N; 
    cin>>N;
    int total = 0;

    for(int i=0; i<N; i++)
    {
        int A; int B; string S;
        cin>>A>>B>>S;
        if(S == "keep")
        {
            total += (B - A);
        }
    }

    cout<<total<<"\n";
    return 0;
}
