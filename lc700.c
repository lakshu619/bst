
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *create(struct node *root,int data){
    if(root==NULL){
        root=(struct node *)malloc(sizeof(struct node));
        root->data=data;
        root->left=NULL;
        root->right=NULL;
    }
    else if(data<root->data){
        root->left=create(root->left,data);
    }
    else{
        root->right=create(root->right,data);
    }
    return(root);
}
struct node *search(struct node *root, int data) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search(root->left, data);
    }

    return search(root->right, data);
}
void pre_order(struct node *root){
    printf("%d ",root->data);
     if(root->left!=NULL){
        pre_order(root->left);
    }
    if(root->right!=NULL){
        pre_order(root->right);
    }
    
}

int main()
{
     struct node *root=NULL;
    int i;
    srand(time(NULL));
    int num;
    for(i=0;i<7;i++){
        num=rand()%100;
        root=create(root,num);
    }
    pre_order(root);
    int data;
    printf("enter a num");
    scanf("%d",&data);
    root=search(root,data);
    pre_order(root);
    

    return 0;
}
