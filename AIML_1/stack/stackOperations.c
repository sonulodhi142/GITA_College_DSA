#include<stdio.h>
#define max 5

int stack[max];
int top = -1;

// function to check stack is empty or not
int isEmpty(){
    return top == -1;
}

// function to check stack is full or not
int isFull(){
    return top == max-1;
}

// function to insert element onto the stack
void push(int n){
    if(isFull()){
        printf("\nStack overflow\n");
    }
    else{
        top++;
        stack[top] = n;
        printf("\n%d inserted\n", n);
    }
}

// function to delete element front the stack
void pop(){
    if(isEmpty()){
        printf("\nStack underflow\n");
    }
    else{
        int n = stack[top];
        top--;
        printf("\n%d deleted\n", n);
    }
}

// function to access top element from the stack
void peek(){
    if(isEmpty()){
        printf("\nStack underflow\n");
    }
    else{
        printf("\nPeek = %d\n", stack[top]);
    }
}

// function to display all element of stack
void display(){
    if(isEmpty()){
        printf("\nStack underflow\n");
    }
    else{
        printf("\nStack : ");
        for(int i = top; i >= 0; i--){
            printf("%d  ", stack[i]);
        }
        printf("\n");
    }
}


int main(){
    int option, value;
    while(1){
        printf("\n=============== stack operation =================\n\n");
        printf("1. push.\n");
        printf("2. pop.\n");
        printf("3. peek.\n");
        printf("4. display.\n");
        printf("5. exit.\n");
        printf("\nEnter option : ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Enter value to insert : ");
            scanf("%d", &value);
            push(value);
            break;
        case 2: pop(); break;
        case 3: peek(); break;
        case 4: display(); break;
        case 5: printf("\nProgram terminated\n"); return 0;
        default:
            printf("\nInvailed option\n");
            break;
        }
    }
}