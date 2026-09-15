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
    return (rear + 1) % max == front;
}

// function to insert at rear
void insertRear(int n){
    if(isFull()){
        printf("\nQueue overflow\n");
    }
    else{
        if(isEmpty()){
            front = rear = 0;
        }
        else if(rear == max-1){
            rear = 0;
        }
        else{
            rear++;
        }
        d_queue[rear] = n;
        printf("\n%d inserted at rear\n", n);
    }
}

// function to insert fornt
void insertFront(int n){
    if(isFull()){
        printf("\nQueue overflow\n");
    }
    else{
        if(isEmpty()){
            front = rear = 0;
        }
        else if(front == 0){
            front = max-1;
        }
        else{
            front--;
        }
        d_queue[front] = n;
        printf("\n%d inseted at front\n", n);
    }
}

// function to delete rear
void deleteRear(){
    if(isEmpty()){
        printf("\nQueue underflow\n");
    }
    else{
        int n = d_queue[rear];
        if(rear == 0){
            rear = max-1;
        }
        else if(rear == front){
            rear = front = -1;
        }
        else{
            rear--;
        }
        printf("\n%d deleted from rear\n", n);
    }
}

// function to delete front
void deleteFront(){
    if(isEmpty()){
        printf("\nQueue underflow\n");
    }
    else{
        int n = d_queue[front];
        if(front == max-1){
            front = 0;
        }
        else if(front == rear){
            front = rear = -1;
        }
        else{
            front++;
        }
        printf("\n%d deleted from front\n", n);
    }
}

// function to display all element of queue
void display(){
    if(isEmpty()){
        printf("\nQueue underflow\n");
    }
    else{
        printf("\nQueue : ");
        int i = front;
        while(1){
            printf("%d  ", d_queue[i]);

            if(i == rear){
                break;
            }
            i = (i+1)%max;
        }
        printf("\n");
    }
}
// function to access front element from the queue
void peek(){
    if(isEmpty()){
        printf("\nQueue is underflow\n");
    }
    else{
        printf("\nPeek = %d\n", d_queue[front]);
    }
}

int main(){
    int option, value;
    while(1){
        printf("\n======= Double End Queue Operations ========\n\n");
        printf("1. insert front.\n");
        printf("2. insert rear.\n");
        printf("3. delete front.\n");
        printf("4. delete rear.\n");
        printf("5. peek\n");
        printf("6. display.\n");
        printf("7. exit program.\n");

        printf("\nEnter option : ");
        scanf("%d", &option);

        switch(option){
            case 1:
                printf("Enter value to insert front : ");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 2:
                printf("Enter value to insert rear : ");
                scanf("%d", &value);
                insertRear(value);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                peek();
                break;
            case 6:
                display();
                break;
            case 7:
                printf("\nprogram terminated successfully...\n");
                return 0;
            default: 
                printf("\nEnter correct optoin.\n");
        }
    }
}
