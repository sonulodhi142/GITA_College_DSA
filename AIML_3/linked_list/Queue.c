#include<stdio.h>
#include<stdlib.h>
// create a node
struct node{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

// function to create node
struct node *createNode(int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// function to insert rear
void enqueue(int data){
    struct node *newNode = createNode(data);

    if(front == NULL){
        front = rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }
    printf("\n%d inserted\n", data);
}

// function to delete front
void dequeue(){
    if(front == NULL){
        printf("\nQueue is empty\n");
    }
    else{
        struct node *temp = front;
        if(front == rear){
            front = rear = NULL;
        }
        else{
            front = front->next;
        }
        printf("\n%d deleted\n", temp->data);
        free(temp);
    }
}


// function to display front
void peek(){
    if(front == NULL){
        printf("\nQueue is empty\n");
    }
    else{
        printf("\nPeek = %d\n", front->data);
    }
}

// function to display Queue
void display(){
    if(front == NULL){
        printf("\nQueue is empty\n");
    }
    else{
        struct node *temp = front;
        printf("\nQueue : ");
        while(temp != NULL){
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}


int main(){
    int option, value;
    while(1){
        printf("\n============= Queue Operations ===========\n\n");
        printf("1. Enqueue.\n");
        printf("2. Dequeue. \n");
        printf("3. Peek.\n");
        printf("4. Display\n");
        printf("5. exit.\n");
        printf("Enter option : ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Enter value : ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("\nProgram terminated successfully\n");
            return 0;
        default:
            printf("\nIn-vailed option.\n");
            break;
        }
    }

}