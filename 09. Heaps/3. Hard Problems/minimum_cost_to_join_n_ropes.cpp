/*
Question:
There are given N ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to the sum of their lengths. The task is to connect the ropes with the minimum cost. Given an array arr[] containing the lengths of the ropes.

Similar:- https://leetcode.com/problems/minimum-cost-to-merge-stones/

Example:
Input: arr[] = {4, 3, 2, 6}
Output: 29
Explanation: The minimum cost is obtained by connecting ropes in the following order:
1. Connect ropes of length 2 and 3, cost = 2 + 3 = 5, resulting array = {4, 5, 6}
2. Connect ropes of length 4 and 5, cost = 4 + 5 = 9, resulting array = {9, 6}
3. Connect ropes of length 6 and 9, cost = 6 + 9 = 15, resulting array = {15}
Total cost = 5 + 9 + 15 = 29

Approach:
1. Use a priority queue (min heap) to store the lengths of the ropes.
2. Push all the rope lengths into the priority queue.
3. While the priority queue has more than one element:
   - Extract the two smallest ropes from the priority queue.
   - Add their lengths together to get the cost.
   - Push the sum back into the priority queue.
   - Update the total cost.
4. Return the total cost as the minimum cost of connecting the ropes.

Complexity Analysis:
- Time complexity: O(n log n), where n is the number of ropes. Inserting and extracting elements from the priority queue take O(log n) time, and the loop runs for (n-1) iterations.
- Space complexity: O(n) to store the rope lengths in the priority queue.

Code:
*/

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

class Solution 
{
    public:
    int minCost(vector<int>&ropes, int n)
    {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(int i=0; i<n; ++i)
        {
            minHeap.push(ropes[i]);
        }

        int totalCost = 0;

        while(minHeap.size() > 1)
        {
            int firstHalf = minHeap.top();
            minHeap.pop();

            int secondHalf = minHeap.top();
            minHeap.pop();

            int sum = firstHalf + secondHalf;
            totalCost += sum;
            minHeap.push(sum);
        }

        return totalCost;
    }
};

int main()
{
    Solution sol;

    int n;
    cin>>n;

    vector<int> ropes(n);
    for(int i=0; i<n; ++i)
    {
        cin>>ropes[i];
    }

    int sum = sol.minCost(ropes, n);

    cout<<sum<<endl;

    return 0;
}
