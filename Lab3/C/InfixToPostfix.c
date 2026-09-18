#include <stdio.h>

/* Data Structures Lab implementation */
#include <ctype.h>
#include <string.h>
#define MAX 100

char stk[MAX];
int top = -1;

void push(char c) { stk[++top] = c; }
char pop() { return stk[top--]; }
char peekTop() { return top == -1 ? -1 : stk[top]; }

int prec(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void toPostfix(char *in) {
    char out[MAX];
    int i = 0, k = 0;
    while (in[i]) {
        char c = in[i];
        if (isalnum(c)) out[k++] = c;
        else if (c == '(') push(c);
        else if (c == ')') { while (peekTop() != '(') out[k++] = pop(); pop(); }
        else { while (top != -1 && prec(peekTop()) >= prec(c)) out[k++] = pop(); push(c); }
        i++;
    }
    while (top != -1) out[k++] = pop();
    out[k] = '\0';
    printf("Postfix: %s\n", out);
}

int main() {
    char expr[MAX];
    printf("Enter infix expression: ");
    scanf("%s", expr);
    toPostfix(expr);
    return 0;
}
