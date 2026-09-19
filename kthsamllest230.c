#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

void createarr(struct node *root, int arr[], int *index) {

    if (root == NULL)
        return;

    if (root->left != NULL) {
        createarr(root->left, arr, index);
    }

    arr[*index] = root->data;
    (*index)++;

    if (root->right != NULL) {
        createarr(root->right, arr, index);
    }
}

int kthsmall(int arr[], int n, int k) {

    int i;

    for (i = 0; i < n; i++) {

        if (i == k - 1) {
            return arr[i];
        }
    }

    return -1;
}
