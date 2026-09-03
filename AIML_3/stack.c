#include<stdio.h>
#define max 10

int stack[max];
int top = -1;

int Isfull(){
    return top == max-1;
}

int Isempty(){
    return top == -1;
}

void push(int n){
    if(Isfull()){
        printf("\nStack is over-flow\n");
    }
    else{
        stack[++top] = n;
        printf("%d is inserted\n", n);
    }
}

int pop(){
    if(Isempty()){
        printf("Stack is under-flow\n");
    }
    else{
        printf("%d is deleted\n", stack[top]);
        return stack[top--];
    }
}

int peek(){
    if(Isempty()){
        printf("stack is under-flow\n");
    }
    else{
        printf("Top = %d\n", stack[top]);
        return stack[top];
    }
}

void Display(){
    if(Isempty()){
        printf("stack is under-flow\n");
    }
    else{
        printf("Stack : ");
        for(int i = 0; i<=top; i++){
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
int main(){
    int option, value;
    while (1)
    {
        printf("\n============STACK OPERATIONS=========\n\n");
        printf("1. push().\n");
        printf("2. pop().\n");
        printf("3. peek().\n");
        printf("4. display().\n");
        printf("5. exit program.\n");
        printf("\nEnter option 1 to 5 :");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Enter value : ");
            scanf("%d", &value);
            push(value);
            break;
        case 2: 
            pop(); 
            break;
        case 3: 
            peek(); 
            break;
        case 4: 
            Display(); 
            break;
        case 5: 
            printf("Program terminated\n");
            exit(1);
        default:
            printf("In-vailed Option");
            break;
        }
    }
    
}