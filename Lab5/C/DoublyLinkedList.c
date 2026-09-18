#include <stdio.h>

/* Data Structures Lab implementation */
#include <stdlib.h>

struct Node {
    int val;
    struct Node *prev, *next;
};

struct Node *head = NULL;

void addFront(int x) {
    struct Node *n = malloc(sizeof(struct Node));
    n->val = x;
    n->prev = NULL;
    n->next = head;
    if (head) head->prev = n;
    head = n;
}

void addBack(int x) {
    struct Node *n = malloc(sizeof(struct Node));
    n->val = x;
    n->next = NULL;
    if (!head) { n->prev = NULL; head = n; return; }
    struct Node *t = head;
    while (t->next) t = t->next;
    t->next = n;
    n->prev = t;
}

void del(int key) {
    struct Node *t = head;
    while (t) {
        if (t->val == key) {
            if (t->prev) t->prev->next = t->next; else head = t->next;
            if (t->next) t->next->prev = t->prev;
            free(t);
            printf("%d removed\n", key);
            return;
        }
        t = t->next;
    }
    printf("%d not found\n", key);
}

void showFwd() {
    struct Node *t = head;
    while (t) { printf("%d <-> ", t->val); t = t->next; }
    printf("NULL\n");
}

void showBack() {
    if (!head) { printf("NULL\n"); return; }
    struct Node *t = head;
    while (t->next) t = t->next;
    while (t) { printf("%d <-> ", t->val); t = t->prev; }
    printf("NULL\n");
}

int main() {
    int ch, x;
    while (1) {
        printf("\n1.AddFront 2.AddBack 3.Delete 4.ShowFwd 5.ShowBack 6.Exit\nChoice: ");
        scanf("%d", &ch);

          switch (ch) {
              case 1: printf("Value: "); scanf("%d", &x); addFront(x); break;
              case 2: printf("Value: "); scanf("%d", &x); addBack(x); break;
              case 3: printf("Value to delete: "); scanf("%d", &x); del(x); break;
              case 4: showFwd(); break;
              case 5: showBack(); break;
              case 6: return 0;
              default: printf("Invalid\n");
          }
    }
}
