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
void insertRear(int value){
    if(isFull()){
        printf("\nQueue overflow\n");
    }
    else{
        if(isEmpty()){
            front = 0;
        }
        rear = (rear+1)%max;
        d_queue[rear] = value;
        printf("\n%d inserted at rear\n", value);
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
            front = (front + 1)%max;
        }
        printf("\n%d deleted from front\n", x);
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
            front = (front-1+max)%max;
        }
        d_queue[front] = value;
        printf("\n%d inserted at front", value);
    }
}

//function to delete rear
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
            rear = (rear-1+max)%max;
        }
        printf("\n%d deleted from rear\n", x);
    }
}

// function to access front
void peekFront(){
    if(isEmpty()){
        printf("\nQueue underflow\n");
    }
    else{
        printf("\nPeek Front = %d\n", d_queue[front]);
    }
}
// function to access rear
void peekRear(){
    if(isEmpty()){
        printf("\nQueue underflow\n");
    }
    else{
        printf("\nPeek Rear = %d\n", d_queue[rear]);
    }
}

// function to display all element of queue
void display(){
    if(isEmpty()){
        printf("\nQueue underflow\n");
    }
    else{
        int i = front;
        printf("\nQueue : front ->  ");
        while(1){
            printf("[%d]%d  ",i , d_queue[i]);

            if(i == rear){
                break;
            }
            i = (i+1)%max;
        }
        printf("-> rear\n");
    }
}

int main(){
    int value, option;
    while(1){
        printf("\n=======Double ended Queue operations=======\n\n");
        printf("1. Insert Rear.\n");
        printf("2. Insert Front.\n");
        printf("3. Delete Rear.\n");
        printf("4. Delete Front.\n");
        printf("5. Peek(Rear).\n");
        printf("6. Peek(Front).\n");
        printf("7. Display Queue.\n");
        printf("8. Exit Program.\n");
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
            case 5: peekRear(); break;
            case 6: peekFront(); break;
            case 7: display(); break;
            case 8: printf("\nprogram terminated\n"); return 0;
            default: printf("\nInvailed option\n");
        }
    }
}