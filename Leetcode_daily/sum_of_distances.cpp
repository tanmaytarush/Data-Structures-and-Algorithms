/*

SUM_OF_DISTANCES -> https://leetcode.com/problems/sum-of-distances/description/?envType=daily-question&envId=2026-04-23

You are given a 0-indexed integer array nums. There exists an array arr of length nums.length, where arr[i] is the sum of |i - j| over all j such that nums[j] == nums[i] and j != i. If there is no such j, set arr[i] to be 0.

Return the array arr.

 

Example 1:

Input: nums = [1,3,1,1,2]
Output: [5,0,3,4,0]
Explanation: 
When i = 0, nums[0] == nums[2] and nums[0] == nums[3]. Therefore, arr[0] = |0 - 2| + |0 - 3| = 5. 
When i = 1, arr[1] = 0 because there is no other index with value 3.
When i = 2, nums[2] == nums[0] and nums[2] == nums[3]. Therefore, arr[2] = |2 - 0| + |2 - 3| = 3. 
When i = 3, nums[3] == nums[0] and nums[3] == nums[2]. Therefore, arr[3] = |3 - 0| + |3 - 2| = 4. 
When i = 4, arr[4] = 0 because there is no other index with value 2. 

Example 2:

Input: nums = [0,5,3]
Output: [0,0,0]
Explanation: Since each element in nums is distinct, arr[i] = 0 for all i.
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109
 

Note: This question is the same as 2121: Intervals Between Identical Elements.



INTUITION :-

Your derivation is spot on — now let’s make it click fully with a clean dry run and connect it directly to the code formula.

⸻

🔁 Problem Recap

For each index i, compute:

\sum_{j:\; nums[j] = nums[i]} |i - j|

⸻

🧠 Key Idea

Group indices with same value.

Example:

nums = [1, 3, 1, 1, 2]

Groups:

1 → [0, 2, 3]
3 → [1]
2 → [4]

We only compute inside each group.

⸻

🔍 Dry Run (Main Example)

Take group:

group = [0, 2, 3]

Step 1: Precompute

S = total sum = 0 + 2 + 3 = 5
prefixTotal = 0
m = 3

⸻

👉 i = 0 (index = 0)

Using formula:

res[a_i] = total - 2 \cdot prefixTotal + a_i \cdot (2i - m)

res[0] = 5 - 2*0 + 0*(2*0 - 3)
       = 5

Manual check:

|0-0| + |0-2| + |0-3| = 0 + 2 + 3 = 5 ✅

Update:

prefixTotal = 0

⸻

👉 i = 1 (index = 2)

prefixTotal = 0
res[2] = 5 - 2*0 + 2*(2*1 - 3)
       = 5 + 2*(-1)
       = 3

Manual:

|2-0| + |2-2| + |2-3| = 2 + 0 + 1 = 3 ✅

Update:

prefixTotal = 0 + 2 = 2

⸻

👉 i = 2 (index = 3)

prefixTotal = 2
res[3] = 5 - 2*2 + 3*(2*2 - 3)
       = 5 - 4 + 3*(1)
       = 4

Manual:

|3-0| + |3-2| + |3-3| = 3 + 1 + 0 = 4 ✅

⸻

🔥 Final Output

res = [5, 0, 3, 4, 0]

⸻

🧩 Now connect with your derivation

You derived:

(i \cdot a_i - P_i) + ((S - P_i - a_i) - (m - i - 1) \cdot a_i)

Let’s simplify:

Expand:

= i*a_i - P_i + S - P_i - a_i - (m-i-1)*a_i

Group terms:

= S - 2P_i + (i*a_i - a_i - (m-i-1)*a_i)

Now simplify bracket:

i*a_i - a_i - (m-i-1)*a_i
= a_i * (i - 1 - (m-i-1))
= a_i * (2i - m)

⸻

✅ Final Formula

\boxed{
res[a_i] = S - 2P_i + a_i (2i - m)
}

⸻

🚀 Why this is powerful

* Avoids O(n²)
* Uses prefix sums → O(n)
* Core trick: split absolute sum into left + right

⸻

🧠 Intuition (Very Important)

Think:

* Left side → distance grows as i * a_i - prefix
* Right side → remaining elements → handled via total sum

And the final formula merges both cleanly.

⸻

*/

#define LOG(x) cerr<<#x<<" "<<x<<endl;
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<numeric>
using namespace std;

class Solution
{
    public:
    vector<long long> sumOfDifferences(vector<int>& nums)
    {
        int n = nums.size();
        unordered_map<int, vector<int>> groups;
        for(int i=0; i<n; ++i)
        {
            groups[nums[i]].push_back(i);
        }

        vector<long long> res(n);
        for(const auto &p : groups)
        {
            const auto &group = p.second;
            long long total = accumulate(group.begin(), group.end(), 0LL);
            long long prefixTotal = 0;

            for(int i=0; i<group.size(); ++i)
            {   
                res[group[i]] = total - 2*prefixTotal + group[i] * (2 * i - group.size());
                prefixTotal += group[i];
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
    int n;
    cin>>n;

    vector<int> nums(n);
    for(int i=0; i<n; ++i)
    {
        cin>>nums[i];
    }

    vector<long long> result = sol.sumOfDifferences(nums);

    for(vector<long long>::iterator it = result.begin(); it!=result.end(); ++it)
    {
        cout<<*it<<" ";
    }

    return 0;
}   