#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;  // number of nodes

    // 👉 Taking input for number of elements
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode;
    int value;

    // 👉 Creating circular linked list
    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);   // 👉 taking each value input

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;

        if (head == NULL) {
            head = newNode;
            newNode->next = head;  // first node points to itself
            temp = head;
        } else {
            temp->next = newNode;
            newNode->next = head;  // maintain circular link
            temp = newNode;
        }
    }

    // 👉 Printing the circular linked list
    printf("Circular Linked List: ");

    if (head != NULL) {
        temp = head;
        do {
            printf("%d ", temp->data);  // 👉 printing values
            temp = temp->next;
        } while (temp != head);
    }

    return 0;
}