/*
Question:
Given the root of a binary tree, return the postorder traversal of its nodes' values.

Approach:
- postorder traversal visits the left subtree first, followed by the right subtree, and then the root node.
- We can solve this problem recursively by following the postorder traversal order.

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
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution
{
    public:
    void postorder(Node* root, vector<int>&ans)
    {
        if(!root) return;

        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->data);
    }

    vector<int> postOrderTraversal(Node* root)
    {
        vector<int> ans;
        postorder(root, ans);
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

    vector<int> result = sol.postOrderTraversal(root);

    for(vector<int>::iterator it = result.begin(); it != result.end(); ++it)
    {
        cout<<*it<<endl;
    }

    return 0;
}