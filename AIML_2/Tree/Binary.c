#include<stdio.h>
#include<stdlib.h>

// node structure
struct node{
    int data;
    struct node *left;
    struct node *right;
};

// function to create node
struct node *createNode(int data){
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// inorder
void Inorder(struct node *root){
    struct node *stack[20];
    int top = -1;
    struct node *current = root;
    while(current != NULL || top != -1 ){

        while(current != NULL){
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d  ", current->data);

        current = current->right;
    }
}

// preorder
void Preorder(struct node *root){
    struct node *stack[20];
    int top = -1;

    struct node *current;
    stack[++top] = root;
    while(top != -1){

        current = stack[top--];
        printf("%d  ", current->data);

        if(current->right != NULL){
            stack[++top] = current->right;
        }

        if(current->left != NULL){
            stack[++top] = current->left;
        }
    }
}

// postorder
void Postorder(struct node *root){
    struct node *stack1[20];
    int top1 = -1;
    struct node *stack2[20];
    int top2 = -1;

    struct node *current;
    stack1[++top1] = root;
    while(top1 != -1){

        current = stack1[top1--];
        stack2[++top2] = current;

        if(current->left != NULL){
            stack1[++top1] = current->left;
        }
        if(current->right != NULL){
            stack1[++top1] = current->right;
        }
    }

    while (top2 != -1)
    {
        current = stack2[top2--];
        printf("%d  ", current->data);
    }
}

int main(){
    struct node *root = NULL;

    root = createNode(50);
    root->left = createNode(30);
    root->right = createNode(70);
    root->left->left = createNode(20);
    root->left->right = createNode(30);
    root->right->left = createNode(60);
    root->right->right = createNode(80);

    printf("\nIonrder : ");
    Inorder(root);
    printf("\nPreorder : ");
    Preorder(root);
    printf("\nPostorder : ");
    Postorder(root);
}