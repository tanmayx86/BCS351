#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a new node
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Build the binary tree
struct Node *buildTree() {
    int data;

    printf("Enter data (-1 for no node): ");

    if (scanf("%d", &data) != 1) {
        printf("Invalid input!\n");
        exit(1);
    }

    // -1 represents an empty node
    if (data == -1) {
        return NULL;
    }

    struct Node *root = createNode(data);

    printf("Enter left child of %d:\n", data);
    root->left = buildTree();

    printf("Enter right child of %d:\n", data);
    root->right = buildTree();

    return root;
}

// Pre-order: Root -> Left -> Right
void preOrder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// In-order: Left -> Root -> Right
void inOrder(struct Node *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Post-order: Left -> Right -> Root
void postOrder(struct Node *root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

// Free the memory occupied by the tree
void freeTree(struct Node *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct Node *root;

    printf("=== Binary Tree Creation ===\n");
    printf("Enter -1 when there is no node.\n\n");

    root = buildTree();

    printf("\n=== Binary Tree Traversals ===\n");

    printf("Pre-order : ");
    preOrder(root);

    printf("\nIn-order  : ");
    inOrder(root);

    printf("\nPost-order: ");
    postOrder(root);

    printf("\n");

    // Free allocated memory
    freeTree(root);

    return 0;
}
