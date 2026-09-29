#include<stdio.h>
#include<stdlib.h>

// node structure
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// function to create node
struct node *createNode(int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));

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

int main(){
    struct node *root = NULL;
    root = createNode(70);
    root->left = createNode(50);
    root->right = createNode(30);
    root->left->left = createNode(10);
    root->left->right = createNode(100);

    inorder(root);
    return 0;
}