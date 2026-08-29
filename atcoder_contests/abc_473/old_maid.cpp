/*

Score : 
200 points

Problem Statement
Takahashi currently has 
N cards. The 
i-th 
(1≤i≤N) card has the integer 
A 
i
​
  written on it.

He repeats the following operation as many times as possible.

Choose two different cards with the same integer written on them, and eat those two cards. The eaten cards are permanently removed and cannot be chosen in subsequent operations.
Find the sum of the integers written on the cards that remain when the operation can no longer be performed.

Constraints
1≤N≤100
1≤A 
i
​
 ≤100 (1≤i≤N)
All input values are integers.
Input
The input is given from Standard Input in the following format:

N
A 
1
​
  
A 
2
​
  
⋯ 
A 
N
​
 
Output
Output the sum of the integers written on the remaining cards.

Sample Input 1
Copy
8
2 7 1 8 2 8 1 8
Sample Output 1
Copy
15
For example, Takahashi operates as follows.

The fourth card and sixth card both have 
8 written on them, so he chooses them and eats them.
The first card and fifth card both have 
2 written on them, so he chooses them and eats them.
The third card and seventh card both have 
1 written on them, so he chooses them and eats them.


Thus, the sum of the integers written on the remaining cards is 
7+8=15.

Note that there are three cards with 
8 written on them, so once two of them are eaten, the remaining one cannot be eaten.

Sample Input 2
Copy
5
1 2 3 4 5
Sample Output 2
Copy
15
It is possible that Takahashi cannot perform the operation even once.

Sample Input 3
Copy
15
58 97 74 16 97 74 97 16 51 52 58 52 74 32 43
Sample Output 3
Copy
297

*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;

class Solution
{
    public:
    int oldMaid(vector<int>&nums)
    {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for(int x : nums)
        {
            mpp[x]++;
        }

        int ans = 0;
        for(auto &p : mpp)
        {
            if(p.second % 2 == 1)
            {
                ans += p.first;
            }
        }

        return ans;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    cout << sol.oldMaid(nums) << '\n';

    return 0;
}