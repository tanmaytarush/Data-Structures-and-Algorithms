/*
Question:
Given the root of a binary tree, return the inorder traversal of its nodes' values.

Approach:
- inorder traversal visits the left subtree first, followed by the root node, and then the right subtree.
- We can solve this problem recursively by following the inorder traversal order.

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
    vector<int> inorderTraversalIterative(Node* root)
    {
        // left->root->right
        vector<int> inorder;
        Node* node = root;
        stack<Node*> st;

        // first we would pass and check for left since left is to be printed first
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
                inorder.push_back(node->val);

                //st.push(node);
                node = node->right;
            }
        }
        return inorder;
    }

    void inorder(Node* root, vector<int> &ans)
    {
        // left->root->right
        if(!root) return;

        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    vector<int> inorderRec(Node* root)
    {
        vector<int> ans;
        inorder(root, ans);
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

    vector<int> resultRec = sol.inorderRec(root);
    for(int x : resultRec)
    {
        cout<<x<<endl;
    }

    vector<int> resultIterative = sol.inorderTraversalIterative(root);
    for(int x : resultIterative)
    {
        cout<<x<<endl;
    }

    return 0;
}