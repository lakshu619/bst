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

int valid(int arr[], int n) {

    int i;

    for (i = 0; i < n - 1; i++) {

        if (arr[i] >= arr[i + 1]) {
            return 0;
        }
    }

    return 1;
}
