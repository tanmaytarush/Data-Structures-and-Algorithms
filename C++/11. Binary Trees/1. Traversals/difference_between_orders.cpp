/*

Preorder vs Inorder vs Postorder
Last Updated : 23 Jul, 2025
In Preorder Traversal, the root node is visited first, followed by the left and right subtrees. Inorder Traversal starts with the left subtree, visits the root, and then the right subtree, often used in binary search trees. Postorder Traversal begins with the left subtree, moves to the right subtree, and visits the root last, useful for deleting nodes. In this article, we will discuss the Tree Traversal Techniques used in data structure and algorithms with their differences.

Preorder Traversal
Preorder traversal is defined as a type of tree traversal that follows the Root-Left-Right policy where:

The root node of the subtree is visited first.
Then the left subtree is traversed.
At last, the right subtree is traversed.
Pre--Order-Traversal-6.webpPre--Order-Traversal-6.webp


In-order Traversal
Inorder traversal is defined as a type of tree traversal technique that follows the Left-Root-Right pattern, such that:

The left subtree is traversed first.
Then the root node for that subtree is traversed.
Finally, the right subtree is traversed.
In--Order-Traversal-6.webpIn--Order-Traversal-6.webp


Postorder Traversal
Postorder traversal is defined as a type of tree traversal that follows the Left-Right-Root policy such that for each node:

The left subtree is traversed first.
Then the right subtree is traversed.
Finally, the root node of the subtree is traversed.
Post-Order-Traversal-6.webpPost-Order-Traversal-6.webp
Below is the Implementation of the above idea:




#include <iostream>
using namespace std;
​
// Definition of a binary tree node
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};
​
// Pre-order traversal
void preorderTraversal(TreeNode* root) {
    if (root) {
        cout << root->val << " "; // Visit root
        preorderTraversal(root->left); // Recursively traverse left subtree
        preorderTraversal(root->right); // Recursively traverse right subtree
    }
}
​
// In-order traversal
void inorderTraversal(TreeNode* root) {
    if (root) {
        inorderTraversal(root->left); // Recursively traverse left subtree
        cout << root->val << " "; // Visit root
        inorderTraversal(root->right); // Recursively traverse right subtree
    }
}
​
// Post-order traversal
void postorderTraversal(TreeNode* root) {
    if (root) {
        postorderTraversal(root->left); // Recursively traverse left subtree
        postorderTraversal(root->right); // Recursively traverse right subtree
        cout << root->val << " "; // Visit root
    }
}
​
// Example tree
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
​
    // Pre-order traversal
    cout << "Pre-order traversal: ";
    preorderTraversal(root);
    cout << endl;
​
    // In-order traversal
    cout << "In-order traversal: ";
    inorderTraversal(root);
    cout << endl;
​
    // Post-order traversal
    cout << "Post-order traversal: ";
    postorderTraversal(root);
    cout << endl;
​
    return 0;
}

Output
Pre-order traversal: 1 2 4 5 3 6 
In-order traversal: 4 2 5 1 3 6 
Post-order traversal: 4 5 2 6 3 1 

*/