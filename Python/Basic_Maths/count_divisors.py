"""

Count Divisors
134.6k
0
Given a positive integer N, find and return the total count of its divisors.

A divisor is any positive integer that divides N completely, leaving a remainder of 0.

Example 1
Input: n = 12

Output: 6

Explanation: The positive divisors of 12 are 1, 2, 3, 4, 6, and 12. So, the total count is 6.

Example 2
Input: n = 25

Output: 3

Explanation: The positive divisors of 25 are 1, 5, and 25. So, the total count is 3.

Brute Force Approach
The first observation is very direct: every positive divisor of N must lie somewhere between 1 and N. So if the goal is to find all divisors, one simple way is to check every number in that range.

The next observation is that a number should be counted only when it divides N exactly. That means the remainder must be 0. Once this is noticed, the logic becomes straightforward: test each number from 1 to N and count the ones that leave no remainder.

Algorithm
Start by keeping a variable named count as 0, because no divisor has been confirmed yet. This variable will store how many valid numbers have been found so far.

Move through every number from 1 to N, because every positive divisor of N must lie in this range. No value outside this range can be a positive divisor of N.

For each number i, check whether N % i == 0. This remainder check matters because only numbers that divide N exactly should be counted.

Whenever the remainder becomes 0, increase count by 1. That step records the fact that one more valid divisor has been discovered.

After all numbers have been tested, return count, because by then every possible positive divisor has either been accepted or rejected.


Complexity Analysis
Time Complexity: O(N), because every number from 1 to N is checked.

Space Complexity: O(1), because only a few variables are used.

"""

class Solution:
    def countDivisor(self, n: int) -> int:
        n = abs(n)

        count: int = 0

        for i in range(1, n):
            if(n%i == 0):
                count+=1

        return count

def main() -> None:
    n = int(input("Enter a number : "))
    sol = Solution()
    print(sol.countDivisor(n))

if __name__ == "__main__":
    main()