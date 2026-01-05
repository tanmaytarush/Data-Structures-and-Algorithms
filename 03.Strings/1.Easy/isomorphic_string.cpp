/*
Question:
Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters.
No two characters may map to the same character, but a character may map to itself.

Approach:
1. Initialize two maps to store the mapping of characters from s to t and from t to s.
2. Iterate through each character in s and t simultaneously.
3. If the current characters in s and t are already mapped differently, return false.
4. If the current characters in s and t are not mapped yet, add them to the maps.
5. If the current characters in s and t are already mapped to each other, continue to the next characters.
6. If all characters have been iterated and no inconsistencies are found, return true.

Code:
*/

#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

bool isIsomorphic(string s, string t)
{
    vector<int> v1(128, -1);
    vector<int> v2(128, -1);

    if(s.size() != t.size())
    {
        return false;
    }

    for(int i=0; i<s.length(); ++i)
    {
        if(v1[s[i]] != v2[t[i]])
        {
            return false;
        }
        v1[s[i]] = v2[t[i]] = i;  // i index mapping, works with counter as well (except for "aaabbbba" and "bbbaaaba")
    }

    return true;
}

int main()
{
    string s;
    string t;  
    getline(cin, s);
    getline(cin, t);

    bool result = isIsomorphic(s, t);

    cout<<result;
    return 0;
}

/*
Time Complexity: O(n), where n is the length of the input strings s and t.
- We iterate through each character of s and t once.

Space Complexity: O(m), where m is the number of unique characters in the input strings s and t.
- In the worst case, all characters in s and t are unique, and we need to store mappings for all of them.
- The space complexity can also be considered as O(1) since the maximum number of unique characters is limited (26 English alphabets).
*/

