#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

// Check if full
int isFull() {
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

// Check if empty
int isEmpty() {
    return (front == -1);
}

// Insert at front
void push_front(int value) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    }
    else if (front == 0) {
        front = MAX - 1;
    }
    else {
        front--;
    }

    deque[front] = value;
}

// Insert at rear
void push_back(int value) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    }
    else if (rear == MAX - 1) {
        rear = 0;
    }
    else {
        rear++;
    }

    deque[rear] = value;
}

// Delete from front
void pop_front() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted: %d\n", deque[front]);

    if (front == rear) {
        front = rear = -1;
    }
    else if (front == MAX - 1) {
        front = 0;
    }
    else {
        front++;
    }
}

// Delete from rear
void pop_back() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted: %d\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;
    }
    else if (rear == 0) {
        rear = MAX - 1;
    }
    else {
        rear--;
    }
}

// Get front element
void getFront() {
    if (isEmpty()) {
        printf("Deque is empty\n");
    } else {
        printf("Front: %d\n", deque[front]);
    }
}

// Get rear element
void getBack() {
    if (isEmpty()) {
        printf("Deque is empty\n");
    } else {
        printf("Rear: %d\n", deque[rear]);
    }
}

// Size
void getSize() {
    if (isEmpty()) {
        printf("Size: 0\n");
        return;
    }

    int size;
    if (rear >= front)
        size = rear - front + 1;
    else
        size = MAX - front + rear + 1;

    printf("Size: %d\n", size);
}

// Display
void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }

    int i = front;
    printf("Deque: ");

    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Main
int main() {
    push_back(10);
    push_back(20);
    push_front(5);
    push_back(30);

    display();       // 5 10 20 30
    getFront();      // 5
    getBack();       // 30
    getSize();       // 4

    pop_front();     // remove 5
    pop_back();      // remove 30

    display();       // 10 20

    return 0;
}