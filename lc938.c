#include <stdio.h>
#include <stdlib.h>

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

int range(struct node *root, int left, int right)
{
    if(root == NULL)
    {
        return 0;
    }

    if(root->data < left)
    {
        return range(root->right, left, right);
    }

    if(root->data > right)
    {
        return range(root->left, left, right);
    }

    return root->data
           + range(root->left, left, right)
           + range(root->right, left, right);
}
int main()
{
     struct node *root=NULL;
    int i;
    int num;
    int data;
    printf("enter no of elements");
    scanf("%d",&num);
    for(i=0;i<num;i++){
        printf("enter data:");
        scanf("%d",&data);
        root=create(root,data);
    }
    int low,high;
    printf("enter low range:");
    scanf("%d",&low);
    printf("enter high range");
    scanf("%d",&high);
    int sum=range(root,low,high);
    printf("the sum is :%d",sum);
    return 0;
}
