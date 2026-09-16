#include<stdio.h>
#define max 5

int queue[max];
int front = -1;
int rear = -1;

// function to check queue is empty or not
int isEmtpy(){
    return front == -1;
}

// function to check queue is full or not
int isFull(){
    return rear == max-1;
}

// function to insert rear
void enqueue(int value){
    if(isFull()){
        printf("\nQueue overflow\n");
    }
    else{
        if(isEmtpy()){
            front = 0;
        }
        rear++;
        queue[rear] = value;
        printf("\n%d inserted\n", value);
    }
}
// function to delete front
void dequeue(){
    if(isEmtpy()){
        printf("\nQueue underflow\n");
    }
    else{
        int x = queue[front];
        if(front == rear){
            front = rear = -1;
        }
        else{
            front++;
        }
        printf("\n%d deleted\n", x);
    }
}

// function to access front
void peek(){
    if(isEmtpy()){
        printf("\nQueue underflow\n");
    }
    else{
        printf("\nPeek = %d\n", queue[front]);
    }
}

// function to display all elements of queue
void display(){
    if(isEmtpy()){
        printf("\nQueue underflow\n");
    }
    else{
        printf("\n Queue : front -> ");
        for(int i =front; i<= rear; i++ ){
            printf("%d  ", queue[i]);
        }
        printf("-> rear\n");
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
        case 2: dequeue(); break;
        case 3: peek(); break;
        case 4: display(); break;
        case 5: printf("\nProgram terminated successfully\n"); return 0;
        default: printf("\nIn-vailed option.\n"); break;
        }
    }

}
