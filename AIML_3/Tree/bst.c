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

// function to insert node
struct node *insert(struct node *root, int data){
    if(root == NULL){
        return createNode(data);
    }
    else if(root->data > data) {
        root->left = insert(root->left, data);
    }
    else if(root->data < data) {
        root->right = insert(root->right, data);
    }
    else{
        printf("\nDuplicate value not allowed\n");
    }
    return root;
}


// inorder traversal
void inorder(struct node *root){
    if(root == NULL) return;
    inorder(root->left);
    printf("%d  ", root->data);
    inorder(root->right);
}

// function to search element
struct node *search(struct node *root, int value){
    if(root == NULL){
        return NULL;
    }

    if(root->data == value ){
        return root;
    }
    else if( root->data > value){
        return search(root->left, value);
    }
    else{
        return search(root->right, value);
    }
}

// function to find min
struct node *findMin(struct node *root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

// function to deleteNode
struct node *deleteNode(struct node *root, int value){
    if(root == NULL){
        printf("\n value not found");
        return NULL;
    }

    if(value < root->data){
        root->left = deleteNode(root->left, value);
    }
    else if(value > root->data){
        root->right = deleteNode(root->right, value);
    }
    else {
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }
        else if(root->left == NULL){
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        else{
            struct node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

int main(){
   
}