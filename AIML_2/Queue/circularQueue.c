#include<stdio.h>
#define max 5

int c_queue[max];
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

// function to insert element 
void enqueue(int n){
    if(isFull()){
        printf("\nQueue is overflow\n");
    }
    else{
        if(isEmpty()){
            front = rear = 0;
        }
        else{
            rear = (rear + 1)%max;
        }
        c_queue[rear] = n;
        printf("\n%d inserted\n", n);
    }
}

// function to delete front
void dequeue(){
    if(isEmpty()){
        printf("\nQueue underflow\n");
    }
    else{
        int x = c_queue[front];
        if(front == rear){
            front = rear = -1;
        }
        else{
            front = (front + 1)%max;
        }
        printf("\n%d deleted\n", x);
    }
}

// function to access peek element
void peek(){
    if(isEmpty()){
        printf("\nQueue is overflow\n");
    }
    else{
        printf("\nPeek = %d\n", c_queue[front]);
    }
}

// function to display all element of queue
void display(){
    if(isEmpty()){
        printf("\nQueue is underflow\n");
    }
    else{
        printf("\nQueue : front -> ");
        int i = front;
        while(1){
            printf("%d  ", c_queue[i]);

            if(i == rear){
                break;
            }
            i = (i+1)%max;
        }
        printf("-> rear\n");
    }
}

int main(){
    enqueue(4);
    enqueue(4);
    enqueue(4);
    enqueue(4);
    enqueue(4);
    display();
}