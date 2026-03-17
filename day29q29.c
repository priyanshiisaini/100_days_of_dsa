#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to rotate list
struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    struct Node *temp = head;
    int n = 1;

    // Step 1: Find length and last node
    while (temp->next != NULL) {
        temp = temp->next;
        n++;
    }

    // Step 2: Make circular
    temp->next = head;

    // Step 3: Reduce k if greater than n
    k = k % n;

    // Step 4: Find new last node (n-k steps)
    int steps = n - k;
    temp = head;

    for (int i = 1; i < steps; i++) {
        temp = temp->next;
    }

    // Step 5: Break the circle
    struct Node* newHead = temp->next;
    temp->next = NULL;

    return newHead;
}

int main() {
    int n, x, k;
    struct Node *head = NULL, *temp = NULL, *newNode;

    // Input n
    scanf("%d", &n);

    // Create linked list
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Input k
    scanf("%d", &k);

    // Rotate
    head = rotateRight(head, k);

    // Print result
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}