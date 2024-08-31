///@brief creation and traversal in tree
///@param inorder left root right
///@param preorder root left right
///@param postorder left right root

#include<stdio.h>
#include<stdlib.h>

//node creation
struct node
{
    int data;
    struct node* left;
    struct node* right;  
};

struct node* createnode(int data){
    struct node* new = malloc(sizeof(struct node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(struct node* root){
        if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root){
        if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

int main(void){
    //root declaration
    struct node* root = createnode(12);

    //creation of data
    root->left = createnode(1);
    root->right = createnode(13);
    root->left->left = createnode(15);
    root->left->right = createnode(19);
    root->right->left = createnode(17);
    root->right->right = createnode(20);

    //traversing 
    printf("inorder traversal:  ");
    inorder(root);
    printf("\n");

    printf("preorder traversal:  ");
    preorder(root);
    printf("\n");

    printf("postorder traversal:  ");
    postorder(root);
    printf("\n");
}