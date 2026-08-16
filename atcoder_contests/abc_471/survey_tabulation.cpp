/*

B - Survey Tabulation / 
Time Limit: 2 sec / Memory Limit: 1024 MiB


Score : 
200 points

Problem Statement
Takahashi is tallying the results of a survey.

N people answered the survey, and the 
i-th person's answer is a string 
S 
i
​
  consisting of English letters.

Find the maximum number of people who gave the same answer in this survey.
Here, the case of the letters in the answers is not distinguished.
For example, AtCoder, ATCODER, and atcoder are all considered the same answer.

Constraints
1≤N≤100
S 
i
​
  is a string of length between 
1 and 
10 (inclusive) consisting of uppercase and lowercase English letters.
N is an integer.
Input
The input is given from Standard Input in the following format:

N
S 
1
​
 
⋮
S 
N
​
 
Output
Output the answer.

Sample Input 1
Copy
7
ARC
abc
ahc
ABC
beginner
AbC
ahc
Sample Output 1
Copy
3
There are three answers that are the same as ABC, and this number is the maximum.

Sample Input 2
Copy
10
x
x
x
x
x
x
x
x
x
x
Sample Output 2
Copy
10

*/

#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int surveyCount(vector<string>&arr)
{
    int maxCount = INT_MIN;

    for(int i=0; i<arr.size(); i++)
    {
        transform(arr[i].begin(), arr[i].end(), arr[i].begin(), ::tolower);
    }

    unordered_map<string, int> mpp;

    for(int i=0; i<arr.size(); i++)
    {
        mpp[arr[i]]++;
    }

    for(auto it : mpp)
    {
        maxCount = max(maxCount, it.second);
    }

    return maxCount;
}

int main()
{
    int n;
    cin>>n;

    vector<string> arr(n);
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    int ans = surveyCount(arr);

    cout<<ans;

    return 0;
}