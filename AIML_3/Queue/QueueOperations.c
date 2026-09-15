#include<stdio.h>
#define max 5

int queue[max];
int front = -1;
int rear = -1;

int isFull(){
    return rear == max-1;
}

int isEmpty(){
    return front == -1 || front > rear;
}

// function to insert a element at rear
void enQueue(int n){
    if(isFull()){
        printf("\nQueue overflow\n");
        return;
    }
    else{
        if(front == -1){
            front = rear = 0;
        }
        else{
            rear++;
        }
        queue[rear] = n;
        printf("\n%d inserted\n", n);
    }
}

// function to delete element from the queue
void deQueue(){
    if(isEmpty()){
        printf("\nQueue underflow\n");
        return;
    }
    else{
        printf("\n%d is deleted\n", queue[front]);
        front++;
        if(front > rear){
            front = rear = -1;
        }
    }
}

// function to get front
void peek(){
    if(isEmpty()){
        printf("\nQueue underflow\n");
        return;
    }
    printf("\nPeek = %d\n", queue[front]);
}

// functio to display all element of queue
void display(){
    int i;
    if(isEmpty()){
        printf("\nQueue underflow\n");
        return;
    }
    printf("\nQueue : ");
    for(i = front; i <= rear; i++){
        printf("%d  ", queue[i]);
    }
    printf("\n");
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
            enQueue(value);
            break;
        case 2:
            deQueue();
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