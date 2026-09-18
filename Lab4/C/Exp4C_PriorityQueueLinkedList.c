#include <stdio.h>

/* Data Structures Lab implementation */
#include <stdlib.h>

struct Node {
    int data, prio;
    struct Node *next;
};

struct Node *head = NULL;

void enqueue(int data, int prio) {
    struct Node *n = malloc(sizeof(struct Node));
    n->data = data;
    n->prio = prio;
    if (!head || prio < head->prio) { n->next = head; head = n; return; }
    struct Node *t = head;
    while (t->next && t->next->prio <= prio) t = t->next;
    n->next = t->next;
    t->next = n;
}

void dequeue() {
    if (!head) { printf("Queue is empty\n"); return; }
    struct Node *t = head;
    printf("Dequeued: %d\n", t->data);
    head = head->next;
    free(t);
}

void display() {
    if (!head) { printf("Queue is empty\n"); return; }
    struct Node *t = head;
    printf("Queue: ");
    while (t) { printf("(%d,p%d) ", t->data, t->prio); t = t->next; }
    printf("\n");
}

int main() {
    int ch, data, prio;
    while (1) {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
             case 1: printf("Data Priority: "); scanf("%d %d", &data, &prio); enqueue(data, prio);
display(); break;
             case 2: dequeue(); display(); break;
             case 3: display(); break;
             case 4: return 0;
             default: printf("Invalid\n");
        }
    }
}
