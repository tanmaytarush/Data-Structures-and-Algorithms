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
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;

class Node
{
    public:
    int data;
    Node* left = NULL;
    Node* right = NULL;

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
    vector<int> postorder2Stack(Node* root)
    {

    }
    
    vector<int> postorder1Stack(Node* root)
    {

    }
};

int main()
{

}