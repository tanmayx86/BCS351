#include <stdio.h>

/* Data Structures Lab implementation */
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
};

struct Node *head = NULL;

void addFront(int x) {
    struct Node *n = malloc(sizeof(struct Node));
    n->val = x;
    n->next = head;
    head = n;
}

void addBack(int x) {
    struct Node *n = malloc(sizeof(struct Node));
    n->val = x;
    n->next = NULL;
    if (!head) { head = n; return; }
    struct Node *t = head;
    while (t->next) t = t->next;
    t->next = n;
}

void addAt(int x, int pos) {
    if (pos <= 0) { addFront(x); return; }
    struct Node *t = head;
    for (int i = 0; t && i < pos - 1; i++) t = t->next;
    if (!t) { printf("Position out of range\n"); return; }
    struct Node *n = malloc(sizeof(struct Node));
    n->val = x;
    n->next = t->next;
    t->next = n;
}

void delFront() {
    if (!head) { printf("List empty\n"); return; }
    struct Node *t = head;
    head = head->next;
    free(t);
}

void delBack() {
    if (!head) { printf("List empty\n"); return; }
    if (!head->next) { free(head); head = NULL; return; }
    struct Node *t = head;
    while (t->next->next) t = t->next;
    free(t->next);
    t->next = NULL;
}

void delAt(int pos) {
    if (!head) { printf("List empty\n"); return; }
    if (pos <= 0) { delFront(); return; }
    struct Node *t = head, *prev = NULL;
    for (int i = 0; t && i < pos; i++) { prev = t; t = t->next; }
    if (!t) { printf("Position out of range\n"); return; }
    prev->next = t->next;
    free(t);
}

void show() {
    struct Node *t = head;
    while (t) { printf("%d -> ", t->val); t = t->next; }
    printf("NULL\n");
}

int main() {
    int ch, x, p;
    while (1) {
        printf("\n1.AddFront 2.AddBack 3.AddAt 4.DelFront 5.DelBack 6.DelAt 7.Show 8.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
             case 1: printf("Value: "); scanf("%d", &x); addFront(x); break;
             case 2: printf("Value: "); scanf("%d", &x); addBack(x); break;
             case 3: printf("Value, Position: "); scanf("%d %d", &x, &p); addAt(x, p); break;
             case 4: delFront(); break;
             case 5: delBack(); break;
             case 6: printf("Position: "); scanf("%d", &p); delAt(p); break;
             case 7: show(); break;
             case 8: return 0;
             default: printf("Invalid\n");
        }
    }
}
