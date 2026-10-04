/*
Question:
Given a Roman numeral as a string, convert it to an integer.

Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.
Example 2:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.


Approach:
1. Create a map to store the values of each Roman symbol.
2. Initialize `result` as the value of the first symbol in the input string.
3. Iterate through each character `c` in the input string `s`, starting from the second character.
    a. If the value of the current symbol is greater than the value of the previous symbol, subtract twice the value of the previous symbol from `result` and add the value of the current symbol.
    b. Otherwise, add the value of the current symbol to `result`.
4. Return `result` as the converted integer.

Rule:
1. Understand that Roman numerals are generally written in descending order of value, and their values are added.
2. However, when a smaller value appears before a larger one, it indicates subtraction instead of addition.
3. To handle this, scan the string from left to right and compare each character with the one after it.
4. If the current symbol is smaller than the next, treat it as a subtractive pair.
5. Otherwise, treat the symbol as a standalone value and add it normally.
6. The final character is always added since there's nothing after it to compare.


Time Complexity: O(n), where n is the length of the input string `s`.
Space Complexity: O(1)
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int romanToInteger(string s)
{
    unordered_map<char, int> roman = {{'I', 1}, {'V', 5}, {'X', 10}, 
    {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

    int ans = 0;

    for(int i=0; i<s.length() - 1; ++i)
    {
        if(roman[s[i]] < roman[s[i+1]])
        {
            ans -= roman[s[i]];
        }

        else
        {
            ans += roman[s[i]];
        }
    }

    // ans += roman[s[s.length() - 1]]; OR
    ans += roman[s.back()];

    return ans;
}

int main()
{
    string s;
    getline(cin, s);

    int ans = romanToInteger(s);

    cout<<ans;

    return 0;
}
