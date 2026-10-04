/*
Question:
Given an integer 'N', determine the maximum number of nodes present on 'Nth' level in a binary tree.

Approach:
- The number of nodes on each level of a binary tree follows a pattern.
- The number of nodes on the Nth level is equal to 2^(N-1).
- We can use the pow function from the cmath library to calculate the power of 2.

Complexity Analysis:
- The time complexity of this approach is O(1) as we are using a simple mathematical formula.
- The space complexity is also O(1) as we are not using any additional space.

Code:
*/

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution
{
    public:
};

int main()
{

}