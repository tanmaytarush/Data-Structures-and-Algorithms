"""

Given an integer N, determine whether it is a Perfect Number or not. Return true if it is a Perfect Number, otherwise return false.

A Perfect Number is a positive integer that is equal to the sum of its positive divisors, excluding the number itself.

Example 1
Input: n = 6

Output: true

Explanation: The proper divisors of 6 are 1, 2, and 3. Their sum is 6, so 6 is a Perfect Number.

Example 2
Input: n = 12

Output: false

Explanation: The proper divisors of 12 are 1, 2, 3, 4, and 6. Their sum is 16, which is not equal to 12.


Complexity Analysis
Time Complexity: O(N), because every number from 1 to N - 1 may be checked.

Space Complexity: O(1), because only a few variables are used.


"""

class Solution:
    def perfectNumber(self, n: int) -> bool:
        num: int = abs(n)

        sum: int = 0

        for i in range(1, num):
            if(num % i == 0):
                sum += i

        return sum == num

def main() -> None:
    n = int(input("Enter a number : "))
    sol = Solution()
    print(sol.perfectNumber(n))

if __name__ == "__main__":
    main()