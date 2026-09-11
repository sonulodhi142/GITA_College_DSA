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

// function to access the front
void peek(){
    if(isEmpty()){
        printf("\nQueue underflow\n");
    }
    else{
        printf("\nPeek = %d\n", queue[front]);
    }
}

// display all elements of Queue
void display(){
    if(isEmpty()){
        printf("\nQueue underflow\n");
    }
    else{
        printf("\nQueue : front -> ");
        for(int i = front; i <= rear; i++){
            printf("%d  ", queue[i]);
        }
        printf("<- rear\n");
    }
}

int main(){
    int option, value;
    
    while(1){
        printf("\n========= Queue Operations ============\n\n");
        printf("1. enqueue.\n");
        printf("2. dequeue.\n");
        printf("3. peek.\n");
        printf("4. display.\n");
        printf("5. exit program.\n");

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
            case 5: printf("\nprogram terminated.\n"); return 0;
            default: printf("\nInvailed option.\n");
        }
    }
}