"""
Check Whether a Number Is a Palindrome
209.7k
1
Given an integer n, check whether it is a palindrome number or not.

A palindrome number stays the same even after its digits are reversed.

Example 1
Input: n = 121

Output: true

Explanation: Reading 121 from both sides gives the same number.

Example 2
Input: n = 10

Output: false

Explanation: Reversing 10 gives 01, which is not the same as 10.

"""

class Solution:
    def Palindrome(self, n: int) -> bool:
        # Negative numbers cannot be palindromes
        if(n < 0):
            return False

        num: int = n
        
        revNum: int = 0
        
        while(n > 0):
            digit: int = n%10
            revNum = revNum*10 + digit
            n = n // 10

        return num == revNum


def main() -> None:
    n = int(input("Enter the number : "))
    sol = Solution()
    print(sol.Palindrome(n))


if __name__ == "__main__":
    main()