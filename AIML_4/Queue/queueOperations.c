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
    return rear == max-1;
}

// function to insert element at rear
void enqueue(int n){
    if(isFull()){
        printf("\nQueue overflow\n");
    }
    else{
        if(isEmpty()){
            front = rear = 0;
        }
        else{
            rear++;
        }
        queue[rear] = n;
        printf("\n%d inserted\n", n);
    }
}



int main(){
    enqueue(6);
    enqueue(6);
    enqueue(6);
    enqueue(6);
    enqueue(6);
    enqueue(6);
}