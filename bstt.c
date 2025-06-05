//Binary Search Tree (BST) – Insert + Inorder
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* insert(struct Node* root, int val) {
    if (root == NULL) {
        struct Node* newNode = malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);

    printf("Inorder Traversal: ");
    inorder(root);

    return 0;
}
