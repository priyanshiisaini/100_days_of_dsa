#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;

    struct Node* nodes[n];

    for (int i = 0; i < n; i++) {
        if (arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = newNode(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int l = 2*i + 1;
            int r = 2*i + 2;
            if (l < n) nodes[i]->left = nodes[l];
            if (r < n) nodes[i]->right = nodes[r];
        }
    }

    return nodes[0];
}

// Queue structure
struct QNode {
    struct Node* node;
    int hd;
};

void verticalOrder(struct Node* root) {
    if (root == NULL) return;

    struct QNode queue[1000];
    int front = 0, rear = 0;

    // Map (HD offset by +1000 to handle negative)
    int map[2000][100];
    int count[2000] = {0};

    int min = 1000, max = 1000;

    queue[rear++] = (struct QNode){root, 1000};

    while (front < rear) {
        struct QNode temp = queue[front++];
        struct Node* curr = temp.node;
        int hd = temp.hd;

        map[hd][count[hd]++] = curr->data;

        if (hd < min) min = hd;
        if (hd > max) max = hd;

        if (curr->left)
            queue[rear++] = (struct QNode){curr->left, hd - 1};
        if (curr->right)
            queue[rear++] = (struct QNode){curr->right, hd + 1};
    }

    // Print result
    for (int i = min; i <= max; i++) {
        for (int j = 0; j < count[i]; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}