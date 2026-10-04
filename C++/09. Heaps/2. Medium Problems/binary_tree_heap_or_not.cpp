/*

Is Binary Tree Heap
Difficulty: MediumAccuracy: 34.41%Submissions: 147K+Points: 4

You are given the root of a binary tree, and the task is to determine whether it satisfies the properties of a max-heap.

A binary tree is considered a max-heap if it satisfies the following conditions:

Completeness: Every level of the tree, except possibly the last, is completely filled, and all nodes are as far left as possible.
Max-Heap Property: The value of each node is greater than or equal to the values of its children.

Examples:

Input: root = [97, 46, 37, 12, 3, 7, 31, 6, 9]
 
Output: true
Explanation: The tree is complete and satisfies the max-heap property.
Input: root = [97, 46, 37, 12, 3, 7, 31, N, N, 2, 4]
 
Output: false
Explanation: The tree is not complete and does not follow the Max-Heap Property, hence it is not a max-heap.
Constraints:
1 ≤ number of nodes ≤ 103
1 ≤ node->data ≤ 103


INTUITION :-

1. Consider two cases, a binary tree is considered to be a heap, if it satisfies two conditions,
   it is a complete binary tree and satisfies max-heap property.
2. Let's start by searching and validating whether the given structure is a CBT, if at any 
   point the particular index becomes greater than the node-count, then in that case, the 
   tree is not a complete binary tree.
3. Similarly, in case of maxHeap we need to check whether a set of given nodes inside tree
   satisfies the max-heap property and any parent node has the value higher than its 
   child node.

*/

#define LOG(x) cerr<<#x<<" "<<x<<endl;
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }
};

int nodeCount(Node* root)
{
    if(root == NULL)
    {
        return 0;
    } 

    int ans = 1 + nodeCount(root->left) + nodeCount(root->right);
    return ans;
}

bool isCBT(Node* root, int index, int nodeCount)
{
    if(root == NULL)
    {
        return true;
    }

    if(index >= nodeCount) return false;

    else
    {
        int left = isCBT(root->left, 2*index+1, nodeCount);
        int right = isCBT(root->right, 2*index+2, nodeCount);

        int ans = (left && right);
        return ans;
    }
}

bool isMaxOrder(Node* root)
{
    if(root->left==NULL && root->right==NULL)
    {
        return true;
    }

    if(root->right == NULL)
    {
        return (root->data >= root->left->data);
    }

    else
    {
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        return ((left && right) && (root->data >= root->left->data) && (root->data >= root->right->data));
    }
}

bool isBinaryTreeHeap(Node* root)
{
    int index = 0;
    int cnt = nodeCount(root);
    if(isCBT(root, index, cnt) && isMaxOrder(root))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    Node* root = new Node(97);

    root->left = new Node(46);

    root->right = new Node(37);

    root->left->left = new Node(12);

    root->left->right = new Node(3);

    root->right->left = new Node(7);

    root->right->right = new Node(31);

    root->left->left->left = new Node(6);

    root->left->left->right = new Node(9);

    if(isBinaryTreeHeap(root))
        cout<< "Tree is a Max Heap\n";
    else
        cout<< "Tree is NOT a Max Heap\n";

    return 0;
}