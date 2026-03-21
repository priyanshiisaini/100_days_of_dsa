#include <stdio.h>
#define MAX 1000

int queue[MAX];
int front = -1, rear = -1;
int size;

// Enqueue
void enqueue(int val) {
    if ((rear + 1) % size == front) {
        // Queue full (not needed here as per question)
        return;
    }
    
    if (front == -1) { // first element
        front = rear = 0;
    } else {
        rear = (rear + 1) % size;
    }
    
    queue[rear] = val;
}

// Dequeue
void dequeue() {
    if (front == -1) return; // empty
    
    if (front == rear) {
        front = rear = -1; // last element removed
    } else {
        front = (front + 1) % size;
    }
}

// Print queue
void printQueue() {
    if (front == -1) return;
    
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % size;
    }
}

int main() {
    int n, m, x;
    
    scanf("%d", &n);
    size = n; // important
    
    // Enqueue n elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }
    
    // Dequeue m times
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        dequeue();
    }
    
    // Print result
    printQueue();
    
    return 0;
}