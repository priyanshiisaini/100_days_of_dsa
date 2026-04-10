#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Helper to create node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Find index in inorder
int findIndex(int inorder[], int start, int end, int value) {
    for(int i = start; i <= end; i++) {
        if(inorder[i] == value) return i;
    }
    return -1;
}

// Build tree
struct TreeNode* buildTreeHelper(int preorder[], int inorder[], int start, int end, int* preIndex) {
    
    if(start > end) return NULL;

    // Step 1: Pick root from preorder
    int rootVal = preorder[*preIndex];
    (*preIndex)++;

    struct TreeNode* root = newNode(rootVal);

    // If single node
    if(start == end) return root;

    // Step 2: Find root in inorder
    int index = findIndex(inorder, start, end, rootVal);

    // Step 3: Build left & right
    root->left = buildTreeHelper(preorder, inorder, start, index - 1, preIndex);
    root->right = buildTreeHelper(preorder, inorder, index + 1, end, preIndex);

    return root;
}

// Main build function
struct TreeNode* buildTree(int preorder[], int inorder[], int n) {
    int preIndex = 0;
    return buildTreeHelper(preorder, inorder, 0, n - 1, &preIndex);
}

// Postorder traversal
void postorder(struct TreeNode* root) {
    if(root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}