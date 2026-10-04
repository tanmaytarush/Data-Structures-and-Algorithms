/*
Question:
Given the root of a binary tree, return the preorder traversal of its nodes' values.

Approach:
- Preorder traversal visits the root node first, followed by the left subtree, and then the right subtree.
- We can solve this problem recursively by following the preorder traversal order.
- Starting from the root node, we can add the node's value to the result vector, then recursively traverse the left subtree and right subtree.

Complexity Analysis:
- Since we are visiting each node once, the time complexity of this approach is O(N), where N is the number of nodes in the binary tree.
- The space complexity is O(N) as we are using the call stack for recursion.

Code:
*/

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<string>
#include<stack>
#include<queue>
using namespace std;

class Node
{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution
{
    public:
    // root->left->right
    vector<int> preorderTraversalIterative(Node* root)
    {
        // stack trace would take right elements first then left, because we
        // need to consider left elements first in pre-order traversal
        vector<int> preorder;
        stack<Node*> st;
        st.push(root);
        while(!st.empty())
        {
            root = st.top();
            st.pop();

            preorder.push_back(root->val);

            if(root->right != NULL)
            {
                st.push(root->right);
            }

            if(root->left != NULL)
            {
                st.push(root->left);
            }
        }
        return preorder;
    }

    void preorder(Node* root, vector<int> &ans)
    {
        if(!root) return;

        // root->left->right
        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }

    vector<int> preorderTraversalRec(Node* root)
    {
        // root->left->right
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }

    // Build tree from the user-input in preorder from
    // use -1 for null nodes
    Node* buildTree()
    {
        int val;
        cin>>val;

        if(val == -1)
        {
            return NULL;
        }

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

    vector<int> resultRec = sol.preorderTraversalRec(root);

    for(int x : resultRec)
    {
        cout<<x<<endl;
    }

    vector<int> resultInterative = sol.preorderTraversalIterative(root);

    for(int x : resultInterative)
    {
        cout<<x<<endl;
    }

    return 0;
}