#include<stdio.h>
#define max 5

int queue[max];
int front = -1;
int rear = -1;

// function to check queue is empty or not
int isEmpty(){
    return front == -1;
}

// function to check queue is full or not
int isFull(){
    return rear == max - 1;
}

// function to insert value at rear
void enqueue(int value){
    if(isFull()){
        printf("\nQueue overflow\n");
    }
    else{
        if(isEmpty()){
            front = 0;
        }
        rear++;
        queue[rear] = value;
        printf("\n%d inserted\n", value);
    }
}


// function to delete front
void dequeue(){
    if(isEmpty()){
        printf("\nQueue underflow\n");
    }
    int x = queue[front];
    front++;
    if(front > rear){
        front = rear = -1;
    }
    printf("\n%d deleted\n", x);

}

int main(){
    enqueue(1);
    dequeue();
    enqueue(1);
    enqueue(1);
    enqueue(1);
    enqueue(1);
    enqueue(1);
    enqueue(1);
}