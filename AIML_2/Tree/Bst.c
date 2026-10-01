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

// preorder traversal
void preorder(struct node *root){
    if(root == NULL) return;
    printf("%d  ", root->data);
    preorder(root->left);
    preorder(root->right);
}
// postorder traversal
void postorder(struct node *root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d  ", root->data);
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
   struct node *root = NULL;

   root = insert(root, 50);
   root = insert(root, 30);
   root = insert(root, 40);
   root = insert(root, 70);

   struct node *result = search(root, 40);
   if(result != NULL){
    printf("\nvalue found\n");
   }
   else{
    printf("\nvalue not found\n");
   }

   root = deleteNode(root, 40);

   printf("\n");
   inorder(root);
   printf("\n");
   preorder(root);
   printf("\n");
   postorder(root);
   printf("\n");
}

