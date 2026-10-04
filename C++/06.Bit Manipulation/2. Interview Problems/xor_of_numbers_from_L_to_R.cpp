/*
Question:
You are given two integers L and R, your task is to find the XOR of elements of the range [L, R].

Example:

Input:
L = 4, R = 8
Output:
8
Explanation:
4 ^ 5 ^ 6 ^ 7 ^ 8 = 8
*/

/*
Approach:
The XOR of a range [L, R] can be calculated by XORing the XORs of the individual numbers in the range [1, L-1] and [1, R].
We can observe a pattern in the XOR values based on the remainders of the numbers divided by 4.
Using this pattern, we can calculate the XOR of a given number n by applying some conditions.

1. If n % 4 == 0, the XOR value is n.
2. If n % 4 == 1, the XOR value is 1.
3. If n % 4 == 2, the XOR value is n+1.
4. If n % 4 == 3, the XOR value is 0.

By calculating the XOR values for L-1 and R separately using the above pattern, we can XOR them to get the final result.

Code:
*/

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

int xorValues(int N)
{
    if(N % 4 == 1) return 1;
    else if(N % 4 == 2) return N+1;
    else if(N % 4 == 3) return 0;
    else return N;
}

int xorLToR(int L, int R)
{
    int xorL = xorValues(L-1);
    int xorR = xorValues(R);

    return xorL^xorR;
}

int main()
{
    int L;
    int R;

    cin>>L;
    cin>>R;

    int result = xorLToR(L, R);

    cout<<result;

    return 0;
}

/*
Complexity Analysis:
- The time complexity is O(1) as the calculations are based on simple arithmetic operations.
- The space complexity is O(1) as no extra space is required.
*/

