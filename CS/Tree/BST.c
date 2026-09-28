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
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// function to insert node
struct node *insertNode(struct node *root, int data){
    if(root == NULL){
        return createNode(data);
    }
    else if(root->data > data){
        root->left = insertNode(root->left, data);
    }
    else if(root->data < data){
        root->right = insertNode(root->right, data);
    }
    else{
        return root;
    }
}

int main(){
    struct node *root = NULL;

    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 10);
    
    inorder(root);
}










