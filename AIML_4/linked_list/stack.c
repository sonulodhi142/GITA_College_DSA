#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *top = NULL; 

// function to create a node
struct node *createNode(int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}


// function to insert top
void push(int data){
    struct node *newNode =createNode(data);
    newNode->next = top;
    top = newNode;
    printf("\n%d inserted\n", data);
}

// function to delete top
void pop(){
    if(top == NULL){
        printf("\nStack is empty\n");
    }
    else{
        struct node *temp = top;
        top = top->next;
        printf("\n%d deleted\n", temp->data);
        free(temp);
    }
}

// function to display top
void peek(){
    if(top == NULL){
        printf("\nStack is empty\n");
    }
    else{
        printf("\nPeek = %d\n", top->data);
    }
}

// function to display stack
void display(){
    if(top == NULL){
        printf("\nStack is empty\n");
    }
    else{
        struct node *temp = top;
        printf("\nStack : ");
        while(temp != NULL){
            printf("\n%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}


int main(){
    int choice, n;
    while (1){
        printf("\n=============== stack operations =============\n\n");
        printf("1. push.\n");
        printf("2. pop.\n");
        printf("3. peek.\n");
        printf("4. display.\n");
        printf("5. exit.\n");
        printf("\nEnter option : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter element to push : ");
            scanf("%d", &n);
            push(n);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("\nProgram terminated...\n");
            return 0;
            break;
        default:
            printf("\nIn-Vailed option..\n");
            break;
        }
    }
}