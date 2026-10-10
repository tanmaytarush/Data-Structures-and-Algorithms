"""

Given an integer N, determine whether it is a Prime Number or not. Return true if it is prime, otherwise return false.

A prime number is a positive integer greater than 1 that has no positive divisors other than 1 and itself.

Example 1
Input: N = 7

Output: true

Explanation: The number 7 is divisible only by 1 and 7, so it is a prime number.

Example 2
Input: N = 12

Output: false

Explanation: The number 12 is divisible by 2, 3, 4, and 6 as well, so it is not a prime number.



Complexity Analysis
Time Complexity: O(N), because in the worst case almost all numbers from 2 to N - 1 are checked.

Space Complexity: O(1), because only a few variables are used.

"""

class Solution:
    def prime(self, n: int) -> bool:
        num: int = abs(n)

        count: int = 0

        for i in range(2, num):
            if(num % i == 0):
                return False

        return True


def main() -> None:
    n = int(input("Enter a number : "))
    sol = Solution()
    print(sol.prime(n))

if __name__ == "__main__":
    main()