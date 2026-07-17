/*
Question:
Given the root of a binary tree, return the postorder traversal of its nodes' values.

Approach:
- We can perform a postorder traversal iteratively using a stack and a map.
- The idea is to push all the left children of a node into the stack until we reach a node with no left child.
- Then, we check if the right child of the node exists or has already been visited (using the map).
    - If it does not exist or has been visited, we add the node's value to the result vector and pop the node from the stack.
    - Otherwise, we push the right child into the stack and mark it as visited in the map.
- We repeat this process until the stack is empty and all nodes are traversed.

Complexity Analysis:
- Since we visit each node once and perform constant time operations for each node, the time complexity of this approach is O(N), where N is the number of nodes in the binary tree.
- The space complexity is also O(N) as we store the node values in the result vector and use a stack and a map to keep track of the nodes.

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
    vector<int> postorderTraversal(Node* root)
    {
        vector<int> post;
        stack<Node*> st;
        Node* curr = root;

        while(curr != NULL || !st.empty())
        {
            if(curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
            else
            {
                Node* temp = st.top()->right;

                if(temp == NULL)
                {
                    temp = st.top();
                    st.pop();
                    post.push_back(temp->data);

                    // till stack is empty and
                    // temp == st.top()->right means there exists an element before
                    while(!st.empty() && temp == st.top()->right)
                    {
                        temp = st.top();
                        st.pop();
                        post.push_back(temp->data);
                    }
                }
                else
                {
                    curr = temp;
                }
            }
        }
        return post;
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

    vector<int> ans = sol.postorderTraversal(root);

    for(int x : ans)
    {
        cout<<x<<" ";
    }

    return 0;
}