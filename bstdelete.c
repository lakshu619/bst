#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* create(struct node *root, int data) {
    if (root == NULL) {
        root = (struct node*)malloc(sizeof(struct node));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    if (data < root->data)
        root->left = create(root->left, data);
    else
        root->right = create(root->right, data);

    return root;
}

struct node* findMin(struct node *root) {
    while (root->left != NULL)
        root = root->left;

    return root;
}

struct node* deleteNode(struct node *root, int key) {

    // Node not found
    if (root == NULL)
        return root;

    // Search in left subtree
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }

    // Search in right subtree
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }

    // Node found
    else {

        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        // Case 2: Only right child
        else if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        }

        // Case 2: Only left child
        else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Two children
        else {
            struct node *temp = findMin(root->right);

            root->data = temp->data;

            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {

    struct node *root = NULL;

    root = create(root, 50);
    root = create(root, 30);
    root = create(root, 70);
    root = create(root, 20);
    root = create(root, 40);
    root = create(root, 60);
    root = create(root, 80);

    printf("Before deletion: ");
    inorder(root);

    root = deleteNode(root, 50);

    printf("\nAfter deletion: ");
    inorder(root);

    return 0;
}
