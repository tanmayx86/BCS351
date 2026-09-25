#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;
Node *newNode(int value)
{
    Node *temp = malloc(sizeof(Node));

    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    temp->value = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node *add(Node *tree, int value)
{
    if (tree == NULL)
        return newNode(value);

    if (value < tree->value)
        tree->left = add(tree->left, value);
    else if (value > tree->value)
        tree->right = add(tree->right, value);

    return tree;
}
void display(Node *tree)
{
    if (tree == NULL)
        return;

    display(tree->left);
    printf("%d ", tree->value);
    display(tree->right);
}
int main()
{
    Node *tree = NULL;
    int option, value;
    do {
        printf("\n1. Insert\n");
        printf("2. Display Inorder\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &option);

        if (option == 1) {
            printf("Enter value: ");
            scanf("%d", &value);
            tree = add(tree, value);
        }
        else if (option == 2) {
            printf("Inorder: ");
            display(tree);
            printf("\n");
        }
        else if (option == 3) {
            printf("Program ended.\n");
        }
        else {
            printf("Invalid choice.\n");
        }

    } while (option != 3);
    return 0;
}
