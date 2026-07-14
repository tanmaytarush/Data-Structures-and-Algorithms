/*
Question:
You have been given a Binary Tree of 'N' nodes, where the nodes have integer values.
Your task is to find the In-Order, Pre-Order, and Post-Order traversals of the given binary tree.

Approach:
- We can perform the tree traversals recursively using three functions:
    - In-Order Traversal: Visit the left subtree, visit the current node, visit the right subtree.
    - Pre-Order Traversal: Visit the current node, visit the left subtree, visit the right subtree.
    - Post-Order Traversal: Visit the left subtree, visit the right subtree, visit the current node.
- For each traversal, we can maintain a vector to store the values of the visited nodes in the respective order.

Complexity Analysis:
- Since we visit each node once and perform constant time operations for each node, the time complexity of this approach is O(N), where N is the number of nodes in the binary tree.
- The space complexity is O(N) as we store the values of the nodes in vectors for each traversal.

Code:
*/

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {} 
};

class Solution
{
    public:
    vector<vector<int>> preinpostTraversals(Node* root)
    {
        vector<int> pre;
        vector<int> in;
        vector<int> post;

        stack<pair<Node*, int>> st;

        st.push({root, 1});

        while(!st.empty())
        {
            auto it = st.top();
            st.pop();

            // preorder traversal [ root->left->right ]
            if(it.second == 1)
            {
                // push to postfix vector
                pre.push_back(it.first->data);

                // update num value
                it.second = 2;

                // push updated to stack
                st.push(it);

                // check for left
                if(it.first->left != NULL)
                {
                    st.push({it.first->left, 1});
                }
            }

            // inorder traversal [ left->root->right ]
            else if(it.second == 2)
            {
                // push to inorder array
                in.push_back(it.first->data);

                // update num
                it.second = 3;

                // push to stack
                st.push(it);

                // check for right
                if(it.first->right != NULL)
                {
                    st.push({it.first->right, 1});
                }
            }
            
            // postorder traversal
            else
            {   
                // simply push to postorder vector
                post.push_back(it.first->data);
            }
        }

        vector<vector<int>> result;
        result.push_back(pre);
        result.push_back(in);
        result.push_back(post);

        return result;
    }
};

int main()
{
    Solution sol;

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);


    vector<int> pre, in, post;
    vector<vector<int>> traversals = sol.preinpostTraversals(root);

    // Extracting the traversals
    // from the result
    pre = traversals[0];
    in = traversals[1];
    post = traversals[2];

    // Printing the traversals
    cout << "Preorder traversal: ";
    for (int val : pre) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Inorder traversal: ";
    for (int val : in) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Postorder traversal: ";
    for (int val : post) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}