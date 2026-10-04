/*QUESTION:-
Given a 32-bit unsigned integer num and an integer i, perform the following operations on the number:
1. AND
2. OR
3. NOT
4. Shift

Note: The bits are indexed from 1 instead of 0 (1-based indexing).

Example:
Input: 70, 3
Output: 1 70 66
Explanation:
- The bit at the 3rd position from the least significant bit (LSB) is 1. (1 0 0 0 1 1 0)
- The value of the given number after setting the 3rd bit is 70.
- The value of the given number after clearing the 3rd bit is 66. (1 0 0 0 0 1 0)

Approach:
1. Subtract 1 from i to adjust the index to 0-based.
2. To get the ith bit, perform a bitwise AND operation between num and (1 << i). If the result is non-zero, the ith bit is set; otherwise, it is cleared.
3. To set the ith bit, perform a bitwise OR operation between num and (1 << i).
4. To clear the ith bit, perform a bitwise AND operation between num and the complement of (1 << i).

CODE:*/

#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

void operations(int a, int b)
{
    // AND
    int and_operation = a & b;
    cout<<and_operation<<endl;

    // OR
    int or_operation = a | b;
    cout<<or_operation<<endl;

    // NOT
    int not_operation = ~a;
    cout<<not_operation<<endl;

    // Right Shift
    int right_shift = a >> 1; // (a / 2^k)
    cout<<right_shift<<endl;

    // Left Shift
    int left_shift = a << 1; // (a * 2^k)
    cout<<left_shift<<endl;
}

int main()
{
    int a,b;
    cin>>a>>b;

    operations(a, b);

    return 0;
}