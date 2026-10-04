/*
QUESTION:
You are given a number N. Find the total count of set bits for all numbers from 1 to N (both inclusive).

Example:
Input: N = 4
Output: 5
Explanation:
For numbers from 1 to 4:
- For 1: 0 0 1 = 1 set bit
- For 2: 0 1 0 = 1 set bit
- For 3: 0 1 1 = 2 set bits
- For 4: 1 0 0 = 1 set bit
Therefore, the total set bits is 5.

APPROACH:
The approach to solve this problem is based on the observation that the count of set bits in the binary representation of a number `n` can be determined by the following formula:
countSetBits(n) = countSetBits(pow(2, x - 1) * x) + (n - pow(2, x) + 1) + countSetBits(n - pow(2, x))

CODE:*/

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

int countSetBitsBF(int N)
{
    int count = 0;
    while(N>0)
    {
        if(N&1) count++;
        N = N>>1;
    }
    return count;
}

int countSetBitsOpt(int N)
{
    int count=0;
    while(N!=0)
    {
        N = (N & (N-1));
        count++;
    }
    return count;
}

int main()
{
    int N;
    cin>>N;

    int ans1 = countSetBitsBF(N);
    int ans2 = countSetBitsOpt(N);

    cout<<ans1<<" "<<ans2<<endl;

    return 0;
}

// Time Complexity: O(log(n))
// Space Complexity: O(log(n))


