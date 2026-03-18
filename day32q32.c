#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push
void push(int x) {
    if (top < MAX - 1) {
        top++;
        stack[top] = x;
    }
}

// Pop
void pop() {
    if (top != -1) {
        top--;
    }
}

// Display
void display() {
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
}

int main() {
    int n, m, x;

    // number of elements
    scanf("%d", &n);

    // push all elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        push(x);
    }

    // number of pops
    scanf("%d", &m);

    // perform m pops
    for (int i = 0; i < m; i++) {
        pop();
    }

    // display remaining stack
    display();

    return 0;
}