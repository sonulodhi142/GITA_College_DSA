#include<stdio.h>
#define max 5

int d_queue[max];
int front = -1;
int rear = -1;

// function to check queue is empty or not
int isEmpty(){
    return front == -1;
}

// function to check queue is full or not
int isFull(){
    return (rear+1)%max == front;
}

// function to insert rear
void insertRear(int n){
    if(isFull()){
        printf("\nQueue overflow\n");
    }
    else{
        if(isEmpty()){
            front = rear = 0;
        }
        else{
            rear = (rear+1)%max;
        }
        d_queue[rear] = n;
        printf("\n%d inserted\n", n);
    }
} 

// function to delete front
void deleteFront(){
    if(isEmpty()){
        printf("\nQueue underflow\n");
    }
    else{
        int x = d_queue[front];
        if(front == rear){
            front = rear = -1;
        }
        else{
            front = (front+1)%max;
        }
        printf("\n%d deleted\n", x);
    }
}

// function to insert front
void insertFront(int value){
    if(isFull()){
        printf("\nQueue overflow\n");
    }
    else{
        if(isEmpty()){
            front = rear = 0;
        }
        else{
            front = (max+front-1)%max;
        }
        d_queue[front] = value;
        printf("\n%d inserted at front", value);
    }
}

// function to delete Rear
void deleteRear(){
    if(isEmpty()){
        printf("\nQueue underflow\n");
    }
    else{
        int x = d_queue[rear];
        if(front == rear){
            front = rear = -1;
        }
        else{
            rear = (max+rear-1)%max;
        }
        printf("\n%d deleted from rear\n");
    }
}

// function to access peek element
void peek(){
    if(isEmpty()){
        printf("\nQueue underflow\n");
    }
    else{
        printf("\nPeek = %d\n", d_queue[front]);
    }
}

// function to display all element of queue
void display(){
    if(isEmpty()){
        printf("\nQueue underflow\n");
    }
    else{
        int i = front;
        printf("\nQueue : front -> ");
        while(1){
            printf("[%d]%d  ",i, d_queue[i]);
            
            if(i == rear){
                break;
            }
            i = (i+1)%max;
        }
        printf("-> rear");
    }
}


int main(){
    int option, value;
    while (1)
    {
        printf("\n=========== Double ended Queue Operations ===========\n\n");
        printf("1. Insert Rear.\n");
        printf("2. Insert Front.\n");
        printf("3. Delete Rear.\n");
        printf("4. Delete Front.\n");
        printf("5. Peek.\n");
        printf("6. Display.\n");
        printf("7. Exit.\n");
        printf("\nEnter option : ");
        scanf("%d", &option);

        switch(option){
            case 1:
                printf("\nEnter value : ");
                scanf("%d", &value);
                insertRear(value);
                break;
            case 2:
                printf("\nEnter value : ");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 3: deleteRear(); break;
            case 4: deleteFront(); break;
            case 5: peek(); break;
            case 6: display(); break;
            case 7: printf("\nprogram terminated\n"); return 0;
            default: printf("\nInvailed option\n"); break; 
        }
    } 
}