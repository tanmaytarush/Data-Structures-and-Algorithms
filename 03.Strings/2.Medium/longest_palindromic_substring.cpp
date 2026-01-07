/*
Question:-
Given a string `s`, the task is to find the longest palindromic substring in `s`.

Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"

Approach:
1. We define a helper function `expandFromCenter` that takes a string `s`, and two indices `start` and `end` as input.
2. The function expands from the center and checks if the substring from `start` to `end` is a palindrome.
3. If the length of the current palindrome is greater than the maximum length seen so far (`maxLen`), we update the maximum length and the corresponding start and end indices (`ans_start` and `ans_end`).
4. We iterate over each character of the string `s` and consider it as a potential center for the palindrome.
5. We call `expandFromCenter` twice for each character - once for considering odd-length palindromes and once for even-length palindromes.
6. Finally, we return the substring of `s` that corresponds to the longest palindromic substring.

Code:*/

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int expandFromCentre(string s, int left, int right)
{
    while((left>=0 && right<s.size()) && (s[left] == s[right]))
    {
        left--;
        right++;
    }
    return (right - left - 1); // right and left moved one step ahead already
}

string longestPalindromicString(string s)
{
    int start = 0;
    int end = 0;

    int maxlen = 0;

    for(int current = 0; current<s.size(); ++current)
    {
        // check for odd length
        int lenOdd = expandFromCentre(s, current, current);

        // check for even length
        int lenEven = expandFromCentre(s, current, current + 1);

        // int maxlength finding out
        maxlen = max(lenEven, lenOdd);

        if(maxlen > end - start)
        {
            start = current - (maxlen - 1)/2;
            end = current + (maxlen)/2;
        }
    }

    return s.substr(start, end - start + 1);
}


int main()
{
    string s;
    getline(cin, s);

    string result = longestPalindromicString(s);

    cout<<result;
    return 0;
}

/*
Time Complexity: O(n^2), where n is the length of the input string `s`. The nested loops iterate over all possible pairs of indices.
Space Complexity: O(1), as we are using a constant amount of extra space.
*/
