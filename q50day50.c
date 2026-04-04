#include <stdio.h>
#include <stdlib.h>

// Definition of BST node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to search in BST
struct TreeNode* searchBST(struct TreeNode* root, int key) {
    // Base case: root is NULL or key found
    if (root == NULL || root->val == key)
        return root;

    // If key is smaller, search in left subtree
    if (key < root->val)
        return searchBST(root->left, key);

    // If key is greater, search in right subtree
    return searchBST(root->right, key);
}