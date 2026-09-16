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
    return (rear + 1)%max == front;
}

// function to insert rear
void enqueue(int n){
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
void dequeue(){
    if(isEmpty()){
        printf("\nQueue underflow\n");
    }
    else{
        int x = d_queue[front];
        if(front == rear){
            front = rear = -1;
        }
        else{
            front = (front + 1)%max;
        }
        printf("\n%d delete\n", x);
    }
}

// function to access front
void peek(){
    if(isEmpty()){
        printf("\nQueue underflow\n");
    }
    else{
        printf("\nPeek = %d\n", d_queue[front]);
    }
}

// function to display all elements of queue
void display(){
    if(isEmpty()){
        printf("\nQueue underflow\n");
    }
    else{
        int i = front;
        printf("\nQueue : front -> ");
        while(1){
            printf("%d  ", d_queue[i]);

            if(i == rear){
                break;
            }
            i = (i+1)%max;
        }
        printf("-> rear\n");
    }
}

// function to delete rear
void deleteRear(){
    if(isEmpty()){
        printf("\nQueue underflow\n");
    }
    else{
        int x = d_queue[rear];
        if(rear == front){
            front = rear = -1;
        }
        else{
            rear = (max + rear - 1) % max;
        }
        printf("\n%d deleted from rear\n", x);
    }
}

int main(){
    int option, value;

    while(1){
        printf("\n====== Queue Operations ======\n\n");
        printf("1. enqueue.\n");
        printf("2. dequeue.\n");
        printf("3. peek.\n");
        printf("4. display.\n");
        printf("5. exit.\n");
        printf("5. delete Rear.\n");

        printf("\nEnter option : ");
        scanf("%d", &option);

        switch(option){
            case 1:
                printf("Enter value : ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: printf("\nprogram terminated\n"); return 0;
            case 6: deleteRear(); break;
            default: printf("\nInvailed option\n");
        }
    }
}