#include <stdio.h>

/* Data Structures Lab implementation */
#include <stdlib.h>

struct Term {
    int coef, exp;
    struct Term *next;
};

void addTerm(struct Term **poly, int c, int e) {
    struct Term *n = malloc(sizeof(struct Term));
    n->coef = c;
    n->exp = e;
    n->next = NULL;
    if (!*poly || (*poly)->exp < e) {
        n->next = *poly;
        *poly = n;
        return;
    }
    struct Term *t = *poly;
    while (t->next && t->next->exp > e) t = t->next;
    if (t->exp == e) { t->coef += c; free(n); return; }
    n->next = t->next;
    t->next = n;
}

void print(struct Term *p) {
    if (!p) { printf("0\n"); return; }
    while (p) {
        printf("%dx^%d", p->coef, p->exp);
        if (p->next) printf(" + ");
        p = p->next;
    }
    printf("\n");
}

struct Term *addPoly(struct Term *a, struct Term *b) {
    struct Term *res = NULL;
    while (a && b) {
        if (a->exp == b->exp) { addTerm(&res, a->coef + b->coef, a->exp); a = a->next; b = b->next; }
        else if (a->exp > b->exp) { addTerm(&res, a->coef, a->exp); a = a->next; }
        else { addTerm(&res, b->coef, b->exp); b = b->next; }
    }
    while (a) { addTerm(&res, a->coef, a->exp); a = a->next; }
    while (b) { addTerm(&res, b->coef, b->exp); b = b->next; }
    return res;
}

int main() {
    struct Term *p1 = NULL, *p2 = NULL;
    int n, c, e;

    printf("Terms in first polynomial: ");
    scanf("%d", &n);
    printf("Enter coefficient exponent pairs:\n");
    for (int i = 0; i < n; i++) { scanf("%d %d", &c, &e); addTerm(&p1, c, e); }

    printf("Terms in second polynomial: ");
    scanf("%d", &n);
    printf("Enter coefficient exponent pairs:\n");
    for (int i = 0; i < n; i++) { scanf("%d %d", &c, &e); addTerm(&p2, c, e); }

    printf("Poly 1: "); print(p1);
    printf("Poly 2: "); print(p2);
    printf("Sum: "); print(addPoly(p1, p2));

    return 0;
}
