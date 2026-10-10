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


[LCM * GCD = a * b]


Complexity Analysis
Time Complexity: O(min(a, b)), because every number from 1 to the smaller value is checked.

Space Complexity: O(1), because constant space is used.

"""

class Solution:
    def gcd(self, a:int, b:int) -> int:

        a = abs(a)
        b = abs(b)

        if a==0 or b==0:
            return

        while b != 0:
            temp = b
            b = a%b
            a = temp

        return a


def main() -> None:
    n = int(input("Number 1 : "))
    m = int(input("Number 2 : "))
    sol = Solution()
    lcm = n*m // sol.gcd(n, m)
    print(lcm)

if __name__ == "__main__":
    main()

