#include<stdio.h>
#include<stdlib.h>

// node structure
struct node {
    int data;
    struct node *left;
    struct node *right;
};

//function to create Node
struct node *createNode(int data){
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// inorder traversal
void inorder(struct node *root){
    if(root == NULL) return;
    inorder(root->left);
    printf("%d  ", root->data);
    inorder(root->right);
}

// preorder traversal
void preorder(struct node *root){
    if(root == NULL) return;
    printf("%d  ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main(){
    struct node *root = NULL;
    root = createNode(70);
    root->left = createNode(100);
    root->right = createNode(40);
    root->left->left = createNode(60);
    root->left->right = createNode(30);

    inorder(root);
    return 0;
}