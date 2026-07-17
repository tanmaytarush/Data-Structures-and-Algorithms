/*
Question:
Given the root of a binary tree, return the preorder traversal of its nodes' values.

Approach:
- We can perform a preorder traversal iteratively using a stack.
- We start by pushing the root node into the stack.
- Then, while the stack is not empty, we pop a node from the stack, add its value to the result vector, and push its right child (if it exists) followed by its left child (if it exists) into the stack.
- By pushing the right child before the left child, we ensure that the left child is processed first during the traversal.

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
    // root->left->right
    // in stack right will go first because left is to be popped out first
    vector<int> preorderTraversal(Node* root)
    {
        vector<int> ans;
        stack<Node*> st;
        st.push(root);

        while(!st.empty())
        {
            Node* node = st.top();
            st.pop();
            ans.push_back(node->data);

            if(node->right != nullptr) st.push(node->right);
            if(node->left != nullptr) st.push(node->left);
        }

        return ans;
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

    vector<int> result = sol.preorderTraversal(root);

    for(int x : result)
    {
        cout<<x<<" ";
    }

    return 0;
}