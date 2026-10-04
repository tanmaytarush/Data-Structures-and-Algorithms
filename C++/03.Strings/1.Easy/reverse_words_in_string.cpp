/*
Question:
Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
Return a string of the words in reverse order concatenated by a single space.
Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

Example:
Input: s = "the sky is blue"
Output: "blue is sky the"

Approach:
- Initialize an empty string 'ans' to store the reversed words.
- Initialize 'start' and 'end' variables to keep track of the start and end indices of each word.
- Iterate through the input string 's'.
- Ignore leading spaces by advancing the iterator 'i' until a non-space character is found.
- Set 'start' to the current index 'i'.
- Find the end index 'end' of the current word by advancing 'i' until a space or the end of the string is encountered.
- Extract the current word using the substr() function and store it in a temporary string 'temp'.
- Reverse the characters in 'temp'.
- Append 'temp' to 'ans' with a space delimiter.
- Reverse the characters in 'ans' to get the reversed order of words.
- Remove any leading or trailing spaces in 'ans'.
- Return the resulting string 'ans'.

Code:
*/

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>

string reverseWords(string str)
{
    int n = str.length();
    int i=0;
    int j=n-1;
    while(i<=j)
    {
        swap(str[i], str[j]);
        i++; 
        j--;
    }

    int start = 0;
    int end = 0;
    for(end=0; end<n; ++end)
    {
        if(str[end] == ' ')
        {
            reverse(str.begin() + start, str.begin() + end);
            start = end + 1;
        }
    }

    reverse(str.begin() + start, str.begin() + end);

    return str;

    // DIDN'T WORK RUNS ONLY ONCE

    // int first = 0;
    // int second = 0;
    // int index = 0;

    // if(str[second] != ' ' && str[second] != '\0')
    // {
    //     second++;
    // }
    // else
    // {
    //     int i=0;
    //     int j=second-1;
    //     while(i<=j)
    //     {
    //         swap(str[i], str[j]);
    //         i++;
    //         j--;
    //     }
    //     index = second + 1;
    //     first = index;
    //     second = first;
    // }

    // return str;
}

int main()
{
    string str;
    getline(cin, str);

    cout<<reverseWords(str);

    //cout<<result;
}


/*
Time Complexity: O(n), where n is the length of the input string 's'.
Space Complexity: O(n), where n is the length of the input string 's'.
*/
