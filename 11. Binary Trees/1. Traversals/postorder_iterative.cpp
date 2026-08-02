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
#include<stack>
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
    vector<int> postOrderTraversalIterative(Node* root)
    {
        // left -> right -> root
        vector<int> post;
        stack<Node*> st;
        Node* curr = root;
        Node* lastVisited = NULL;

        while(curr != NULL || !st.empty())
        {
            if(curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
            else
            {
                Node* peekNode = st.top();

                if(peekNode->right != NULL && lastVisited != peekNode->right)
                {
                    curr = peekNode->right;
                }
                else
                {
                    post.push_back(peekNode->data);
                    lastVisited = peekNode;
                    st.pop();
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

    vector<int> result = sol.postOrderTraversalIterative(root);

    for(int x : result)
    {
        cout<<x<<endl;
    }

    return 0;
}
