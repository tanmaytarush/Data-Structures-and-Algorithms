/*
Question:
You are given an array nodes. It contains 7 integers, which represents the value of nodes of the binary tree in level order traversal. You are also given a root of the tree which has a value equal to nodes[0].
Your task to construct a binary tree by creating nodes for the remaining 6 nodes.

Approach:
- We can solve this problem recursively by performing a level-order traversal of the tree.
- Starting from the root node, we can recursively create the left and right child nodes using the given array of values.
- The position of each child node in the array can be calculated based on the index of its parent node.

Complexity Analysis:
- Since we are visiting each node once, the time complexity of this approach is O(N), where N is the number of nodes in the binary tree.
- The space complexity is O(N) as we are using the call stack for recursion.

Code:
*/

#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<unordered_set>
#include<algorithm>
#include<queue>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val) 
    {
        this->data = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Solution
{
    public:
    Node* buildTree(vector<int> &arr, int index)
    {
        if(index >= (int)arr.size())
        {
            return nullptr;
        }

        Node* root = new Node(arr[index]);
        root->left = buildTree(arr, 2*index + 1);
        root->right = buildTree(arr, 2*index + 2);

        return root;
    }

    vector<int> levelOrder(Node* root)
    {
        vector<int> ans;
        if(!root)
        {
            return ans;
        }

        queue<Node*> q;
        q.push(root);

        while(!q.empty())
        {
            Node* curr = q.front();
            q.pop();

            ans.push_back(curr->data);

            if(curr->left)
            {
                q.push(curr->left);
            }
            if(curr->right)
            {
                q.push(curr->right);
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    int n;
    cin>>n;

    vector<int> nums(n);
    for(int i=0; i<n; i++)
    {
        cin>>nums[i];
    }

    Node* root = sol.buildTree(nums, 0);
    vector<int> result = sol.levelOrder(root);

    for(vector<int>::iterator it = result.begin(); it != result.end(); ++it)
    {
        cout<<*it<<" ";
    }

    return 0;
}