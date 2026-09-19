#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* insertIntoBST(struct node* root, int val) {
    if(root == NULL) {
        root = (struct node*)malloc(sizeof(struct node));
        root->data = val;
        root->left = NULL;
        root->right = NULL;
    }
    else if(val < root->data) {
        root->left = insertIntoBST(root->left, val);
    }
    else if(val > root->data) {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}
