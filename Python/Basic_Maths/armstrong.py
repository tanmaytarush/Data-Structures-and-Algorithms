"""

Check If a Number Is an Armstrong Number
163k
1
Given an integer N, determine whether it is an Armstrong number or not. Return true if it is an Armstrong number, otherwise return false.

An Armstrong number, also known as a Narcissistic number, is a number that is equal to the sum of its own digits, where each digit is raised to the power of the total number of digits.

Example 1
Input: n = 153

Output: true

Explanation: 153 has 3 digits, and 1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153, so it is an Armstrong number.

Example 2
Input: n = 123

Output: false

Explanation: 123 has 3 digits, and 1^3 + 2^3 + 3^3 = 1 + 8 + 27 = 36, which is not equal to 123.



Time Complexity: O(d * k), where d is the number of digits and k is the digit count used as the power, because each digit is processed once and each power is computed over k multiplications in this implementation.

Space Complexity: O(1), because only a few variables are used.

"""

class Solution:
    def armstrong(self, n: int) -> bool:
        num: int = abs(n)

        original: int = num
        sum: int = 0

        while(num > 0):
            digit: int = num % 10
            sum += digit*digit*digit
            num = num // 10

        if(original == sum):
            return True

        return False


def main() -> None:
    n = int(input("Enter number : "))
    sol = Solution()
    print(sol.armstrong(n))

if __name__ == "__main__":
    main()