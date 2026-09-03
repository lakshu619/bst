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
void in_order(struct node *root){
    if(root->left!=NULL){
        in_order(root->left);
    }
    printf("%d ",root->data);
    if(root->right!=NULL){
        in_order(root->right);
    }
}
void pre_order(struct node *root){
    printf("%d",root->data);
     if(root->left!=NULL){
        in_order(root->left);
    }
    if(root->right!=NULL){
        in_order(root->right);
    }
    
}
void post_order(struct node *root){
    if(root->left!=NULL){
        in_order(root->left);
    }
    if(root->right!=NULL){
        in_order(root->right);
    }
    printf("%d",root->data);
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
    //in_order(root);
    pre_order(root);
    //post_order(root);

    return 0;
}
