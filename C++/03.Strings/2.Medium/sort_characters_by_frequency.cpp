/*
Question:
Given a string s, sort it in decreasing order based on the frequency of the characters.
The frequency of a character is the number of times it appears in the string.

Approach:
1. Create a frequency map to count the occurrences of each character in the string.
2. Use a priority queue to sort the characters based on their frequencies in decreasing order.
3. Iterate through the priority queue and append the characters to a new string according to their frequencies.

Code:
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<unordered_map>
using namespace std;

string freqSort(string s)
{
    // storing frequencies in the hashmap
    unordered_map<char, int> mpp; 
    for(char ch : s)
    {
        mpp[ch]++;
    }

    // Implementing priority_queue for the re-ranking
    priority_queue<pair<int, char>> pq;  
    // <int, char> is used for lexographically considering freq before character for ordering
    for(auto it : mpp)
    {
        pq.push({it.second, it.first});
    }

    // Tracing out the queued max-heap string
    string ans = "";
    while(!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();
        ans.append(curr.first, curr.second);
    }
    
    return ans; 
}

int main()
{
    string s;
    getline(cin, s);

    string result = freqSort(s);

    cout<<result;
    return 0;
}

/*
Time Complexity: O(n log n), where n is the length of the string. Building the frequency map takes O(n) time, and the priority queue operations take O(n log n) time.
Space Complexity: O(n), where n is the length of the string. The space is used to store the frequency map and the priority queue.
*/
