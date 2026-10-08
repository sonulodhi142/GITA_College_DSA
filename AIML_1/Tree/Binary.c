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

// preorder traversal
void preorder(struct node *root){
    if(root == NULL) return;
    printf("%d  ", root->data);
    preorder(root->left);
    preorder(root->right);
}
// inorder traversal
void inorder(struct node *root){
    if(root == NULL) return;
    inorder(root->left);
    printf("%d  ", root->data);
    inorder(root->right);
}
// postorder traversal
void postorder(struct node *root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d  ", root->data);
}

int main(){
    struct node *root = NULL;
    root = createNode(70);
    root->left = createNode(50);
    root->right = createNode(30);
    root->left->left = createNode(10);
    root->left->right = createNode(100);

    printf("\n");
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    return 0;
}