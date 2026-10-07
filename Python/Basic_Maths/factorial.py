"""

Factorial of a Number
108.5k
0
Given a non-negative integer N, find its factorial.

The factorial of N is written as N! and means:

N! = N * (N - 1) * (N - 2) * ... * 2 * 1

For N = 0, the factorial is defined as 1.

Example 1
Input: n = 5

Output: 120

Explanation: 5! = 5 * 4 * 3 * 2 * 1 = 120

Example 2
Input: n = 0

Output: 1

Explanation: By definition, 0! = 1.




Complexity Analysis
Time Complexity: O(N), because the loop runs from 2 to N.

Space Complexity: O(1), because only one main answer variable is used.

"""



class Solution:
    """
    Returns the factorial of n
    using iterative multiplication.
    """
    def factorial(self, n: int) -> int:
        # Stores the running factorial value.
        fact: int = 1

        # Start from 2 because multiplying by 1 does not matter.
        for i in range(2, n + 1):
            # Multiply current number into running factorial value.
            fact *= i

        return fact


# Driver code starts
def main() -> None:
    n: int = 5

    obj = Solution()
    print(obj.factorial(n))


if __name__ == "__main__":
    main()