#include<stdio.h>
#define max 5

int c_queue[max];
int rear = -1;
int front = -1;

// function to check the queue is empty or not
int isEmpty(){
    return front == -1;
}

// function to check queue is full or not
int isFull(){
    return (rear + 1) % max == front;
}

// function to insert element in queue
void enqueue(int n){
    if(isFull()){
        printf("\nQueue overflow\n");
    }
    else{
        if(isEmpty()){
            front = rear = 0;
        }
        else{
            rear = (rear+1) % max;
        }
        c_queue[rear] = n;
        printf("\n%d inserted\n", n);
    }
}

// functionto delete a element from the queue
void dequeue(){
    if(isEmpty()){
        printf("\n Queue underflow\n");
    }
    else{
        printf("\n%d deleted\n", c_queue[front]);
        if(rear == front){
            rear = front = -1;
        }
        else{
            front = (front + 1) % max;
        }
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
        while (1){
            printf("%d  ", c_queue[i]);
            if(i == rear){
                break;
            }
            i = (i + 1) % max;
        }
    }
}

// function to access the front element 
void peek(){
    if(isEmpty()){
        printf("\nQueue underflow\n");
    }
    else{
        printf("\nPeek = %d\n", c_queue[front]);
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