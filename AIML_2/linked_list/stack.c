#include<stdio.h>
#include<stdlib.h>

// single linked list node
struct node{
    int data;
    struct node *next;
};

struct node *top = NULL;

// function to create node
struct node *createNode(int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// function to insert at top
void push(int data){
    struct node *newNode = createNode(data);

    newNode->next = top;
    top = newNode;
    printf("%d inserted\n", data);
}

// function to delete top
void pop(){
    if(top == NULL){
        printf("\nstack is empty\n");
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
        printf("\nstack is empty\n");
    }
    else{
        printf("\nPeek = %d\n", top->data);
    }
}

// function to desplay stack
void display(){
    if(top == NULL){
        printf("\nstack is empty\n");
    }
    else{
        struct node *temp = top;
        printf("\nStack : ");
        while(temp != NULL){
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}


int main(){
    int option, value;
    while (1)
    {
        printf("\n================ Stack Operations================\n\n");
        printf("1. push.\n");
        printf("2. pop.\n");
        printf("3. peek.\n");
        printf("4. display.\n");
        printf("5. exit.\n");
        printf("\nEnter option : ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Enter element : ");
            scanf("%d", &value);
            push(value);
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
            printf("\nProgram terminated successfully\n\n");
            return 0;
        default:
            printf("\nIn-vailed option\n");
            break;
        }
        
    }
    
}