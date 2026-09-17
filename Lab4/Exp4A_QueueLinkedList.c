#include <stdio.h>

/* Data Structures Lab implementation */
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int x) {
    struct Node *n = malloc(sizeof(struct Node));
    n->data = x;
    n->next = NULL;
    if (!rear) { front = rear = n; }
    else { rear->next = n; rear = n; }
    printf("%d enqueued\n", x);
}

void dequeue() {
    if (!front) { printf("Queue underflow\n"); return; }
    struct Node *t = front;
    printf("%d dequeued\n", t->data);
    front = front->next;
    if (!front) rear = NULL;
    free(t);
}

void peek() {
    if (!front) printf("Queue is empty\n");
    else printf("Front element: %d\n", front->data);
}

void display() {
    if (!front) { printf("Queue is empty\n"); return; }
    struct Node *t = front;
    printf("Queue: ");
    while (t) { printf("%d ", t->data); t = t->next; }
    printf("\n");
}

int main() {
    int ch, x;
    while (1) {
        printf("\n1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
             case 1: printf("Value: "); scanf("%d", &x); enqueue(x); break;
             case 2: dequeue(); break;
             case 3: peek(); break;
             case 4: display(); break;
             case 5: return 0;
             default: printf("Invalid\n");
        }
    }
}
