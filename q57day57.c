#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to mirror the tree
struct TreeNode* mirrorTree(struct TreeNode* root) {
    if (root == NULL) return NULL;

    // Swap left and right
    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recur for subtrees
    mirrorTree(root->left);
    mirrorTree(root->right);

    return root;
}

// Inorder traversal
void inorder(struct TreeNode* root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}