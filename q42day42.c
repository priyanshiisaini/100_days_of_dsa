#include <stdio.h>
#include <stdlib.h>

// Queue implementation (array)
#define MAX 1000
int queue[MAX];
int front = 0, rear = -1;

// Stack implementation (array)
int stack[MAX];
int top = -1;

// Queue operations
void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    if (front > rear) return -1;
    return queue[front++];
}

// Stack operations
void push(int x) {
    stack[++top] = x;
}

int pop() {
    if (top == -1) return -1;
    return stack[top--];
}

int main() {
    int N, x;
    scanf("%d", &N);

    // Input queue elements
    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // Step 1: Move queue -> stack
    while (front <= rear) {
        push(dequeue());
    }

    // Step 2: Print reversed (stack)
    while (top != -1) {
        printf("%d ", pop());
    }

    return 0;
}