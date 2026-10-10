"""

GCD of Two Numbers Using the Euclidean Algorithm
178.2k
2
Given two integers a and b, find their GCD using the Euclidean Algorithm. The GCD of two numbers is the largest positive integer that divides both numbers exactly.

Example 1
Input: a = 48, b = 18

Output: 6

Explanation: The common divisors of 48 and 18 are 1, 2, 3, 6, and the greatest among them is 6.

Example 2
Input: a = 42, b = 56

Output: 14

Explanation: 14 divides both 42 and 56, and no larger common divisor exists.



Complexity Analysis
Time Complexity: O(min(a, b)), because every number from 1 to the smaller value is checked.

Space Complexity: O(1), because constant space is used.

"""

class Solution:
    def GCD(self, n: int, m: int) -> int:
        n = abs(n)
        m = abs(m)

        if n==0 or m==0:
            return 0

        while m != 0:
            temp: int = m
            m = n%m
            n = temp

        return n


def main() -> None:
    n = int(input("Enter num1 : "))
    m = int(input("Enter num2 : "))
    sol = Solution()
    print(sol.GCD(n, m))


if __name__ == "__main__":
    main()