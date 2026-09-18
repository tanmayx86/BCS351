#include <stdio.h>

/* Data Structures Lab implementation */
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
};

struct Node *head = NULL;

void insert(int x) {
    struct Node *n = malloc(sizeof(struct Node));
    n->val = x;
    if (!head) {
        head = n;
        n->next = head;
        return;
    }
    struct Node *t = head;
    while (t->next != head) t = t->next;
    t->next = n;
    n->next = head;
}

void del(int key) {
    if (!head) { printf("Empty list\n"); return; }
    struct Node *cur = head, *prev = NULL;
    do {
         if (cur->val == key) {
             if (cur == head) {
                 if (cur->next == head) { free(cur); head = NULL; return; }
                 struct Node *last = head;
                 while (last->next != head) last = last->next;
                 head = head->next;
                 last->next = head;
             } else {
                 prev->next = cur->next;
             }
             free(cur);
             printf("%d removed\n", key);
             return;
         }
         prev = cur;
         cur = cur->next;
    } while (cur != head);
    printf("%d not found\n", key);
}

void show() {
    if (!head) { printf("Empty list\n"); return; }
    struct Node *t = head;
    do { printf("%d -> ", t->val); t = t->next; } while (t != head);
    printf("(back to start)\n");
}

int main() {
    int ch, x;
    while (1) {
        printf("\n1.Insert 2.Delete 3.Show 4.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
             case 1: printf("Value: "); scanf("%d", &x); insert(x); break;
             case 2: printf("Value to delete: "); scanf("%d", &x); del(x); break;
             case 3: show(); break;

              case 4: return 0;
              default: printf("Invalid\n");
          }
    }
}
