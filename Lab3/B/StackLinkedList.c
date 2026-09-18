#include <stdio.h>

/* Data Structures Lab implementation */
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int x) {
    struct Node *n = malloc(sizeof(struct Node));
    n->data = x;
    n->next = top;
    top = n;
    printf("%d pushed\n", x);
}

void pop() {
    if (!top) { printf("Stack underflow\n"); return; }
    struct Node *t = top;
    printf("%d popped\n", t->data);
    top = top->next;
    free(t);
}

void peek() {
    if (!top) printf("Stack is empty\n");
    else printf("Top element: %d\n", top->data);
}

void display() {
    if (!top) { printf("Stack is empty\n"); return; }
    struct Node *t = top;
    printf("Stack: ");
    while (t) { printf("%d ", t->data); t = t->next; }
    printf("\n");
}

int main() {
    int ch, x;
    while (1) {
        printf("\n1.Push 2.Pop 3.Peek 4.Display 5.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
             case 1: printf("Value: "); scanf("%d", &x); push(x); break;
             case 2: pop(); break;
             case 3: peek(); break;
             case 4: display(); break;
             case 5: return 0;
             default: printf("Invalid\n");
        }
    }
}
