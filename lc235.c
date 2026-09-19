struct node* lowestCommonAncestor(struct node* root,
                                  struct node* p,
                                  struct node* q) {

    if (p->data < root->data && q->data < root->data) {
        return lowestCommonAncestor(root->left, p, q);
    }

    else if (p->data > root->data && q->data > root->data) {
        return lowestCommonAncestor(root->right, p, q);
    }

    else {
        return root;
    }
}
