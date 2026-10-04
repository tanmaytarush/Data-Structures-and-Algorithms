/*
Question:
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Approach:
- We can perform a level order traversal using a queue.
- We start by pushing the root node into the queue.
- Then, while the queue is not empty, we process each level by taking the size of the queue and iterating over the nodes at that level.
- For each node, we add its value to the current level's vector and push its left and right child nodes into the queue if they exist.
- After processing each level, we add the level's vector to the result vector.

Complexity Analysis:
- Since we visit each node once and perform constant time operations for each node, the time complexity of this approach is O(N), where N is the number of nodes in the binary tree.
- The space complexity is O(N) as we store the node values in the result vector.

Code:
*/

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Solution
{
    public:
    vector<vector<int>> levelOrder(Node* root)
    {
        vector<vector<int>> answer;
        queue<Node*> q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();

            vector<int> level;
            for(int i=0; i<size; i++)
            {
                Node* node = q.front();
                q.pop();

                // check for left and right
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                
                level.push_back(node->data);
            }

            answer.push_back(level);
        }

        return answer;
    }

    Node* buildTree()
    {
        int val;
        cin>>val;

        if(val == -1) return NULL;

        Node* root = new Node(val);
        root->left = buildTree();
        root->right = buildTree();

        return root;
    }
};

int main()
{
    Solution sol;
    
    Node* root = sol.buildTree();

    vector<vector<int>> result = sol.levelOrder(root);

    for(vector<vector<int>>::iterator it = result.begin(); it != result.end(); ++it)
    {
        for(vector<int>::iterator jt = it->begin(); jt != it->end(); ++jt)
        {
            cout<<*jt<<" ";
        }
        cout<<endl;
    }

    return 0;
}