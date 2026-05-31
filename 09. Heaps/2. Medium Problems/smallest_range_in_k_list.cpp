/*

Smallest range in K lists
Difficulty: Hard Accuracy: 43.21%Submissions: 44K+Points: 8Average Time: 40m

Given a 2d integer array mat[][] of size n*k, where each row is sorted in ascending order. Your task is to find the smallest range [l, r] that includes at least one element from each of the n lists. If more than one such ranges are found, return the first one.

Note: If there are two possible ranges [a, b] and [c, d] with the same size, choose the one with the smaller starting value, i.e., consider [a, b] if a < c.

Examples:

Input: mat[][] = [[4, 7, 9, 12, 15], 
               [0, 8, 10, 14, 20], 
               [6, 12, 16, 30, 50]]
Output: [6, 8]
Explanation: Smallest range is formed by number 7 from the first list, 8 from second list and 6 from the third list.
Input: mat[][] = [[2, 4],
               [1, 7], 
               [20, 40]]
Output: [4, 20]
Explanation: Smallest range is formed by number 4 from the first list, 7 from second list and 20 from the third list.
Constraints:
1 ≤ n, k ≤ 500
0 ≤ mat[i][j] ≤ 105

*/

#define LOG(x) cerr<<#x<<" "<<x<<endl;
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<string>
#include<queue>
using namespace std;

class node
{
    public:
    int data;
    int row;
    int col;

    node(int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare
{
    public:
    bool operator()(node* a, node* b)
    {
        return a->data > b->data;
    }
};

class Solution
{
    public:
    int rangeK(vector<vector<int>>&nums, int k)
    {
        int m = nums.size();
        int n = nums[0].size();
        priority_queue<node*, vector<node*>, compare> minHeap;

        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        for(int i=0; i<k; ++i)
        {
            node* newnode = new node(nums[i][0], i, 0);
            mini = min(mini, newnode->data);
            maxi = max(maxi, newnode->data);
            minHeap.push(newnode);
        }

        int start = mini; int end = maxi;

        while(!minHeap.empty())
        {
            node* top = minHeap.top();
            minHeap.pop();

            int mini = top->data;

            if(maxi-mini < end-start || (maxi-mini == end-start && mini < start))
            {
                start = mini;
                end = maxi;
            }

            if(top->col + 1 < n)
            {
                maxi = max(maxi, nums[top->row][top->col+1]);
                node* nextnode = new node(nums[top->row][top->col+1], top->row, top->col+1);
                minHeap.push(nextnode);
            }
            else{
                break;
            }
        }
        return (end-start+1);
    }
};

int main()
{
    Solution sol;
    int m;
    cin>>m;
    int n;
    cin>>n;

    vector<vector<int>> nums(m, vector<int>(n));
    for(int i=0; i<m; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            cin>>nums[i][j];
        }
    }

    int k;
    cin>>k;

    int result = sol.rangeK(nums, k);

    cout<<result<<endl;

    return 0;
}