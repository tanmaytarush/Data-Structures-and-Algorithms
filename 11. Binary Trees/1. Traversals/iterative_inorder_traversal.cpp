/*
Question:
Given the root of a binary tree, return the inorder traversal of its nodes' values.

Approach:
- We can perform an inorder traversal iteratively using a stack.
- The idea is to push all the left children of a node into the stack until we reach a node with no left child.
- Then, we pop a node from the stack, add its value to the result vector, and move to its right child (if it exists).
- We repeat this process until the stack is empty and all nodes are traversed.

Complexity Analysis:
- Since we visit each node once and perform constant time operations for each node, the time complexity of this approach is O(N), where N is the number of nodes in the binary tree.
- The space complexity is O(N) as we store the node values in the result vector and use a stack to keep track of the nodes.

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
    vector<int> inorderTraversal(Node* root)
    {
        // left->root->right
        // if left keep adding in the stack and keep moving left
        // if not, go on with else condition where the vector root elements
        // are stored

        vector<int> ans;
        Node* node = root;
        stack<Node*> st;

        while(true)
        {
            if(node != NULL)
            {
                st.push(node);
                node = node->left;
            }
            else
            {
                if(st.empty()) break;
                node = st.top();
                st.pop();
                ans.push_back(node->data);

                node = node->right;
            }
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

    vector<int> ans = sol.inorderTraversal(root);

    for(int x : ans)
    {
        cout<<x<<" ";
    }

    return 0;
}